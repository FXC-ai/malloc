#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#import <stddef.h>
#include <stdbool.h>

#define COLOUR_GREEN "\033[0;32m"
#define COLOUR_RED "\033[0;31m"
#define COLOUR_BLUE "\033[0;34m"
#define COLOUR_PURPLE "\033[0;35m"
#define COLOUR_END "\033[0m"

#define TINY 51200
#define SMALL 819200


size_t ft_round_eight(size_t size);


void *heap_start = NULL;


typedef struct s_block_meta
{

	int size;
	struct s_block_meta *previous;
	struct s_block_meta *next;
	bool is_free;

} block_meta;


/* display a block meta */
void display_block_meta(block_meta *block, size_t index)
{
    printf("--------------------------------\n");

    printf("|%s%*zu                %s|\n",COLOUR_PURPLE,  14,index,COLOUR_END);
    printf("|  %saddr block = %s%*p   |\n",COLOUR_GREEN, COLOUR_END, 12,block);
    printf("|  %ssize       = %s%*d   |\n", COLOUR_GREEN, COLOUR_END,12,block->size);
    printf("|  %sprevious   = %s%*p   |\n",COLOUR_GREEN, COLOUR_END, 12,block->previous);
    printf("|  %snext       = %s%*p   |\n", COLOUR_GREEN, COLOUR_END,12,block->next);
    printf("|  %sis_free    = %s%*d   |\n",COLOUR_GREEN, COLOUR_END, 12,block->is_free);

    printf("--------------------------------\n");
}

/* display the chained list of memory block */
void display_memory(block_meta *first_block)
{
	block_meta *current_block;
	size_t counter;

	counter = 0;
	current_block = first_block;
	while (current_block->next != NULL)
	{
		display_block_meta(current_block, counter);
		printf("%s              |               %s\n",COLOUR_BLUE, COLOUR_END);
		printf("%s              v               %s\n",COLOUR_BLUE, COLOUR_END);
		current_block = current_block->next;
		++counter;
	}
		printf("%s            NULL              %s\n",COLOUR_RED, COLOUR_END);
}

/* return the pointer of the last block */
void *find_last_block_meta (block_meta *first_block)
{
	block_meta *current = first_block;

	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}

/* pre-allocate” some memory zones to store your “small” and “medium” */
void *ft_init_zone(size_t size_zone)
{
	void *ptr_zone;

	/* MAP_SHARED */
	ptr_zone = mmap(NULL, size_zone, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr_zone == MAP_FAILED)
	{
		perror("mmap");
		return NULL;
	}
	return (ptr_zone);
}

/* create a new list */
void *ft_create_new_list(block_meta *first_block, size_t size)
{

	size = ft_round_eight(size);

	first_block->size = size;
	first_block->previous = NULL;
	first_block->next = NULL;
	first_block->is_free = false;

	return (void *) (first_block + sizeof(block_meta));
}


/* Add a new block of size bytes of datas */
void *ft_add_new_block(block_meta *first_block, size_t size)
{
	block_meta *new_block;
	block_meta *last_block;
	int *security;

	size = ft_round_eight(size);
	last_block = find_last_block_meta(first_block);
	new_block = (void *) last_block + sizeof(block_meta) + last_block->size + sizeof(int);

	last_block->next = new_block;

	new_block->size = size;
	new_block->previous = last_block;
	new_block->next = NULL;
	new_block->is_free = false;

	security = (void *) new_block + sizeof(block_meta) + size;
	*security = size;

	return (void *) (new_block + sizeof(block_meta));
}

void *ft_malloc (size_t size)
{

	// size = size + sizeof(int);

	if (heap_start == NULL)
	{
		void *ptr_tiny = NULL;
		void *ptr_small = NULL;
		void *ptr_large = NULL;
		/*Inutile d'allouer systematiquement... ?*/
		
		// besoin d etre amelioré !!!!!!!!!!!! PAs besoin d allouer systematiquement ....

		// printf("%ld %ld\n", ptr_small - ptr_tiny, ptr_large - ptr_small);

		if (size <= 512)
		{
			ptr_tiny = ft_init_zone(TINY);
			heap_start = ptr_tiny;
			return ft_create_new_list(ptr_tiny, size);
		}
		else if (size <= 8192)
		{
			ptr_small = ft_init_zone(SMALL);
			heap_start = ptr_small;
			return ft_create_new_list(ptr_small, size);
		}
		else
		{
			/* need to code that */
		}
		// Il y aura besoin d'un else pour les allocations encore plus grande...

	}
	else
	{
		if (size <= 512)
		{
			return ft_add_new_block(heap_start, size);
		}

	}
	return NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	str = NULL;
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s) - start > len)
		str = ft_malloc(sizeof(char) * (len + 1));
	else
		str = ft_malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && start + i < ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t ft_round_eight(size_t size)
{
	// return size + (8 - (size % 8));
	return (size + 7) & ~7;
}

int main()
{

    printf("Size of block_meta: %lu %lu\n", sizeof(block_meta), sizeof(int));
    // printf("Offset of size_previous: %lu\n", offsetof(block_meta, size_previous));
    // printf("Offset of size: %lu\n", offsetof(block_meta, size));
    // printf("Offset of previous: %lu\n", offsetof(block_meta, previous));
    // printf("Offset of next: %lu\n", offsetof(block_meta, next));
    // printf("Offset of is_free: %lu\n", offsetof(block_meta, is_free));
	// printf("sizeof block meta = %ld\n", sizeof(block_meta));

	char *ptr_test0 = (char *) ft_malloc(10);

	printf("First memory address = %p\n", heap_start);

	printf("ptr_test0 = %p\n",  ptr_test0);


	ptr_test0[0] = 'a';
	ptr_test0[1] = 'a';
	ptr_test0[2] = 'a';
	ptr_test0[3] = 'a';
	ptr_test0[4] = 'a';
	ptr_test0[5] = 'a';
	ptr_test0[6] = 'a';
	ptr_test0[7] = 'a';
	ptr_test0[8] = 'a';
	ptr_test0[9] = '\0';


	char *ptr_test1 = (char *) ft_malloc(10);
	printf("ptr_test1 = %p\n",ptr_test1);

	char *ptr_test2 = (char *) ft_malloc(10);
	printf("ptr_test2 = %p\n",ptr_test2);

	char *ptr_test3 = (char *) ft_malloc(10);
	printf("ptr_test3 = %p\n",ptr_test3);

	char *str_test  = "0123456789";
	char *sub_str_test = ft_substr(str_test, 1, 4);
	printf("sub_str_test = %s\n", sub_str_test);

	display_memory(heap_start);

	

	return 0;
}