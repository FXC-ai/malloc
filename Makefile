CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -fPIC -I inc
LDFLAGS := -shared
NAME    := libft_malloc.so

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

REAL_LIB := libft_malloc_$(HOSTTYPE).so

SRCS := \
	src/malloc.c \
	src/free.c \
	src/realloc.c \
	src/calloc.c \
	src/show_alloc_mem.c \
	src/show_alloc_mem_ex.c \
	src/utils/get_heap_group_from_block_size.c \
	src/utils/get_heap_size_from_heap_group.c \
	src/utils/round_nearest_multiple.c \
	src/heap_management/create_heap.c \
	src/heap_management/add_heap_front.c \
	src/heap_management/search_heap.c \
	src/heap_management/find_heap_from_ptr.c \
	src/heap_management/delete_heap.c \
	src/heap_management/t_heap_chain_iter.c \
	src/block_management/create_block.c \
	src/block_management/add_block_back.c \
	src/block_management/init_block_chain.c \
	src/block_management/search_block.c \
	src/block_management/split_block.c \
	src/block_management/split_block2.c \
	src/block_management/merge_previous_block.c \
	src/block_management/merge_next_block.c \
	src/block_management/delete_last_block.c \
	src/block_management/set_block.c \
	src/block_management/block_chain_iter.c \
	src/block_management/block_chain_datasize.c \
	src/display/display_t_heap.c \
	src/display/display_heap_chain.c \
	src/display/display_t_heap_group.c \
	src/display/display_t_block.c \
	src/display/display_block_chain.c \


OBJS := $(SRCS:src/%.c=obj/%.o)

all: libft/libft.a $(NAME)

$(NAME): $(REAL_LIB)
	@rm -f $(NAME)
	@ln -s $(REAL_LIB) $(NAME)


$(REAL_LIB): $(OBJS) libft/libft.a
	$(CC) -shared $(OBJS) -Wl,--whole-archive libft/libft.a -Wl,--no-whole-archive -o $(REAL_LIB)


obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


libft/libft.a:
	$(MAKE) -C libft clean
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME) $(REAL_LIB)

re: fclean all

.PHONY: all clean fclean re