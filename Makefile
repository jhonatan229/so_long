NAME = mlx.a

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -I./mlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -L./mlx_linux -l./mlx_linux -L./mlx_linux -I./mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

test: 
	clang -I ./mlx_linux/ test.c -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 ./mlx_linux/libmlx.a

test2: 
	clang -I ./mlx_linux/ test2.c -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 ./mlx_linux/libmlx.a