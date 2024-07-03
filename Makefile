CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = lib.c
OBJS = lib.o

HOSTTYPE = ""

all: $(OBJS)
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
	gcc $(CFLAGS) $(OBJS) -shared -o libmy_lib.so

test: $(OBJS)
	$(CC) -fPIC -c $(CFLAGS) -o test $(OBJS)

