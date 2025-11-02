#include "../inc/malloc.h"

int main()
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    char *ptr3 = NULL;
    char *ptr4 = NULL;
    char *ptr5 = NULL;
    char *ptr_test = NULL;
    
    
    ft_putstr_fd("\n========================================================\n", 1);
    ft_putstr_fd("Test 1 : Reallocation dans une heap de type différent\n", 1);
    ft_putstr_fd("========================================================\n", 1);

    ptr1 = malloc(150);
    show_alloc_mem_ex();

    ptr_test = realloc(ptr1, 43);
    show_alloc_mem_ex();

    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();

    ft_putstr_fd("\n========================================================\n", 1);
    ft_putstr_fd("Test 1.1 : Reallocation dans une heap de type différent\n", 1);
    ft_putstr_fd("========================================================\n", 1);

    ptr1 = malloc(150);
    show_alloc_mem_ex();

    ptr_test = realloc(ptr1, 1900);
    show_alloc_mem_ex();

    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();



    ft_putstr_fd("\n========================================================\n", 1);
    ft_putstr_fd("Test 1.2 : Reallocation dans une heap de type différent\n", 1);
    ft_putstr_fd("========================================================\n", 1);

    ptr1 = malloc(15);
    show_alloc_mem_ex();

    ptr_test = realloc(ptr1, 190);
    show_alloc_mem_ex();

    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();

    ft_putstr_fd("\n========================================================\n", 1);
    ft_putstr_fd("Test 1.2 : Reallocation dans une heap de type différent\n", 1);
    ft_putstr_fd("========================================================\n", 1);

    ptr1 = malloc(1500);
    show_alloc_mem_ex();

    ptr_test = realloc(ptr1, 19);
    show_alloc_mem_ex();

    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();

    ft_putstr_fd("\n================================================================\n", 1);
    ft_putstr_fd("Test 1.3 : Reallocation avec un block exactement de la même taille\n", 1);
    ft_putstr_fd("==================================================================\n", 1);

    ptr1 = malloc(1500);
    show_alloc_mem_ex();

    ptr_test = realloc(ptr1, 1500);
    show_alloc_mem_ex();

    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();

    
    ft_putstr_fd("\n====================================================================\n", 1);
    ft_putstr_fd("Test 2 : Reallocation dernier block de la heap avec heap assez grande \n", 1);
    ft_putstr_fd("====================================================================\n", 1);

    ptr1 = malloc(150);
    show_alloc_mem_ex();
    ptr_test = realloc(ptr1, 189);
    show_alloc_mem_ex();


    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr1);
    free(ptr_test);

    show_alloc_mem_ex();


    ft_putstr_fd("\n======================================================================\n", 1);
    ft_putstr_fd("Test 2.1 : Reallocation dernier block de la heap avec heap assez grande \n", 1);
    ft_putstr_fd("======================================================================\n", 1);

    ptr1 = malloc(1);
    ptr2 = malloc(1);
    ptr3 = malloc(1);
    ptr4 = malloc(1);
    show_alloc_mem_ex();
    ptr_test = realloc(ptr4, 18);
    show_alloc_mem_ex();


    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr4,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr_test);

    show_alloc_mem_ex();


    
    ft_putstr_fd("\n=======================================================================\n", 1);
    ft_putstr_fd("Test 3 : Reallocation dernier block de la heap avec heap pas assez grande\n", 1);
    ft_putstr_fd("========================================================================\n", 1);

    void **ptr[170];
    int i;

    for (i = 0; i < 170; i++)
    {
        ptr[i] = malloc(64);
        if (ptr[i] == NULL)
        {
            return 1;
        }
    }
    
    ptr_test = realloc(ptr[169], 128);


    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr[169],1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);



    for (i = 0; i < 169; i++)
    {
        free(ptr[i]);
    }


    show_alloc_mem_ex();

    free(ptr_test);


    show_alloc_mem_ex();

    /*
    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);


    ft_putstr_fd("\n=================================================================================\n", 1);
    ft_putstr_fd("Test 4 : Reallocation pour un block plus grand avec block suivant free mais pas assez grand\n", 1);
    ft_putstr_fd("====================================================================================\n", 1);

    ptr1 = malloc(16);
    ptr2 = malloc(16);
    ptr3 = malloc(64);
    free(ptr2);
    show_alloc_mem_ex();
    ptr_test = realloc(ptr1, 128);
    show_alloc_mem_ex();


    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr1);
    free(ptr3);
    free(ptr_test);


    ft_putstr_fd("\n===================================================================================\n", 1);
    ft_putstr_fd("Test 5 : Reallocation pour un block plus grand avec block suivant free assez grand\n", 1);
    ft_putstr_fd("(SEGFAULT DANS LE REALLOC !!!! DANS LE MERGE_PREVIOUS !!!)\n", 1);
    ft_putstr_fd("===================================================================================\n", 1);

    ptr1 = malloc(16);
    ptr2 = malloc(128);
    ptr3 = malloc(64);

    show_alloc_mem_ex();

    free(ptr2);

    show_alloc_mem_ex();

    ptr_test = realloc(ptr1, 32);

    show_alloc_mem_ex();

    // display_t_block((t_block *) BLOCK_UNSHIFT(ptr3));

    free(ptr3);

    show_alloc_mem_ex();

    free(ptr_test);

    show_alloc_mem_ex();

    ft_putstr_fd("(!!!)\n", 1);

    free(ptr1);

    show_alloc_mem_ex();


    ft_putstr_fd("\n==========================================================================\n", 1);
    ft_putstr_fd("Test 6 : Reallocation pour un block plus petit avec impossibilité de split\n", 1);
    ft_putstr_fd("==========================================================================\n", 1);

    ptr1 = malloc(32);
    show_alloc_mem_ex();
    ptr_test = realloc(ptr1, 16);
    show_alloc_mem_ex();


    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();


    ft_putstr_fd("\n=========================================================\n", 1);
    ft_putstr_fd("Test 7 : Reallocation pour un block plus petit avec split\n", 1);
    ft_putstr_fd("==========================================================\n", 1);

    ptr1 = malloc(96);
    show_alloc_mem_ex();
    ptr_test = realloc(ptr1, 16);
    show_alloc_mem_ex();


    ft_putstr_fd("\n",1);
    ft_putstr_fd(" Ancien ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1,1);
    ft_putstr_fd("\nNouveau ptr = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr_test,1);
    ft_putstr_fd("\n",1);

    free(ptr_test);

    show_alloc_mem_ex();

    */

    return 0;
}