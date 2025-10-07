COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS := ft_malloc.c heap_manager_tools.c display_tools.c block_manager_tools.c
OBJS := $(SRCS:.c=.o)

NAME := libft_malloc.so

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

REAL_LIB := libft_malloc_$(HOSTTYPE).so

all : $(NAME)

$(NAME) : $(REAL_LIB)
	@ln -s $(REAL_LIB) $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) created$(COLOUR_END)"

$(REAL_LIB) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -shared -o $(REAL_LIB)
	@echo "$(COLOUR_GREEN)$(REAL_LIB) created$(COLOUR_END)"

%.o : %.c
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "$(COLOUR_GREEN).o files created$(COLOUR_END)"

clean :
	@rm -f $(OBJS)
	@echo "$(COLOUR_RED).o files deleted$(COLOUR_RED)"

fclean : clean
	@rm -f $(NAME) $(REAL_LIB)
	@echo "$(COLOUR_RED)$(NAME) $(REAL_LIB) deleted$(COLOUR_RED)"

re : fclean all

dev :
	gcc $(FLAGS) -fsanitize=address $(SRCS)

.PHONY: all clean fclean re