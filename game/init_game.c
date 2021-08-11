/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:03:38 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/10 23:04:33 by jestevam         ###   ########.fr       */
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

static int populate_field(t_map *map, t_win *win)
{
	t_img	door;
	t_img	item;
	int		index;
	int		count;

	index = 0;
	count = 0;
	init_image(&door, "sprites/door.xpm", win);
	init_image(&item, "sprites/item.xpm", win);
	while (index < map->row_map)
	{
		while (count < map->column_map)
		{
			if (map->map[index][count] == 'C' || map->map[index][count] == 'c')
				mlx_put_image_to_window(win->mlx, win->win, item.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			else if (map->map[index][count] == 'E' || map->map[index][count] == 'e')
				mlx_put_image_to_window(win->mlx, win->win, door.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			count++;
		}
		count = 0;
		index++;
	}
	return (0);
}

static int create_environment(t_map *map, t_win *win)
{
	t_img	wall;
	t_img 	floor;
	int		index;
	int		count;

	index = 0;
	count = 0;
	init_image(&wall, "sprites/wall.xpm", win);
	init_image(&floor, "sprites/floor.xpm", win);
	while (index < map->row_map)
	{
		while (count < map->column_map)
		{
			mlx_put_image_to_window(win->mlx, win->win, floor.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			if (map->map[index][count] == '1')
				mlx_put_image_to_window(win->mlx, win->win, wall.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			count++;
		}
		count = 0;
		index++;
	}
	return (0);
}

int	ft_start_game(t_win *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "SO_LONG");
	create_environment(map, mlx);
	populate_field(map, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
