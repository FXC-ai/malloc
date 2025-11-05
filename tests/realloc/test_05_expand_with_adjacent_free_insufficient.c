#include "../../includes/malloc.h"

/* Couleurs ANSI (pas de rouge/vert) */
#define C_RESET   "\033[0m"
#define C_CYAN    "\033[36m"
#define C_MAGENTA "\033[35m"
#define C_DIM     "\033[2m"

#define P(s)    ft_putstr_fd((char*)(s), 1)
#define PHEX(x) ft_putnb_hex_fd((uintptr_t)(x), 1)

/* --- Helpers d'affichage --- */
static void banner(const char *title, const char *subtitle)
{
    P("\n");
    P(C_CYAN);
    P("══════════════════════════════════════════════════════════════════\n");
    P(C_RESET);
    P("  "); P(title); P("\n");
    if (subtitle) { P(C_DIM); P("  "); P(subtitle); P(C_RESET); P("\n"); }
    P(C_CYAN);
    P("══════════════════════════════════════════════════════════════════");
    P(C_RESET);
    P("\n\n");
}

static void step(const char *label)
{
    P(C_DIM); P(label); P(C_RESET); P("\n");
}

static void recap(void *old_ptr, void *new_ptr)
{
    P("\n");
    P(" Ancien ptr = "); PHEX(old_ptr);
    P("\nNouveau ptr = "); PHEX(new_ptr); P("\n");

    if (new_ptr == 0)
        { P(C_MAGENTA); P("  ➜ realloc a échoué (NULL)\n"); P(C_RESET); }
    else if (new_ptr == old_ptr)
        { P(C_MAGENTA); P("  ➜ Réalloc SANS déplacement (extension in-place)\n"); P(C_RESET); }
    else
        { P(C_MAGENTA); P("  ➜ Réalloc AVEC déplacement (copie vers un autre emplacement)\n"); P(C_RESET); }

    P("\n");
}

/* Affiche proprement les 'n' premiers octets (borne + '\0' temporaire) */
static void print_n_bytes_as_str(const char *label, char *buf, size_t n)
{
    char saved = buf[n];
    ((char*)buf)[n] = '\0';
    P(label);
    P(buf);
    P("\n");
    ((char*)buf)[n] = saved;
}

/* === Test 5 : Agrandissement avec bloc suivant libre insuffisant (16 -> 128) ===
   Setup : ptr1=16, ptr2=16, ptr3=128 puis free(ptr2).
   Le bloc suivant libre (16) est trop petit pour étendre ptr1 à 128 → déplacement attendu. */
int main(void)
{
    char *ptr1 = 0, *ptr2 = 0, *ptr3 = 0;
    char *ptr_test = 0;
    void *old_ptr1 = 0;

    banner("TEST 5 — Agrandissement avec bloc suivant insuffisant",
           "Scenario: malloc(16), malloc(16), malloc(128) → free(ptr2) → realloc(ptr1, 128)");

    /* Étape 1 : allocations */
    step("Étape 1: malloc(16) → ptr1, malloc(16) → ptr2, malloc(128) → ptr3");
    ptr1 = (char*)malloc(16);
    ptr2 = (char*)malloc(16);
    ptr3 = (char*)malloc(128);
    show_alloc_mem_ex();

    /* Étape 2 : libérer le bloc adjacent (ptr2) — insuffisant pour atteindre 128 */
    step("Étape 2: free(ptr2)  (bloc adjacent libre mais trop petit)");
    free(ptr2);
    show_alloc_mem_ex();

    /* Étape 3 : écrire 15 octets dans ptr1 et afficher un extrait sûr */
    step("Étape 3: ft_memcpy(ptr1, \"0123456789abcde\", 15); (affichage borné à 15)");
    ft_memcpy(ptr1, "0123456789abcde", 15);
    print_n_bytes_as_str("ptr1     = ", ptr1, 15);

    /* Étape 4 : réallocation de ptr1 vers 128 — déplacement probable */
    step("Étape 4: realloc(ptr1, 128)");
    old_ptr1 = ptr1;
    ptr_test = (char*)realloc(ptr1, 128);

    if (ptr_test) {
        /* Contenu conservé = min(15,128)=15. Affichons 15 premiers chars. */
        print_n_bytes_as_str("ptr_test = ", ptr_test, 15);
    } else {
        P("ptr_test = (null)\n");
    }

    show_alloc_mem_ex();

    /* Étape 5 : récap adresses / mouvement */
    recap(old_ptr1, ptr_test);

    /* Étape 6 : libérations
       - On libère ptr3
       - On libère UNIQUEMENT le pointeur retourné par realloc (ptr_test) */
    step("Étape 6: free(ptr3), free(ptr_test)");
    free(ptr3);
    free(ptr_test);
    show_alloc_mem_ex();

    return 0;
}
