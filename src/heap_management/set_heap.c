#include "../inc/malloc.h"


void set_heap
(
    t_heap *heap,
    t_heap_group group,
    size_t total_size,
    size_t free_size,
    size_t block_count
)
{
    heap->group = group;
    heap->total_size = total_size;
    heap->free_size = free_size;
    heap->block_count = block_count;
}

void set_heap_group (t_heap *heap, t_heap_group group)
{
    heap->group = group;
}

void set_heap_total_size(t_heap *heap, size_t total_size)
{
    heap->total_size = total_size;
}

void set_heap_free_size(t_heap *heap, size_t free_size)
{
    heap->free_size = free_size;
}

void set_heap_block_count(t_heap *heap, size_t block_count)
{
    heap->block_count = block_count;
}
