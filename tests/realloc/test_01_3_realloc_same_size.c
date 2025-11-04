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
    if (subtitle)
    {
        P(C_DIM); P("  "); P(subtitle); P(C_RESET); P("\n");
    }
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
    {
        P(C_MAGENTA); P("  ➜ realloc a échoué (NULL)\n"); P(C_RESET);
    }
    else if (new_ptr == old_ptr)
    {
        P(C_MAGENTA); P("  ➜ Réalloc SANS déplacement (même adresse)\n"); P(C_RESET);
    }
    else
    {
        P(C_MAGENTA); P("  ➜ Réalloc AVEC déplacement (nouvelle adresse)\n"); P(C_RESET);
    }

    P("\n");
}

/* Affiche les 'n' premiers octets sous forme de chaîne avec borne + '\0' */
static void print_n_bytes_as_str(const char *label, char *buf, size_t n)
{
    char saved = buf[n];
    ((char*)buf)[n] = '\0';
    P(label);
    P(buf);
    P("\n");
    ((char*)buf)[n] = saved;
}

/* === Test 1.3 : realloc de même taille (1500 → 1500) === */
int main(void)
{
    char *ptr1 = 0;
    char *ptr_test = 0;

    const char *str160 =
        "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
        "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
        "0123456789abcdef0123456789abcde";

    banner("TEST 1.3 — Reallocation avec une taille identique",
           "Scenario: malloc(1500) → realloc(1500) (aucun déplacement attendu)");

    /* Étape 1 : allocation */
    step("Étape 1: malloc(1500)");
    ptr1 = (char*)malloc(1500);
    show_alloc_mem_ex();

    /* Étape 2 : copier du contenu test et afficher un extrait */
    step("Étape 2: ft_memcpy(ptr1, str160, 159); ptr1[159] = '\\0'");
    ft_memcpy(ptr1, str160, 159);
    ptr1[159] = '\0';
    print_n_bytes_as_str("ptr1     = ", ptr1, 159);

    /* Étape 3 : réallocation de même taille */
    step("Étape 3: realloc(ptr1, 1500)");
    ptr_test = (char*)realloc(ptr1, 1500);

    if (ptr_test)
    {
        ptr_test[159] = '\0';
        print_n_bytes_as_str("ptr_test = ", ptr_test, 159);
    }
    else
        P("ptr_test = (null)\n");

    show_alloc_mem_ex();

    /* Étape 4 : comparaison des adresses */
    recap(ptr1, ptr_test);

    /* Étape 5 : libération */
    step("Étape 5: free(ptr_test)");
    free(ptr_test);
    show_alloc_mem_ex();

    return 0;
}
