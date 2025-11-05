#include "../../includes/malloc.h"

/* Couleurs ANSI (pas de rouge/vert) */
#define C_RESET   "\033[0m"
#define C_CYAN    "\033[36m"
#define C_MAGENTA "\033[35m"
#define C_DIM     "\033[2m"

#define P(s)    ft_putstr_fd((char*)(s), 1)
#define PHEX(x) ft_putnb_hex_fd((uintptr_t)(x), 1)

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_cpy;
	char	*src_cpy;

	if (!dst && !src)
		return (NULL);
	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}

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

/* === Test 2.1 : Realloc du dernier block avec heap assez grande (16 -> 18) ===
   Setup : 4 blocs successifs (16,16,16,16). On réalloque le DERNIER (ptr4) à 18. */
int main(void)
{
    char *ptr1 = 0, *ptr2 = 0, *ptr3 = 0, *ptr4 = 0;
    char *ptr_test = 0;

    banner("TEST 2.1 — Realloc du dernier block (heap assez grande)",
           "Scenario: malloc(16)x4 → memcpy sur ptr4 → realloc(ptr4, 18) + vérif");

    /* Étape 1 : allocations */
    step("Étape 1: malloc(16) x4 (ptr1..ptr4)");
    ptr1 = (char*)malloc(16);
    ptr2 = (char*)malloc(16);
    ptr3 = (char*)malloc(16);
    ptr4 = (char*)malloc(16);
    show_alloc_mem_ex();

    /* Étape 2 : écrire 16 octets lisibles dans ptr4, afficher 15 pour rester borné */
    step("Étape 2: ft_memcpy(ptr4, \"0123456789abcdef\", 16); (affichage borné à 15)");
    ft_memcpy(ptr4, "0123456789abcdef", 16);
    /* On affiche les 15 premiers caractères (index 0..14) pour éviter toute lecture hors-borne */
    print_n_bytes_as_str("ptr4     = ", ptr4, 15);

    /* Étape 3 : réallocation du dernier block vers 18 */
    step("Étape 3: realloc(ptr4, 18)");
    ptr_test = (char*)realloc(ptr4, 18);

    if (ptr_test) {
        /* Le contenu conservé = min(16,18)=16 octets.
           On affiche 15 premiers caractères pour rester prudent. */
        print_n_bytes_as_str("ptr_test = ", ptr_test, 15);
    } else {
        P("ptr_test = (null)\n");
    }

    show_alloc_mem_ex();

    /* Étape 4 : récap adresses / déplacement */
    recap(ptr4, ptr_test);

    /* Étape 5 : libération — ptr1/ptr2/ptr3 + le pointeur RENVOYÉ par realloc */
    step("Étape 5: free(ptr1), free(ptr2), free(ptr3), free(ptr_test)");
    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr_test);
    show_alloc_mem_ex();

    return 0;
}
