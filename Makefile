NAME = mlx.a

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -I./mlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -L./mlx_linux -l./mlx_linux -L./mlx_linux -I./mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

test: 
	clang -fsanitize=leak -I ./mlx_linux/ so_long.c config_map.c gnl/*.c libft/ft_calloc.c  libft/ft_bzero.c -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 ./mlx_linux/libmlx.a

test2: 
	clang -fsanitise=leak -I ./mlx_linux/ test2.c -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 ./mlx_linux/libmlx.a