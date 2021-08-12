/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:03:38 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/11 21:15:54 by jestevam         ###   ########.fr       */
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

static void init_img(t_win *mlx)
{
	init_image(&mlx->mlspt->door, "sprites/door.xpm", mlx);
	init_image(&mlx->mlspt->item, "sprites/item.xpm", mlx);
	init_image(&mlx->mlspt->player, "sprites/player.xpm", mlx);
	init_image(&mlx->mlspt->wall, "sprites/wall.xpm", mlx);
	init_image(&mlx->mlspt->floor, "sprites/floor.xpm", mlx);
}


int	ft_start_game(t_win *mlx, t_sprites *spt)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "SO_LONG");
	init_img(mlx);
	render_map(mlx);
	mlx_key_hook(mlx->win, actions, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
