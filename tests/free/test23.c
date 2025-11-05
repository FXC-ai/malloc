#include "../../includes/malloc.h"

/* Couleurs ANSI (pas de rouge ni vert) */
#define C_RESET   "\033[0m"
#define C_CYAN    "\033[36m"
#define C_YELLOW  "\033[33m"
#define C_MAGENTA "\033[35m"
#define C_DIM     "\033[2m"

/* Helpers d'affichage basés uniquement sur ft_putstr_fd */
#define P(s) ft_putstr_fd((char*)(s), 1)

#define SECTION(title, color) do {                                  \
    P("\n");                                                        \
    P(color);                                                       \
    P("══════════════════════════════════════════════\n");          \
    P("  "); P(title); P("\n");                                     \
    P("══════════════════════════════════════════════");            \
    P(C_RESET);                                                     \
    P("\n\n");                                                      \
} while (0)

#define SNAP(step) do {                                             \
    P(C_DIM); P(step); P(C_RESET); P("\n");                         \
    show_alloc_mem_ex();                                            \
    P("\n");                                                        \
} while (0)

int main(void)
{
    /* ===================== TEST 1 ===================== */
    SECTION("TEST 1 — 4 x 128, libérations: 4,2,1,3", C_CYAN);

    void *ptr1 = malloc(128);
    void *ptr2 = malloc(128);
    void *ptr3 = malloc(128);
    void *ptr4 = malloc(128);

    SNAP("État initial après 4 malloc(128)");
    free(ptr4); SNAP("Après free(ptr4)");
    free(ptr2); SNAP("Après free(ptr2)");
    free(ptr1); SNAP("Après free(ptr1)");
    free(ptr3); SNAP("Après free(ptr3) — fin TEST 1");

    /* ===================== TEST 2 ===================== */
    SECTION("TEST 2 — 4 x 128, libérations: 4,3,2,1", C_YELLOW);

    ptr1 = malloc(128);
    ptr2 = malloc(128);
    ptr3 = malloc(128);
    ptr4 = malloc(128);

    SNAP("État initial après 4 malloc(128)");
    free(ptr4); SNAP("Après free(ptr4)");
    free(ptr3); SNAP("Après free(ptr3)");
    free(ptr2); SNAP("Après free(ptr2)");
    free(ptr1); SNAP("Après free(ptr1) — fin TEST 2");

    /* ===================== TEST 3 ===================== */
    SECTION("TEST 3 — 4 x 128, libérations: 4,3,1,2", C_MAGENTA);

    ptr1 = malloc(128);
    ptr2 = malloc(128);
    ptr3 = malloc(128);
    ptr4 = malloc(128);

    SNAP("État initial après 4 malloc(128)");
    free(ptr4); SNAP("Après free(ptr4)");
    free(ptr3); SNAP("Après free(ptr3)");
    free(ptr1); SNAP("Après free(ptr1)");
    free(ptr2); SNAP("Après free(ptr2) — fin TEST 3");

    /* ===================== TEST 4 ===================== */
    SECTION("TEST 4 — 4 x 1024, libérations: 3,2,1,4", C_CYAN);

    ptr1 = malloc(1024);
    ptr2 = malloc(1024);
    ptr3 = malloc(1024);
    ptr4 = malloc(1024);

    SNAP("État initial après 4 malloc(1024)");
    free(ptr3); SNAP("Après free(ptr3)");
    free(ptr2); SNAP("Après free(ptr2)");
    free(ptr1); SNAP("Après free(ptr1)");
    free(ptr4); SNAP("Après free(ptr4) — fin TEST 4");

    /* ===================== TEST 5 ===================== */
    SECTION("TEST 5 — 12 x 128, libérations paires puis impaires", C_YELLOW);

    ptr1  = malloc(128);
    void *ptr5  = NULL, *ptr6 = NULL, *ptr7 = NULL, *ptr8 = NULL;
    void *ptr9  = NULL, *ptr10 = NULL, *ptr11 = NULL, *ptr12 = NULL;

    ptr2  = malloc(128);
    ptr3  = malloc(128);
    ptr4  = malloc(128);
    ptr5  = malloc(128);
    ptr6  = malloc(128);
    ptr7  = malloc(128);
    ptr8  = malloc(128);
    ptr9  = malloc(128);
    ptr10 = malloc(128);
    ptr11 = malloc(128);
    ptr12 = malloc(128);

    SNAP("État initial après 12 malloc(128)");

    free(ptr2);  SNAP("Après free(ptr2)");
    free(ptr4);  SNAP("Après free(ptr4)");
    free(ptr6);  SNAP("Après free(ptr6)");
    free(ptr8);  SNAP("Après free(ptr8)");
    free(ptr10); SNAP("Après free(ptr10)");
    free(ptr12); SNAP("Après free(ptr12)");

    /* Ton code initial faisait un double free(ptr12).
       Décommente si tu veux tester la détection du double free côté allocateur.
       // free(ptr12); SNAP("Après double free(ptr12)");
    */

    free(ptr1);  SNAP("Après free(ptr1)");
    free(ptr3);  SNAP("Après free(ptr3)");
    free(ptr5);  SNAP("Après free(ptr5)");
    free(ptr7);  SNAP("Après free(ptr7)");
    free(ptr9);  SNAP("Après free(ptr9)");
    free(ptr11); SNAP("Après free(ptr11) — fin TEST 5");

    return 0;
}
