FILES = *.c

NAME = libft.a

CC = clang

FLAGS = -Wall -Wextra -Werror

OBJ = $(FILES:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ):		$(FILES)
	$(CC) $(FLAGS) -c $(FILES)

comp: 
	$(CC) $(FLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f ${NAME}

re: fclean all