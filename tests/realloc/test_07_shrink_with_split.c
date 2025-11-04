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
        { P(C_MAGENTA); P("  ➜ Réalloc SANS déplacement (réduction in-place)\n"); P(C_RESET); }
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

/* === Test 7 : Réduction avec split possible (112 -> 16) ===
   Objectif : vérifier que la réduction conserve le contenu et permet un split
   (si ta politique de split autorise de créer un bloc libre suffisamment grand). */
int main(void)
{
    char *ptr1 = 0;
    char *ptr_test = 0;

    banner("TEST 7 — Réallocation plus petite avec split",
           "Scenario: malloc(112) → memcpy(31) → realloc(16) + vérif du contenu, split attendu");

    /* Étape 1 : allocation */
    step("Étape 1: malloc(112)");
    ptr1 = (char*)malloc(112);
    show_alloc_mem_ex();

    /* Étape 2 : copie d’un contenu lisible (31 octets) + affichage borné */
    step("Étape 2: ft_memcpy(ptr1, \"0123456789abcdefA123456789abcde\", 31)");
    ft_memcpy(ptr1, "0123456789abcdefA123456789abcde", 31);
    print_n_bytes_as_str("ptr1     = ", ptr1, 31);

    /* Étape 3 : réduction à 16 (split possible si reste >= taille_min_bloc) */
    step("Étape 3: realloc(ptr1, 16)");
    ptr_test = (char*)realloc(ptr1, 16);

    if (ptr_test) {
        /* Contenu conservé = min(31,16)=16 → affichons 15 chars pour prudence */
        print_n_bytes_as_str("ptr_test = ", ptr_test, 15);
    } else {
        P("ptr_test = (null)\n");
    }

    show_alloc_mem_ex();

    /* Étape 4 : recap adresses / mouvement */
    recap(ptr1, ptr_test);

    /* Étape 5 : libération */
    step("Étape 5: free(ptr_test)");
    free(ptr_test);
    show_alloc_mem_ex();

    return 0;
}
