#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>

# define BLOCK_MIN_SIZE 16

# define TINY_HEAP_SIZE (size_t)(4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_HEAP_SIZE / 128)
# define SMALL_HEAP_SIZE (size_t)(32 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_HEAP_SIZE / 128)


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

/*

	sizeof(t_heap) = 48
*/

typedef struct	s_heap
{
	struct s_heap	*prev;
	struct s_heap	*next;

	t_heap_group	group;
	size_t			total_size;    // Taille totale de la heap
	size_t			free_size;     // Espace de la heap qui n'appartient à aucun block (free ou pas !)
	size_t			block_count;   // Nombre de block dans la heap
}            t_heap;

/*

	sizeof(t_block) = 32
*/

typedef struct	s_block
{
	struct s_block	*prev;
	struct s_block	*next;
	size_t			data_size;     // Taille des données que dois pouvoir contenir le block
	t_bool			is_free;       // FALSE : block alloué / TRUE : block non alloué
}            t_block;

# define HEAP_SHIFT(start) ((void *)start + sizeof(t_heap))
# define BLOCK_SHIFT(start) ((void *)start + sizeof(t_block))

# define BLOCK_UNSHIFT(start) ((void*)start - sizeof(t_block))
# define HEAP_UNSHIFT(start) ((void *)start - sizeof(t_heap))

extern t_heap *heap_anchor;


void         free(void *ptr);
void         *malloc(size_t size);
void         *realloc(void *ptr, size_t size);

size_t       round_nearest_multiple(size_t size, size_t multiple_of);

t_heap_group get_heap_group_from_block_size(size_t block_size);
size_t       get_heap_size_from_heap_group(t_heap_group heap_group, size_t size);

void         set_heap (t_heap *heap, size_t total_size, size_t free_size, size_t block_count);
void         set_heap_group (t_heap *heap, t_heap_group group);
void         set_heap_total_size(t_heap *heap, size_t total_size);
void         set_heap_free_size(t_heap *heap, size_t free_size);
void         set_heap_block_count(t_heap *heap, size_t block_count);

void		 set_block_prev(t_block *block, t_block *prev);
void         set_block_next(t_block *block, t_block *next);
void         set_block_data_size(t_block *block, size_t size);
void         set_block_is_free(t_block *block, t_bool is_free);

t_block      *merge_previous_block (t_heap *heap, t_block *block);
t_block      *merge_next_block(t_heap *heap, t_block *block);
void         delete_last_block(t_heap *heap);

t_block      *search_block(t_block *first_block, size_t min_data_size, t_bool is_free);

t_heap       *search_heap(t_heap *heap_start, t_heap_group	group, size_t total_size, size_t free_size, size_t block_count);

t_heap       *find_heap_from_ptr (t_heap *heap_anchor, void *ptr);

void     	 split_block(t_heap  *heap, t_block *left_block, size_t  size);

void         create_block(t_block *ptr_block, size_t data_size, t_bool is_free);

t_heap       *create_heap(t_heap_group heap_group, size_t heap_size);
t_block      *add_block_back(t_heap *heap, size_t data_size, t_bool is_free);
void         add_heap_front(t_heap **heap_start, t_heap *heap_to_add);

void         delete_heap(t_heap *heap_to_delete, t_heap **heap_anchor);

void         t_heap_chain_iter(t_heap *first_heap, void (*f)(t_heap *));
void         block_chain_iter(t_block *first_block, void (*f)(t_block *));

size_t       block_chain_datasize (t_block *first_block);

t_block      *init_block_chain(t_heap *heap, size_t data_size);

void         display_nb(size_t nb);
void         display_hex(uintptr_t hex);
void         display_t_heap(t_heap *heap);
void         display_t_heap_group(t_heap_group heap_group);
void         display_t_heap_chain(t_heap *first_heap);
void         display_t_block(t_block *block);

void         display_block_content(t_block *block);
void         display_block_chain(t_block *b);
void         display_bool(t_bool bool);
void         show_alloc_mem();

void	     ft_bzero(void *s, size_t n);
void	     ft_putstr_fd(char *s, int fd);
size_t	     ft_strlen(const char *str);
void         *ft_memcpy(void *dst, const void *src, size_t n);
int          ft_memcmp(const void *s1, const void *s2, size_t n);

#endif