HEADIR = includes

SRCS 	= ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_isascii.c \
		ft_striteri.c \
		ft_strlcpy.c \
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
		ft_putbool.c \
		ft_putsize_t.c \
		ft_putsize_t_fd.c \
		ft_putnb_hex_fd.c \
		ft_putconststr_fd.c


OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADIR}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
	
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re