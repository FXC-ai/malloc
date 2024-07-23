#include "malloc.h"

void *heap_start = NULL;


size_t ft_calculate_heap_size (size_t size)
{
	size = ft_round_eight(size);

	if (size <= 128 )
		return TINY_HEAP_ALLOCATION_SIZE;
	else if (size <= 512)
		return SMALL_HEAP_ALLOCATION_SIZE;
	else
		return size + sizeof(t_heap);
}

t_heap_group ft_find_group (size_t size)
{
	if (size <= 128)
		return TINY;
	else if (size <= 512)
		return SMALL;
	else
		return LARGE;
}

void *ft_malloc (size_t size)
{
	printf("size asked = %zu\n", size);

	if (heap_start == NULL)
	{
		heap_start = ft_init_heap(ft_calculate_heap_size(size));


		return HEAP_SHIFT(heap_start);
	}
	else
	{
		t_heap *heap_found = ft_find_heap_group(heap_start, ft_find_group(size));
		if (heap_found == NULL)
		{
			t_heap *new_heap = ft_add_new_heap(heap_start, ft_calculate_heap_size(size));
			if (new_heap == NULL)
				return NULL;
			return HEAP_SHIFT(new_heap);
		}
		else
		{
			// une heap avec le groupe adaptée existe
			printf("need to think...\n");
		}

	}

	return NULL;
}

void ut_ft_init_heap()
{
	t_heap *new_heap = ft_init_heap(TINY_HEAP_ALLOCATION_SIZE);
	t_heap *new_heap_small = ft_init_heap(SMALL_HEAP_ALLOCATION_SIZE);
	t_heap *new_heap_large = ft_init_heap(66000);

	display_heap_meta(new_heap,0);
	display_heap_meta(new_heap_small,1);
	display_heap_meta(new_heap_large,2);
}

void ut_ft_find_last_heap(t_heap *first_heap)
{
	t_heap *last_heap = ft_find_last_heap(first_heap);
	display_heaps_chain(first_heap);
	display_heap_meta(last_heap,0);
}

void ut_ft_add_new_heap(t_heap *first_heap)
{

	t_heap *first_added = ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE);
	t_heap *second_added = ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE);
	t_heap *third_added = ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE);
	t_heap *fourth_added = ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE);
	t_heap *fifth_added = ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE);
	t_heap *sixth_added = ft_add_new_heap(first_heap, 100000);

	display_heaps_chain(first_heap);
}

void ut_ft_find_heap_group()
{
	t_heap *first_heap = ft_init_heap(100000);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE);
	ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE);
	ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE);

	t_heap *found_heap = ft_find_heap_group(first_heap, SMALL);

	display_heaps_chain(first_heap);
	display_heap_meta(found_heap, 0);
}

void ut_ft_find_group ()
{
	printf("size = 128 : %d\n", ft_find_group(128));
	printf("size = 512 : %d\n", ft_find_group(512));
	printf("size = 1280 : %d\n", ft_find_group(1280));
}


void ut_ft_add_new_block ()
{
	t_heap *first_heap = ft_init_heap(TINY_HEAP_ALLOCATION_SIZE);

	t_block *new_block = ft_add_new_block(first_heap, 75);
	t_block *new_block1 = ft_add_new_block(first_heap, 12);
	t_block *new_block2 = ft_add_new_block(first_heap, 12);
	t_block *new_block3 = ft_add_new_block(first_heap, 12);
	t_block *new_block4 = ft_add_new_block(first_heap, 12);
	t_block *new_block5 = ft_add_new_block(first_heap, 0);
	t_block *new_block6 = ft_add_new_block(first_heap, 12);
	t_block *new_block7 = ft_add_new_block(first_heap, 1);
	t_block *new_block8 = ft_add_new_block(first_heap, 12);
	t_block *new_block9 = ft_add_new_block(first_heap, 110);
	t_block *new_block10 = ft_add_new_block(first_heap, 12);
	t_block *new_block11 = ft_add_new_block(first_heap, 12);
	t_block *new_block12 = ft_add_new_block(first_heap, 128);


	display_blocks_chain(first_heap);
}



int main()
{

    printf("Size of t_block: %lu\n", sizeof(t_block));
    printf("Size of meta_data_heap: %lu\n", sizeof(t_heap));





	t_heap *first_heap = ft_init_heap(TINY_HEAP_ALLOCATION_SIZE);


	// void * ptr_writable = ft_malloc(12);
	// ft_malloc(1300);
	// ft_malloc(1300);

	ut_ft_add_new_block();






	// void *test = HEAP_SHIFT(heap_start);

	// printf("%p\n", test);


	return 0;
}