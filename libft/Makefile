COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRCS 	= ft_putnbr_fd.c \
		  ft_putendl_fd.c \
		  ft_putstr_fd.c \
		  ft_putchar_fd.c \
		  ft_striteri.c \
		  ft_strmapi.c \
		  ft_isascii.c \
		  ft_itoa.c \
		  ft_strtrim.c \
		  ft_strjoin.c \
		  ft_substr.c \
		  ft_strdup.c \
		  ft_calloc.c \
		  ft_strlcpy.c \
		  ft_split.c \
		  ft_strlcat.c \
		  ft_tolower.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strchr.c \
		  ft_toupper.c \
		  ft_isprint.c \
		  ft_isalnum.c \
		  ft_isdigit.c \
		  ft_isalpha.c \
		  ft_memcmp.c \
		  ft_memchr.c \
		  ft_memmove.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_strlen.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_memset.c \
		  ft_split.c \
		  ft_strdup.c \
		  ft_strjoin.c

OBJDIR = obj

OBJS = $(addprefix ${OBJDIR}/, $(SRCS:.c=.o))

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${OBJDIR}/%.o: %.c 
			${CC} ${CFLAGS} -c $< -o $@
			@echo "$(COLOUR_GREEN)$@ created$(COLOUR_END)"

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
	
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

tester:     
			${CC} ${CFLAGS} -I. tests/tests.c -L. -lft -o test_exec
			@./test_exec

unittest:
			${CC} ${CFLAGS} tests/tests.c -o unittest_exec
			@./unittest_exec

.PHONY:		all clean fclean re tester