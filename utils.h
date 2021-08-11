#ifndef UTILS_H

# define UTILS_H
# define WIDTH_SPT 50
# define HEIGHT_SPT 50

# include "mlx_linux/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	int		row_map;
	int		column_map;
	int		base;
	int		player_pos;
	int		items;
	int		exits;
	int		outsider;
}				t_map;

typedef struct	s_win {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_win;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_sprites{
	t_img	wall;
	t_img	floor;
	t_img	door;
	t_img	item;
	t_img	player;
	int		px_player;
	int		py_player;
}				t_sprites;

int	ft_read_map(char *file, t_map *map);
int	ft_start_game(t_win *mlx, t_map *map, t_sprites *spt);

#endif
