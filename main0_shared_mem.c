#include "libft/libft.h"
#include <stdio.h>
#include <sys/mman.h>

int main()
{
	size_t len = 4096;

	char *shared_mem = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (shared_mem == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	const char *message = "Bonjour du processus 0";
	strcpy(shared_mem, message);
	printf("processus 0 a ecrit à la l'adresse %p : %s\n", shared_mem, shared_mem);

	char * cpy_ptr = shared_mem;



	printf("processus 0 a ecrit à la l'adresse %p : %s\n", cpy_ptr, cpy_ptr);

	// while (1)
	// {}

	return 0;
}