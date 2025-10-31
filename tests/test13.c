#include "../inc/malloc.h"


int main(void)
{
    int failed = 0;

    t_block *ptr0  = malloc(96);   if (!ptr0)  failed = 1;
    t_block *ptr1  = malloc(37);   if (!ptr1)  failed = 1;
    t_block *ptr2  = malloc(120);  if (!ptr2)  failed = 1;
    t_block *ptr3  = malloc(150);  if (!ptr3)  failed = 1;
    t_block *ptr4  = malloc(150);  if (!ptr4)  failed = 1;
    t_block *ptr5  = malloc(150);  if (!ptr5)  failed = 1;
    t_block *ptr6  = malloc(64);   if (!ptr6)  failed = 1;
    t_block *ptr7  = malloc(300);  if (!ptr7)  failed = 1;
    t_block *ptr8  = malloc(512);  if (!ptr8)  failed = 1;
    t_block *ptr9  = malloc(42);   if (!ptr9)  failed = 1;
    t_block *ptr10 = malloc(2048); if (!ptr10) failed = 1;
    t_block *ptr11 = malloc(13);   if (!ptr11) failed = 1;
    t_block *ptr12 = malloc(256);  if (!ptr12) failed = 1;
    t_block *ptr13 = malloc(4096); if (!ptr13) failed = 1;
    t_block *ptr14 = malloc(128);  if (!ptr14) failed = 1;
    t_block *ptr15 = malloc(999);  if (!ptr15) failed = 1;
    t_block *ptr16 = malloc(75);   if (!ptr16) failed = 1;
    t_block *ptr17 = malloc(700);  if (!ptr17) failed = 1;
    t_block *ptr18 = malloc(50);   if (!ptr18) failed = 1;
    t_block *ptr19 = malloc(160);  if (!ptr19) failed = 1;
    t_block *ptr20 = malloc(320);  if (!ptr20) failed = 1;
    t_block *ptr21 = malloc(81);   if (!ptr21) failed = 1;
    t_block *ptr22 = malloc(192);  if (!ptr22) failed = 1;
    t_block *ptr23 = malloc(2048); if (!ptr23) failed = 1;
    t_block *ptr24 = malloc(17);   if (!ptr24) failed = 1;
    t_block *ptr25 = malloc(333);  if (!ptr25) failed = 1;
    t_block *ptr26 = malloc(777);  if (!ptr26) failed = 1;
    t_block *ptr27 = malloc(409);  if (!ptr27) failed = 1;
    t_block *ptr28 = malloc(600);  if (!ptr28) failed = 1;
    t_block *ptr29 = malloc(93);   if (!ptr29) failed = 1;
    t_block *ptr30 = malloc(10000);if (!ptr30) failed = 1;
    t_block *ptr31 = malloc(2);    if (!ptr31) failed = 1;
    t_block *ptr32 = malloc(55);   if (!ptr32) failed = 1;
    t_block *ptr33 = malloc(345);  if (!ptr33) failed = 1;
    t_block *ptr34 = malloc(870);  if (!ptr34) failed = 1;
    t_block *ptr35 = malloc(130);  if (!ptr35) failed = 1;
    t_block *ptr36 = malloc(940);  if (!ptr36) failed = 1;
    t_block *ptr37 = malloc(500);  if (!ptr37) failed = 1;
    t_block *ptr38 = malloc(19);   if (!ptr38) failed = 1;
    t_block *ptr39 = malloc(73);   if (!ptr39) failed = 1;
    t_block *ptr40 = malloc(3000); if (!ptr40) failed = 1;
    t_block *ptr41 = malloc(420);  if (!ptr41) failed = 1;
    t_block *ptr42 = malloc(240);  if (!ptr42) failed = 1;
    t_block *ptr43 = malloc(888);  if (!ptr43) failed = 1;
    t_block *ptr44 = malloc(501);  if (!ptr44) failed = 1;
    t_block *ptr45 = malloc(4096); if (!ptr45) failed = 1;
    t_block *ptr46 = malloc(11);   if (!ptr46) failed = 1;
    t_block *ptr47 = malloc(170);  if (!ptr47) failed = 1;
    t_block *ptr48 = malloc(690);  if (!ptr48) failed = 1;
    t_block *ptr49 = malloc(555);  if (!ptr49) failed = 1;
    t_block *ptr50 = malloc(200);  if (!ptr50) failed = 1;



    show_alloc_mem();

    if (failed)
    {
        write(1, "\033[31mFAIL\033[0m\n", sizeof("\033[31mFAIL\033[0m\n") - 1);
        return 1;
    }

    return 0;
}