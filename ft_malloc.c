#include "malloc.h"

t_heap *heap_start = NULL;


void ut_ft_init_heap()
{
	t_heap *new_heap = ft_init_heap(TINY_HEAP_ALLOCATION_SIZE, TINY);
	t_heap *new_heap_small = ft_init_heap(SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	t_heap *new_heap_large = ft_init_heap(66000, LARGE);

	display_heap_meta(new_heap,0);
	display_heap_meta(new_heap_small,1);
	display_heap_meta(new_heap_large,2);
}

void ut_ft_find_last_heap()
{
	t_heap *first_heap = ft_init_heap(SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	t_heap *last_heap = ft_find_last_heap(first_heap);
	display_heaps_chain(first_heap);
	display_heap_meta(last_heap,0);
}

void ut_ft_add_new_heap()
{
	t_heap *first_heap = ft_init_heap(SMALL_HEAP_ALLOCATION_SIZE, SMALL);

	t_heap *first_added = ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	t_heap *second_added = ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE, TINY);
	t_heap *third_added = ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	t_heap *fourth_added = ft_add_new_heap(first_heap, ft_calculate_heap_size(600), LARGE);
	t_heap *fifth_added = ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	t_heap *sixth_added = ft_add_new_heap(first_heap, ft_calculate_heap_size(100000), LARGE);

	display_heaps_chain(first_heap);
}

void ut_ft_find_heap_group()
{
	t_heap *first_heap = ft_init_heap(100000, LARGE);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE, TINY);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE, TINY);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE, TINY);
	ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	ft_add_new_heap(first_heap, SMALL_HEAP_ALLOCATION_SIZE, SMALL);
	ft_add_new_heap(first_heap, TINY_HEAP_ALLOCATION_SIZE, TINY);

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
	t_heap *first_heap = ft_init_heap(TINY_HEAP_ALLOCATION_SIZE, TINY);

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


void ut_ft_calculate_heap_size()
{

	printf("%d : %zu (%zu pages)\n", 1, ft_calculate_heap_size(1), ft_calculate_heap_size(1) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 10, ft_calculate_heap_size(10), ft_calculate_heap_size(10) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 100, ft_calculate_heap_size(100), ft_calculate_heap_size(100) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 120, ft_calculate_heap_size(120), ft_calculate_heap_size(120) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 128, ft_calculate_heap_size(128), ft_calculate_heap_size(128) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 256, ft_calculate_heap_size(256), ft_calculate_heap_size(256) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 510, ft_calculate_heap_size(210), ft_calculate_heap_size(210) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 500, ft_calculate_heap_size(500), ft_calculate_heap_size(500) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 512, ft_calculate_heap_size(512), ft_calculate_heap_size(512) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 516, ft_calculate_heap_size(516), ft_calculate_heap_size(516) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 1024, ft_calculate_heap_size(1024), ft_calculate_heap_size(1024) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 100000, ft_calculate_heap_size(100000), ft_calculate_heap_size(100000) / getpagesize());
	printf("%d : %zu (%zu pages)\n", 1000000, ft_calculate_heap_size(1000000), ft_calculate_heap_size(1000000) / getpagesize());


}

/* Return the adapted size of the heap given the size of allocated bytes asked */
size_t ft_calculate_heap_size (size_t size)
{
	size = ft_round_eight(size);

	if (size <= 128)
		return TINY_HEAP_ALLOCATION_SIZE;
	else if (size <= 512)
		return SMALL_HEAP_ALLOCATION_SIZE;
	else
	{
		size_t r = getpagesize() * ((size + sizeof(t_heap)) / getpagesize());
		if (size % getpagesize() > 0)
			r += getpagesize();
		return r;
	}
}

/* Return the type (group) of heap needed (TINY SMALL OR LARGE)*/
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
	// printf("size asked = %zu\n", size);

	if (heap_start == NULL)
	{
		size_t heap_size = ft_calculate_heap_size(size);
		t_heap_group group = ft_find_group(size);

		heap_start = ft_init_heap(heap_size, group);
		t_block *first_block = ft_add_new_block(heap_start, size);

		return BLOCK_SHIFT(first_block);
	}
	else
	{
		t_heap *heap_found = ft_find_heap_group(heap_start, ft_find_group(size));
		if (heap_found == NULL)
		{
			t_heap *new_heap = ft_add_new_heap(heap_start, ft_calculate_heap_size(size), ft_find_group(size));
			if (new_heap == NULL)
				return NULL;
			t_block *first_block = ft_add_new_block(heap_start, size);
			return BLOCK_SHIFT(first_block);
		}
		else
		{
			t_heap_group group_researched = ft_find_group(size);
			// une heap avec le groupe adaptée existe
			printf("need to think... %d\n", group_researched);
		}

	}

	return NULL;
}

int main()
{

    printf("Size of t_block: %lu\n", sizeof(t_block));
    printf("Size of t_heap : %lu\n", sizeof(t_heap));



	// ut_ft_init_heap();
	// ut_ft_find_last_heap();
	// ut_ft_calculate_heap_size();

	// ut_ft_add_new_heap();


	void * ptr_writable = ft_malloc(25);

	void *ptr_writable1 = ft_malloc(269);
	void *ptr_writable2 = ft_malloc(1300);
	void *ptr_writable3 = ft_malloc(1300);

	display_block(ptr_writable, 0);
	display_block(ptr_writable1, 1);
	display_block(ptr_writable2, 2);

	display_heaps_chain(heap_start);

	// ut_ft_add_new_block();


	return 0;
}