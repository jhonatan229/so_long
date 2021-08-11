/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:03:38 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/10 23:38:35 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static int init_image(t_img *img, char *file, t_win *win)
{
	int	x;
	int	y;

	x = WIDTH_SPT;
	y = HEIGHT_SPT;
	img->img = mlx_xpm_file_to_image(win->mlx, file, &x, &y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	 							&img->line_length, &img->endian);
	return (0);
}

static int populate_field(t_map *map, t_win *win, t_sprites *spt)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	init_image(&spt->door, "sprites/door.xpm", win);
	init_image(&spt->item, "sprites/item.xpm", win);
	while (index < map->row_map)
	{
		while (count < map->column_map)
		{
			if (map->map[index][count] == 'C' || map->map[index][count] == 'c')
				mlx_put_image_to_window(win->mlx, win->win, spt->item.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			else if (map->map[index][count] == 'E' || map->map[index][count] == 'e')
				mlx_put_image_to_window(win->mlx, win->win, spt->door.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			count++;
		}
		count = 0;
		index++;
	}
	return (0);
}

static int put_player(t_map *map, t_win *win, t_sprites *spt)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	init_image(&spt->player, "sprites/player.xpm", win);
	while (index < map->row_map)
	{
		while (count < map->column_map)
		{
			if (map->map[index][count] == 'p' || map->map[index][count] == 'P')
			{
				spt->px_player = count;
				spt->py_player = index;
				mlx_put_image_to_window(win->mlx, win->win, spt->player.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			}
			count++;
		}
		count = 0;
		index++;
	}
	return (0);
}

static int create_environment(t_map *map, t_win *win, t_sprites *spt)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	init_image(&spt->wall, "sprites/wall.xpm", win);
	init_image(&spt->floor, "sprites/floor.xpm", win);
	while (index < map->row_map)
	{
		while (count < map->column_map)
		{
			mlx_put_image_to_window(win->mlx, win->win, spt->floor.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			if (map->map[index][count] == '1')
				mlx_put_image_to_window(win->mlx, win->win, spt->wall.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			count++;
		}
		count = 0;
		index++;
	}
	return (0);
}

int	ft_start_game(t_win *mlx, t_map *map, t_sprites *spt)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "SO_LONG");
	create_environment(map, mlx, spt);
	populate_field(map, mlx, spt);
	put_player(map, mlx, spt);
	mlx_loop(mlx->mlx);
	return (0);
}
