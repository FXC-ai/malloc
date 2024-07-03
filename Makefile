CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = lib.c
OBJS = lib.o

HOSTTYPE = "pp"

all: $(OBJS)
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
	gcc $(CFLAGS) $(OBJS) -shared -o lib_$(HOSTTYPE)_.so

test: $(OBJS)
	$(CC) -fPIC -c $(CFLAGS) -o test $(OBJS)

