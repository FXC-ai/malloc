COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

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
	src/libft/ft_bzero.c \
	src/libft/ft_putstr_fd.c \
	src/libft/ft_strlen.c \
	src/libft/ft_memcpy.c \
	src/libft/ft_memcmp.c \
	src/libft/ft_putbool.c \
	src/libft/ft_putsize_t.c \
	src/libft/ft_putsize_t_fd.c \
	src/libft/ft_putnb_hex_fd.c \
	src/libft/ft_memmove.c \
	src/libft/ft_putconststr_fd.c \



OBJS := $(SRCS:src/%.c=obj/%.o)

NAME := libft_malloc.so

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

REAL_LIB := libft_malloc_$(HOSTTYPE).so

all : dirs $(NAME)

$(NAME) : $(REAL_LIB)
	@rm -f $(NAME)
	@ln -s $(REAL_LIB) $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) created\n$(COLOUR_END)"

$(REAL_LIB) : $(OBJS)
	@$(CC) $(CFLAGS) -shared $(OBJS) -o $(REAL_LIB)
	@echo "$(COLOUR_GREEN)$(REAL_LIB) created\n$(COLOUR_END)"

obj/%.o : src/%.c
	@mkdir -p $(dir $@)
	@echo "$(COLOUR_BLUE)$< => $@ in progress$(COLOUR_END)"
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@ -I inc
	@echo "$(COLOUR_GREEN)$@ created \n$(COLOUR_END)"

dirs :
	@mkdir -p obj
	@mkdir -p obj/utils
	@mkdir -p obj/libft
	@mkdir -p obj/block_management
	@mkdir -p obj/heap_management
	@mkdir -p obj/display
	@echo "$(COLOUR_GREEN)All obj/ directories created$(COLOUR_END)"

clean :
	@rm -f $(OBJS)
	@echo "$(COLOUR_RED)$(OBJS) deleted\n$(COLOUR_RED)"

fclean : clean
	@rm -f $(NAME) $(REAL_LIB)
	@echo "$(COLOUR_RED)$(NAME) $(REAL_LIB) deleted\n$(COLOUR_RED)"

re : fclean all

.PHONY: all clean fclean re dirs