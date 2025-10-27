#include "inc/malloc.h"
#include <stdio.h>


void test0()
{
    void *ptr0  = malloc(1);
    void *ptr1  = malloc(100);
    void *ptr2  = malloc(156);

    show_alloc_mem();
}

void test1()
{
    void *ptr4  = malloc(64);
    void *ptr5  = malloc(100);
    void *ptr6  = malloc(64);

    show_alloc_mem();
    write(1, "\n", 1);

    set_block_is_free(BLOCK_UNSHIFT(ptr5), TRUE);

    void *ptr16 = malloc(128);

    show_alloc_mem();
    write(1, "\n", 1);
}

void test2()
{
    void *ptr4  = malloc(64);
    void *ptr5  = malloc(128);
    void *ptr6  = malloc(64);

    show_alloc_mem();
    write(1, "\n", 1);

    set_block_is_free( BLOCK_UNSHIFT(ptr5), TRUE);

    void *ptr16 = malloc(1);

    show_alloc_mem();
    write(1, "\n", 1);
}

void test3()
{
    void *ptr4  = malloc(64);
    void *ptr5  = malloc(128);
    void *ptr6  = malloc(64);

    show_alloc_mem();
    write(1, "\n", 1);

    set_block_is_free( BLOCK_UNSHIFT(ptr5) , TRUE);

    void *ptr16 = malloc(128);

    show_alloc_mem();
    write(1, "\n", 1);
}

void test4()
{
    t_block *block0 = malloc(96);
    t_block *block1 = malloc(37);
    t_block *block2 = malloc(120);
    t_block *block3 = malloc(150);
    t_block *block4 = malloc(150);
    t_block *block5 = malloc(150);
    t_block *block6 = malloc(64);
    t_block *block7 = malloc(300);
    t_block *block8 = malloc(512);
    t_block *block9 = malloc(42);
    t_block *block10 = malloc(2048);
    t_block *block11 = malloc(13);
    t_block *block12 = malloc(256);
    t_block *block13 = malloc(4096);
    t_block *block14 = malloc(128);
    t_block *block15 = malloc(999);
    t_block *block16 = malloc(75);
    t_block *block17 = malloc(700);
    t_block *block18 = malloc(50);
    t_block *block19 = malloc(160);
    t_block *block20 = malloc(320);
    t_block *block21 = malloc(81);
    t_block *block22 = malloc(192);
    t_block *block23 = malloc(2048);
    t_block *block24 = malloc(17);
    t_block *block25 = malloc(333);
    t_block *block26 = malloc(777);
    t_block *block27 = malloc(409);
    t_block *block28 = malloc(600);
    t_block *block29 = malloc(93);
    t_block *block30 = malloc(10000);
    t_block *block31 = malloc(2);
    t_block *block32 = malloc(55);
    t_block *block33 = malloc(345);
    t_block *block34 = malloc(870);
    t_block *block35 = malloc(130);
    t_block *block36 = malloc(940);
    t_block *block37 = malloc(500);
    t_block *block38 = malloc(19);
    t_block *block39 = malloc(73);
    t_block *block40 = malloc(3000);
    t_block *block41 = malloc(420);
    t_block *block42 = malloc(240);
    t_block *block43 = malloc(888);
    t_block *block44 = malloc(501);
    t_block *block45 = malloc(4096);
    t_block *block46 = malloc(11);
    t_block *block47 = malloc(170);
    t_block *block48 = malloc(690);
    t_block *block49 = malloc(555);
    t_block *block50 = malloc(200);


    

    show_alloc_mem();
    write(1, "\n", 1);
}


void test5()
{

    void *ptr1 = malloc(14);
    void *ptr2 = malloc(15);
    void *ptr3 = malloc(16);

    write(1, "Les pointeurs existent -t- ils ?\n", 33);

    display_bool( check_ptr_allocation( heap_anchor, ptr1));
    write(1, "\n", 1);

    display_bool( check_ptr_allocation( heap_anchor, ptr2));
    write(1, "\n", 1);

    display_bool( check_ptr_allocation( heap_anchor, ptr3));
    write(1, "\n", 1);

    char *stck_ptr = "poiteur dans la stack";
    display_bool( check_ptr_allocation( heap_anchor, stck_ptr));
    write(1, "\n", 1);

    show_alloc_mem();
    write(1, "\n", 1);
}


void test6()
{
    void *ptr1 = malloc(16);
    void *ptr2 = malloc(16);
    void *ptr3 = malloc(7);

    show_alloc_mem();

    write(1, "\n", 1);

    set_block_is_free(BLOCK_UNSHIFT(ptr1), TRUE);

    merge_previous_block(BLOCK_UNSHIFT(ptr2));

    show_alloc_mem();

    display_block_chain(HEAP_SHIFT(heap_anchor));

    merge_previous_block(BLOCK_UNSHIFT(ptr3));    


    show_alloc_mem();
}

int main()
{
    /*
    test0();
    write(1, "-----------------------------\n", 30);
    
    test1();
    write(1, "-----------------------------\n", 30);

    test2();
    write(1, "-----------------------------\n", 30);

    test3();
    write(1, "-----------------------------\n", 30);

    test4();

    write(1, "-----------------------------\n", 30);
    

    test5();
    write(1, "-----------------------------\n", 30);
    */

    test6();
    //write(1, "-----------------------------\n", 30);

    return 0;
}