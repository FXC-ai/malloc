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
        { P(C_MAGENTA); P("  ➜ Réalloc SANS déplacement (même adresse)\n"); P(C_RESET); }
    else
        { P(C_MAGENTA); P("  ➜ Réalloc AVEC déplacement (nouvelle adresse)\n"); P(C_RESET); }

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

/* === Test 3 : Realloc du dernier block avec heap PAS assez grande (64 -> 128) ===
   Setup : 170 blocs de 64 octets. On réalloque le DERNIER (ptr[169]) vers 128. */
int main(void)
{
    char *ptr[170] = {0};
    char *ptr_test = 0;
    void *old_last = 0;
    int i;

    const char *str64 =
        "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    banner("TEST 3 — Realloc du dernier block (heap pas assez grande)",
           "Scenario: 170 x malloc(64) → memcpy sur ptr[169] → realloc(ptr[169], 128)");

    /* Étape 1 : allocations */
    step("Étape 1: malloc(64) x170");
    for (i = 0; i < 170; ++i)
    {
        ptr[i] = (char*)malloc(64);
        if (!ptr[i]) { P("Allocation échouée\n"); return 1; }
    }
    /* (Optionnel) Affichage global si utile */
    // show_alloc_mem_ex();

    /* Étape 2 : écrire 64 octets lisibles dans le dernier bloc, afficher 63 */
    step("Étape 2: ft_memcpy(ptr[169], str64, 64); (affichage borné à 63)");
    ft_memcpy(ptr[169], str64, 64);
    print_n_bytes_as_str("ptr[169] = ", ptr[169], 63);

    /* Étape 3 : réallocation du dernier block vers 128 */
    step("Étape 3: realloc(ptr[169], 128)");
    old_last = ptr[169];
    ptr_test = (char*)realloc(ptr[169], 128);

    if (ptr_test) {
        /* Le contenu conservé = min(64,128)=64 octets.
           On affiche 63 premiers caractères pour rester prudent. */
        print_n_bytes_as_str("ptr_test = ", ptr_test, 63);
    } else {
        P("ptr_test = (null)\n");
    }

    /* Récap adresses / déplacement */
    recap(old_last, ptr_test);

    /* Étape 4 : libération de tous les blocs SAUF old_last (devenu invalide si success)
       - Si realloc a réussi: on libère ptr_test + tous les autres (0..168).
       - Si realloc a échoué: old_last est toujours valide → on libère old_last aussi. */
    step("Étape 4: free de tous les blocs");
    for (i = 0; i < 169; ++i) {
        free(ptr[i]);
    }
    if (ptr_test) {
        free(ptr_test);
    } else {
        /* realloc a échoué → l’ancien pointeur reste valide */
        free((void*)old_last);
    }

    /* État final (optionnel) */
    show_alloc_mem_ex();

    return 0;
}
