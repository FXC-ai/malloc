#ifndef MALLOC_H
# define MALLOC_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#import <stddef.h>


#define COLOUR_GREEN "\033[0;32m"
#define COLOUR_RED "\033[0;31m"
#define COLOUR_BLUE "\033[0;34m"
#define COLOUR_PURPLE "\033[0;35m"
#define COLOUR_END "\033[0m"

#define	TINY_HEAP_ALLOCATION_SIZE 16384
#define	SMALL_HEAP_ALLOCATION_SIZE 65536
#define TINY_BLOCK_SIZE 128
#define SMALL_BLOCK_SIZE 512


#define HEAP_SHIFT(start)((void *)start + sizeof(t_heap))


typedef enum e_heap_group
{
	TINY,
	SMALL,
	LARGE
} t_heap_group;

typedef struct s_heap {
	struct s_heap *previous;
	struct s_heap *next;
	t_heap_group group;
	size_t total_size;
	size_t free_size;
	size_t block_count;

} t_heap;

typedef struct s_block_meta
{

	int size;
	struct s_block_meta *previous;
	struct s_block_meta *next;
	bool is_free;

} t_block_meta;

/*heap_manager_tool.c*/
t_heap *ft_init_heap(size_t heap_size);
t_heap *ft_add_new_heap (t_heap *first_heap, size_t heap_size);
t_heap *ft_find_last_heap (t_heap *first_heap);
t_heap *ft_find_heap_group (t_heap *first_heap, t_heap_group group);



/*block_manager_tools.c*/
void *find_last_block_meta (t_block_meta *first_block);
void *ft_create_new_list(t_block_meta *first_block, size_t size);
void *ft_add_new_block(t_block_meta *first_block, size_t size);
size_t ft_round_eight(size_t size);

/*display_tools.c*/
void display_block_meta(t_block_meta *block, size_t index);
void display_memory(t_block_meta *first_block);
void display_heap_meta(t_heap *heap, size_t index);
void display_heaps_chain(t_heap *first_heap);


#endif