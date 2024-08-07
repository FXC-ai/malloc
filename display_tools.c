#include "malloc.h"

void display_memory (t_heap *first_heap)
{
	t_heap *current_heap;
	size_t counter;

    printf("%s___________HEAPS LIST___________%s\n", COLOUR_BLUE, COLOUR_END);

	counter = 0;
	current_heap = first_heap;
	while (current_heap != NULL)
	{
		// display_heap_meta(current_heap, counter);
		display_blocks_chain(current_heap);
		current_heap = current_heap->next;
		++counter;
	}
	printf("%s            NULL              %s\n",COLOUR_RED, COLOUR_END);
    printf("%s________________________________%s\n", COLOUR_BLUE, COLOUR_END);

}

/* display a block meta */
void display_block(t_block *block, size_t index)
{

	if (block == NULL)
		printf("%s                      NULL              %s\n",COLOUR_RED, COLOUR_END);
	else
	{
		printf("          --------------------------------\n");

		printf("          |  %sID BLOCK   = %s%*zu   |\n",COLOUR_PURPLE,  COLOUR_END, 12,index);
		printf("          |  %saddr block = %s%*p   |\n",COLOUR_GREEN, COLOUR_END, 12,block);
		printf("          |  %ssize       = %s%*d   |\n", COLOUR_GREEN, COLOUR_END,12,block->size);
		printf("          |  %sprevious   = %s%*p   |\n",COLOUR_GREEN, COLOUR_END, 12,block->previous);
		printf("          |  %snext       = %s%*p   |\n", COLOUR_GREEN, COLOUR_END,12,block->next);
		printf("          |  %sis_free    = %s%*d   |\n",COLOUR_GREEN, COLOUR_END, 12,block->is_free);

		printf("          --------------------------------\n");
	}

}

/* display the chained list of memory block */
void display_blocks_chain(t_heap *heap)
{
	t_block *current_block;
	size_t counter;

	display_heap_meta(heap, 0);


	if (heap->block_count == 0)
		printf("%sNO BLOCK allocated in this heap.%s\n", COLOUR_RED, COLOUR_END);
	else
	{

		counter = 0;
		current_block = (t_block *) HEAP_SHIFT(heap);
		while (current_block != NULL)
		{
			display_block(current_block, counter);
			printf("%s                        |               %s\n",COLOUR_BLUE, COLOUR_END);
			printf("%s                        v               %s\n",COLOUR_BLUE, COLOUR_END);
			current_block = current_block->next;
			++counter;
		}
		printf("%s                      NULL              %s\n",COLOUR_RED, COLOUR_END);
	}
}




/* display heap meta _data */

void display_heap_meta(t_heap *heap, size_t index)
{
    printf("--------------------------------\n");

    printf("|  %sID HEAP     = %s%*zu   |\n",COLOUR_PURPLE, COLOUR_END, 11,index);
    printf("|  %saddr heap   = %s%*p   |\n",COLOUR_GREEN, COLOUR_END, 11,heap);
    printf("|  %sprevious    = %s%*p   |\n",COLOUR_GREEN, COLOUR_END, 11,heap->previous);
    printf("|  %snext        = %s%*p   |\n", COLOUR_GREEN, COLOUR_END,11,heap->next);
    printf("|  %sgroup       = %s%*d   |\n", COLOUR_GREEN, COLOUR_END,11,heap->group);
    printf("|  %stotal_size  = %s%*zu   |\n", COLOUR_GREEN, COLOUR_END,11,heap->total_size);
    printf("|  %sfree_size   = %s%*zu   |\n",COLOUR_GREEN, COLOUR_END, 11,heap->free_size);
    printf("|  %sblock_count = %s%*zu   |\n",COLOUR_GREEN, COLOUR_END, 11,heap->block_count);

    printf("--------------------------------\n");
}


/* display the chained list of memory block */
void display_heaps_chain(t_heap *first_heap)
{
	t_heap *current_heap;
	size_t counter;

    printf("%s___________HEAPS LIST___________%s\n", COLOUR_BLUE, COLOUR_END);

	counter = 0;
	current_heap = first_heap;
	while (current_heap != NULL)
	{
		display_heap_meta(current_heap, counter);
        printf("%s              |               %s\n",COLOUR_BLUE, COLOUR_END);
        printf("%s              v               %s\n",COLOUR_BLUE, COLOUR_END);
		current_heap = current_heap->next;
		++counter;
	}
	printf("%s            NULL              %s\n",COLOUR_RED, COLOUR_END);
    printf("%s________________________________%s\n", COLOUR_BLUE, COLOUR_END);

}