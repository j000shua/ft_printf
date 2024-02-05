NAME = libftprintf.a

SRC = ft_printf.c \
      string_utils.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

${NAME}:	${OBJ}
	ar -rcs ${NAME} ${OBJ}

all:	${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
