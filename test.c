#include "inc/malloc.h"
#include <stdio.h>

void faux_free (void *ptr)
{
    t_block *block = (t_block *) BLOCK_UNSHIFT(ptr);

    // write(1, "AA\n", 3);

    block->is_free = TRUE;
    // display_t_block(block);

}


int main()
{
    /* ───────────────────────────
       SCÉNARIO 2 — Beaucoup de pointeurs, trous alternés
       ─────────────────────────── */
    void *ptr4  = malloc(64);
    void *ptr5  = malloc(128);
    void *ptr6  = malloc(64);
    void *ptr7  = malloc(128);
    void *ptr8  = malloc(64);
    void *ptr9  = malloc(128);
    void *ptr10 = malloc(64);
    void *ptr11 = malloc(128);
    void *ptr12 = malloc(64);
    void *ptr13 = malloc(128);
    void *ptr14 = malloc(64);
    void *ptr15 = malloc(128);

    show_alloc_mem();

    // Crée des trous sur un motif pair/impair
    faux_free(ptr5);
    faux_free(ptr7);
    faux_free(ptr9);
    faux_free(ptr11);
    faux_free(ptr13);
    faux_free(ptr15);

    // Petites allocations censées rentrer dans les trous existants
    void *ptr16 = malloc(32);
    void *ptr17 = malloc(48);
    void *ptr18 = malloc(80);
    void *ptr19 = malloc(96);
    void *ptr20 = malloc(24);
    void *ptr21 = malloc(112);

    write(1, "\n",1);
    show_alloc_mem();

    return 0;
}