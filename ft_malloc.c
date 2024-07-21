#include "malloc.h"

void *heap_start = NULL;

void *ft_malloc (size_t size)
{
	printf("%zu", size);
	// size = size + sizeof(int);

	// if (heap_start == NULL)
	// {
	// 	void *ptr_tiny = NULL;
	// 	void *ptr_small = NULL;
	// 	void *ptr_large = NULL;

	// 	if (size <= 512)
	// 	{
	// 		ptr_tiny = ft_init_zone(51200);
	// 		heap_start = ptr_tiny;
	// 		return ft_create_new_list(ptr_tiny, size);
	// 	}
	// 	else if (size <= 8192)
	// 	{
	// 		ptr_small = ft_init_zone(SMALL);
	// 		heap_start = ptr_small;
	// 		return ft_create_new_list(ptr_small, size);
	// 	}
	// 	else
	// 	{
	// 		/* need to code that */
	// 	}

	// }
	// else
	// {
	// 	if (size <= 512)
	// 	{
	// 		return ft_add_new_block(heap_start, size);
	// 	}

	// }
	return NULL;
}

int main()
{

    printf("Size of t_block_meta: %lu\n", sizeof(t_block_meta));
    printf("Size of meta_data_heap: %lu\n", sizeof(t_heap));

	t_heap *new_heap = ft_init_heap(TINY_HEAP_ALLOCATION_SIZE);
	t_heap *new_heap_small = ft_init_heap(SMALL_HEAP_ALLOCATION_SIZE);

	display_heap_meta(new_heap, 0);
	display_heap_meta(new_heap_small, 1);



    // printf("Offset of size_previous: %lu\n", offsetof(t_block_meta, size_previous));
    // printf("Offset of size: %lu\n", offsetof(t_block_meta, size));
    // printf("Offset of previous: %lu\n", offsetof(t_block_meta, previous));
    // printf("Offset of next: %lu\n", offsetof(t_block_meta, next));
    // printf("Offset of is_free: %lu\n", offsetof(t_block_meta, is_free));
	// printf("sizeof block meta = %ld\n", sizeof(t_block_meta));

	// char *ptr_test0 = (char *) ft_malloc(10);

	// printf("First memory address = %p\n", heap_start);

	// printf("ptr_test0 = %p\n",  ptr_test0);

	// ptr_test0[0] = 'a';
	// ptr_test0[1] = 'a';
	// ptr_test0[2] = 'a';
	// ptr_test0[3] = 'a';
	// ptr_test0[4] = 'a';
	// ptr_test0[5] = 'a';
	// ptr_test0[6] = 'a';
	// ptr_test0[7] = 'a';
	// ptr_test0[8] = 'a';
	// ptr_test0[9] = '\0';

	// char *ptr_test1 = (char *) ft_malloc(10);
	// printf("ptr_test1 = %p\n",ptr_test1);

	// char *ptr_test2 = (char *) ft_malloc(10);
	// printf("ptr_test2 = %p\n",ptr_test2);

	// char *ptr_test3 = (char *) ft_malloc(10);
	// printf("ptr_test3 = %p\n",ptr_test3);

	// char *str_test  = "0123456789";
	// char *sub_str_test = ft_substr(str_test, 1, 4);
	// printf("sub_str_test = %s\n", sub_str_test);

	// char *ptr_test4 = (char *) ft_malloc(200);
	// printf("ptr_test4 = %p\n",ptr_test4);

	// display_memory(heap_start);

	return 0;
}