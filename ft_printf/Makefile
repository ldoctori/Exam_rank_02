NAME = libftprintf.a

SOURCE_FILES = ft_printf.c 

HEADER = ft_printf.h

FLAGS = -c -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${SOURCE_FILES} ${HEADER}
	gcc $(FLAGS) $(SOURCE_FILES)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o 

fclean: clean
	rm -f $(NAME) 

re: fclean all

bonus: re

.PHONY:	all clean fclean re bonus
