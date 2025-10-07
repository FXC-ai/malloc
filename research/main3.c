#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Ce script met en évidence l'utilisation de mémoire partagée entre deux processus
// Tout d'abord il déclare 2 pointeurs : anon et zero
// anon est anonyme c'est à dire non lié à un fichier ???
// zero est un pointeur vers une mémoire partagée liée à un fichier
// 
// Ensuite il copie une chaine de caractéres à partir de anon et zero
// 
// Le processus est dupliqué et pendant que le processus enfant attend, les chaines de caracteres sont modifiées par le processus parent
// C'est pourquoi le processus enfant affiche 2 messages différents lorsqu'il print les
// anon et zero

int main(void)
{
        const char str1[] = "Je suis le premier string";
        const char str2[] = "ET MOI LE DEUXIEME !";
        int parpid = getpid(), childpid;
        int fd = -1;
        char *anon, *zero;

        int foo = 14;

        if ((fd = open("/dev/zero", O_RDWR, 0)) == -1)
                err(1, "open");

        anon = (char*)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
        zero = (char*)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_FILE|MAP_SHARED, fd, 0);

        if (anon == MAP_FAILED || zero == MAP_FAILED)
                errx(1, "either mmap");

        strcpy(anon, str1);
        strcpy(zero, str1);

        printf("PID %d:\tanonymous %s, zero-backed %s\n", parpid, anon, zero);
        switch ((childpid = fork()))
        {
        case -1:
                err(1, "fork");
                /* NOTREACHED */

        case 0:
                
                printf("PID enfant %d:\tanonymous %s, zero-backed %s\n", getpid(), anon, zero);
                printf("foo = %d\n", foo);
                sleep(3);

                printf("PID enfant %d:\tanonymous %s, zero-backed %s\n", getpid(), anon, zero);
                munmap(anon, 4096);
                munmap(zero, 4096);
                close(fd);
                return (EXIT_SUCCESS);
        }

        sleep(2);
        strcpy(anon, str2);
        strcpy(zero, str2);

        printf("Blocage PID %d:\tanonymous %s, zero-backed %s\n", parpid, anon, zero);
        munmap(anon, 4096);
        munmap(zero, 4096);
        close(fd);
        return (EXIT_SUCCESS);
}