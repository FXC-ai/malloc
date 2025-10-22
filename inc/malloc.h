#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>

# define TINY_HEAP_SIZE (size_t)(4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_HEAP_SIZE / 128)
# define SMALL_HEAP_SIZE (size_t)(32 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_HEAP_SIZE / 128)

extern void *heap_anchor;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_heap_group
{
	TINY,
	SMALL,
	LARGE
}            t_heap_group;

typedef struct	s_heap
{
	struct s_heap	*prev;
	struct s_heap	*next;
	t_heap_group	group;
	size_t			total_size;    // Taille totale de la heap
	size_t			free_size;     // Espace de la heap qui n'appartient à aucun block (free ou pas !)
	size_t			block_count;   // Nombre de block dans la heap
}            t_heap;

typedef struct	s_block
{
	struct s_block	*prev;
	struct s_block	*next;
	size_t			data_size;     // Taille des données que dois pouvoir contenir le block
	t_bool			is_free;       // FALSE : block alloué / TRUE : block non alloué
}            t_block;

void         free(void *ptr);
void         *malloc(size_t size);
void         *realloc(void *ptr, size_t size);

size_t       ceil_size(size_t size, int multiple_of);

t_heap_group get_heap_group_from_block_size(size_t block_size);
size_t       get_heap_size_from_heap_group(t_heap_group heap_group);

t_block      *search_block(t_heap *heap, t_bool is_free, size_t min_data_size);
t_heap       *search_heap(t_heap **heap_anchor, t_heap_group heap_group, size_t avaible_size);
t_block      *split_block(t_block *block, size_t size);
t_block      create_block(size_t data_size, t_bool is_free);
t_heap       *create_heap(size_t heap_size);
void         add_block_back(t_heap *heap, t_block block);
void         add_heap_front(t_heap *heap_anchor, t_heap *heap_to_add);

void         display_nb(size_t nb);
void         display_hex(size_t hex);
void         display_t_heap(t_heap *heap);
void         display_t_heap_group(t_heap_group heap_group);
void         display_t_heap_chain(t_heap *first_heap);

#endif