CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c
OBJS = main.o

all: test

test: $(OBJS)
	$(CC) $(CFLAGS) -o test $(OBJS)
