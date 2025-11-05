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
    P(C_CYAN); P("══════════════════════════════════════════════════════════════════\n"); P(C_RESET);
    P("  "); P(title); P("\n");
    if (subtitle) { P(C_DIM); P("  "); P(subtitle); P(C_RESET); P("\n"); }
    P(C_CYAN); P("══════════════════════════════════════════════════════════════════"); P(C_RESET);
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

/* Affiche en toute sécurité les 'n' premiers octets comme une chaîne:
   - on force un '\0' à la position n (temporairement) pour éviter les dépassements */
static void print_n_bytes_as_str(const char *label, char *buf, size_t n)
{
    char saved = buf[n];
    ((char*)buf)[n] = '\0';
    P(label);
    P(buf);
    P("\n");
    ((char*)buf)[n] = saved;
}

/* === Test 1 : Reallocation dans une heap de type différent (malloc(160) -> realloc(43)) === */
int main(void)
{
    char *ptr1 = 0;
    char *ptr_test = 0;

    /* 160 octets utiles (sans garantie de '\0' si on copie pile 160),
       on préfère copier 159 et poser un terminateur pour l'affichage. */
    const char *str160 =
        "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
        "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
        "0123456789abcdef0123456789abcde";

    banner("TEST 1 — Reallocation dans une heap de type différent",
           "Scenario: malloc(160) → memcpy(data) → realloc(43) + vérif du contenu");

    /* Étape 1 : allocation initiale */
    step("Étape 1: malloc(160)");
    ptr1 = (char*)malloc(160);
    show_alloc_mem_ex();

    /* Étape 2 : écrire des données lisibles, et afficher sans déborder */
    step("Étape 2: ft_memcpy(ptr1, str160, 159); ptr1[159] = '\\0'  (pour affichage sûr)");
    ft_memcpy(ptr1, str160, 159);
    ptr1[159] = '\0'; /* sécurité pour impression */
    print_n_bytes_as_str("ptr1     = ", ptr1, 159);

    /* Étape 3 : réallocation (potentiellement vers un autre groupe) */
    step("Étape 3: realloc(ptr1, 43)");
    ptr_test = (char*)realloc(ptr1, 43);

    /* Pour l’affichage, on borne à 42 caractères + '\0' */
    if (ptr_test) {
        if (43 > 0) ptr_test[42] = '\0';
        print_n_bytes_as_str("ptr_test = ", ptr_test, 42);
    } else {
        P("ptr_test = (null)\n");
    }

    show_alloc_mem_ex();

    /* Étape 4 : récap adresses / déplacement */
    recap(ptr1, ptr_test);

    /* Étape 5 : nettoyage */
    step("Étape 5: free(ptr_test)");
    free(ptr_test);
    show_alloc_mem_ex();

    return 0;
}
