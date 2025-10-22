COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS := malloc.c \
		get_heap_group_from_block_size.c \
		display_nb.c \
		display_hex.c \
		create_block.c \
		create_heap.c \
        get_heap_size_from_heap_group.c \
		add_heap_front.c \
		display_t_heap.c \
		display_t_heap_chain.c \
		display_t_heap_group.c

OBJS := $(SRCS:%.c=obj/%.o)

NAME := libft_malloc.so

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

REAL_LIB := libft_malloc_$(HOSTTYPE).so

all : $(NAME)

$(NAME) : $(REAL_LIB)
	@rm -f $(NAME)
	@ln -s $(REAL_LIB) $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) created\n$(COLOUR_END)"

$(REAL_LIB) : $(OBJS)
	@$(CC) $(CFLAGS) -shared $(OBJS) -o $(REAL_LIB)
	@echo "$(COLOUR_GREEN)$(REAL_LIB) created\n$(COLOUR_END)"

obj/%.o : src/%.c
	@echo "$(COLOUR_BLUE)$< => $@ in progress$(COLOUR_END)"
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@ -I inc
	@echo "$(COLOUR_GREEN)$@ created \n$(COLOUR_END)"

clean :
	@rm -f $(OBJS)
	@echo "$(COLOUR_RED)$(OBJS) deleted\n$(COLOUR_RED)"

fclean : clean
	@rm -f $(NAME) $(REAL_LIB)
	@echo "$(COLOUR_RED)$(NAME) $(REAL_LIB) deleted\n$(COLOUR_RED)"

re : fclean all

dev :
	gcc $(FLAGS) -fsanitize=address src/$(SRCS)

.PHONY: all clean fclean re