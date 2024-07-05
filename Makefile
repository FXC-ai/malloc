CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS := lib.c
OBJS := lib.o

NAME = libft_malloc.so

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all : $(NAME)

$(NAME) : libft_malloc_$(HOSTTYPE).so
	@echo Create libft_malloc.so
	ln -s libft_malloc_$(HOSTTYPE).so $(NAME)

libft_malloc_$(HOSTTYPE).so : $(OBJS)
	@echo Create libft_malloc_$(HOSTTYPE).so
	$(CC) $(CFLAGS) $(OBJS) -shared -o libft_malloc_$(HOSTTYPE).so

$(OBJS) : $(SRCS)
	@echo "Create .o files"
	$(CC) $(CFLAGS) -fPIC -c $(SRCS) -o $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all


