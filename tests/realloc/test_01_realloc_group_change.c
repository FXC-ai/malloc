#include "../../inc/malloc.h"

/* Couleurs ANSI (pas de rouge ni vert) */
#define C_RESET   "\033[0m"
#define C_CYAN    "\033[36m"
#define C_MAGENTA "\033[35m"
#define C_DIM     "\033[2m"

/* Raccourcis d'affichage (exclusivement ft_putstr_fd / ft_putnb_hex_fd) */
#define P(s)        ft_putstr_fd((char*)(s), 1)
#define PHEX(x)     ft_putnb_hex_fd((uintptr_t)(x), 1)

/* Petit séparateur + titre */
static void banner(const char *title, const char *subtitle)
{
    P("\n");
    P(C_CYAN); P("════════════════════════════════════════════════════════\n"); P(C_RESET);
    P("  "); P(title); P("\n");
    if (subtitle) { P(C_DIM); P("  "); P(subtitle); P(C_RESET); P("\n"); }
    P(C_CYAN); P("════════════════════════════════════════════════════════"); P(C_RESET);
    P("\n\n");
}

/* Ligne d’étape */
static void step(const char *label)
{
    P(C_DIM); P(label); P(C_RESET); P("\n");
}

/* Mini récap: adresse avant/après + si déplacement */
static void recap(void *old_ptr, void *new_ptr)
{
    P("\n");
    P(" Ancien ptr = "); PHEX(old_ptr);
    P("\nNouveau ptr = "); PHEX(new_ptr); P("\n");

    if (new_ptr == 0)
        { P(C_MAGENTA); P("  ➜ realloc a échoué (NULL)\n"); P(C_RESET); }
    else if (new_ptr == old_ptr)
        { P(C_MAGENTA); P("  ➜ Réalloc SANS déplacement (même adresse)\n"); P(C_RESET); }
    else
        { P(C_MAGENTA); P("  ➜ Réalloc AVEC déplacement (nouvelle adresse)\n"); P(C_RESET); }

    P("\n");
}

int main(void)
{
    char *ptr1 = 0;
    char *ptr_after = 0;

    banner("TEST 1 — Reallocation dans une heap de type différent",
           "malloc(150)  → realloc(43)");

    /* Étape 1 : allocation initiale */
    step("Étape 1: malloc(150)");
    ptr1 = malloc(150);
    show_alloc_mem_ex();

    /* Étape 2 : réallocation potentiellement vers un autre groupe */
    step("Étape 2: realloc(ptr1, 43)");
    ptr_after = realloc(ptr1, 43);
    show_alloc_mem_ex();

    /* Récap clair des adresses et du déplacement */
    recap(ptr1, ptr_after);

    /* Nettoyage: on libère toujours le pointeur renvoyé par realloc */
    step("Étape 3: free(ptr_after)");
    free(ptr_after);
    show_alloc_mem_ex();

    return 0;
}
