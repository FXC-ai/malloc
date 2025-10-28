#include "inc/malloc.h"

t_bool test1()
{
    char *ptr1 = malloc(21);
    (void) ptr1;
    char *dst = malloc(12);

    display_t_block((t_block *) BLOCK_UNSHIFT(dst));

    char *src = "Hello World !";

    if (dst == NULL)
        return FALSE;

    ft_memcpy(dst, src, 13);

    if (!ft_memcmp(dst, src, 13))
    {
        return TRUE;
    }
    
    display_t_block((t_block *) BLOCK_UNSHIFT(dst));

    show_alloc_mem();

    return FALSE;
}

t_bool test2()
{
    void **ptr[102];
    void *tmp_ptr;
    int i;

    tmp_ptr = NULL;

    for (i = 0; i < 102; i++)
    {
        tmp_ptr = malloc(128);
        if (tmp_ptr == NULL)
        {
            return FALSE;
        }
        ptr[i] = tmp_ptr;
    }

    write(1, "\n",1);
    show_alloc_mem();
    write(1, "\n",1);

    return TRUE;
}

t_bool test3()
{
    void **ptr[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        ptr[i] = malloc(128);
        if (ptr[i] == NULL)
        {
            return FALSE;
        }
    }

    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[0]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[1]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[2]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[3]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[4]);
    write(1, "\n",1);
    show_alloc_mem();

    return TRUE;
}

t_bool test4()
{

    void **ptr[9];
    void *tmp_ptr;
    int i;

    tmp_ptr = NULL;

    for (i = 0; i < 3; i++)
    {
        tmp_ptr = malloc(128);
        if (tmp_ptr == NULL)
        {
            return FALSE;
        }
        ptr[i] = tmp_ptr;
    }

    for (i = 0; i < 3; i++)
    {
        tmp_ptr = malloc(1024);
        if (tmp_ptr == NULL)
        {
            return FALSE;
        }
        ptr[i] = tmp_ptr;
    }

    for (i = 0; i < 3; i++)
    {
        tmp_ptr = malloc(4025);
        if (tmp_ptr == NULL)
        {
            return FALSE;
        }
        ptr[i] = tmp_ptr;
    }

    show_alloc_mem();

    return TRUE;
}


t_bool test5()
{
    int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}

    show_alloc_mem();

    return TRUE;
}

t_bool test6()
{
    int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
        show_alloc_mem();
        write(1,"\n",1);
        ft_putstr_fd(addr,1);
        write(1,"\n",1);

		free(addr);
		i++;
	}

    show_alloc_mem();

	return (TRUE);
}

t_bool test7()
{
    void *ptr = malloc(1024);
	void *ptr1 = malloc(1024 * 32);
	void *ptr2 = malloc(1024 * 1024);
	void *ptr3 = malloc(1024 * 1024 * 16);
	void *ptr4 = malloc(1024 * 1024 * 128);

    (void) ptr;
    (void) ptr1;
    (void) ptr2;
    (void) ptr3;
    (void) ptr4;

	show_alloc_mem();
}

t_bool test8()
{   
    void **ptr[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        ptr[i] = malloc(128);
        if (ptr[i] == NULL)
        {
            return FALSE;
        }
    }
	show_alloc_mem();

    return TRUE;
}

int main()
{

    int choix = 1;


    switch (choix)
    {
        case 1:
            ft_putstr_fd("test 1 : ", 1);
            display_bool(test1());
            write(1,"\n",1);
            break;
        case 2:
            ft_putstr_fd("test 2 : ", 1);
            display_bool(test2());
            write(1,"\n",1);
            break;
        case 3:
            ft_putstr_fd("test 3 : ", 1);
            display_bool(test3());
            write(1,"\n",1);
            break;
        case 4:
            ft_putstr_fd("test 4 : \n", 1);
            display_bool(test4());
            write(1,"\n",1);
            break;
        case 5:
            ft_putstr_fd("test 5 : \n", 1);
            display_bool(test5());
            write(1,"\n",1);
            break;
        case 6:
            ft_putstr_fd("test 6 : \n", 1);
            display_bool(test6());
            write(1,"\n",1);
            break;
        case 7:
            ft_putstr_fd("test 7 : \n", 1);
            display_bool(test7());
            write(1,"\n",1);
            break;
        case 8:
            ft_putstr_fd("test 8 : \n", 1);
            display_bool(test8());
            write(1,"\n",1);
            break; 
        default:
            ft_putstr_fd("Choisir un test\n", 1);
            break; 
    }



    return 0;
}