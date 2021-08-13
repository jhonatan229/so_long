PATH_GAME = ./game/
PATH_GNL = ./gnl/
PATH_UTILS = ./utils/
PATH_MAP = ./map/
PATH_MLX = ./mlx_linux/
PATH_OBJ = objs
SRC = $(PATH_GAME)%.c $(PATH_GNL)%.c $(PATH_UTILS)%.c $(PATH_MAP)%.c errors.c

FILES = errors.c $(PATH_GAME)flow_game.c $(render.c) \
		$(PATH_GAME)init_game.c $(PATH_GAME)render.c $(PATH_GAME)reset.c $(PATH_GNL)get_next_line_utils.c $(PATH_GNL)get_next_line.c \
		$(PATH_MAP)config_map.c $(PATH_MAP)set_map.c $(PATH_UTILS)ft_bzero.c $(PATH_UTILS)ft_calloc.c \
		$(PATH_UTILS)ft_itoa.c $(PATH_UTILS)ft_strnstr.c

OBJS = $(patsubst $(SRC), $(PATH_OBJ)/%.o, $(FILES))

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Ilmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PATH_MLX)
	$(CC) $(CFLAGS) $(OBJS) -I $(PATH_MLX) -L $(PATH_MLX) so_long.c $(MLXFLAGS) $(PATH_MLX)libmlx.a -o $(NAME)

$(PATH_OBJ)/%.o:	$(SRC)
	@mkdir -p $(PATH_OBJ)
	$(CC) $(CFLAGS)  -I. -c $< -o $@

test: 
	clang -fsanitize=leak -I ./mlx_linux/ so_long.c errors.c game/reset.c game/init_game.c game/flow_game.c game/render.c map/config_map.c map/set_map.c gnl/*.c libft/ft_calloc.c  libft/ft_bzero.c libft/ft_itoa.c libft/ft_strnstr.c -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 ./mlx_linux/libmlx.a

test2: 
	clang -fsanitize=leak -I ./mlx_linux/ test2.c -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 ./mlx_linux/libmlx.a