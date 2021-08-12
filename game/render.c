/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:01:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/12 02:30:19 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void populate_field(t_win *win, t_sprites *spt)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (index < win->mlmap->row_map)
	{
		while (count < win->mlmap->column_map)
		{
			if (win->mlmap->map[index][count] == 'C')
				mlx_put_image_to_window(win->mlx, win->win, spt->item.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			else if (win->mlmap->map[index][count] == 'E')
				mlx_put_image_to_window(win->mlx, win->win, spt->door.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			count++;
		}
		count = 0;
		index++;
	}
}

static void put_player(t_win *win, t_img *spt, t_player *player)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	if (player->px_player == -1 && player->py_player == -1)
		return ;
	while (index < win->mlmap->row_map)
	{
		if (player->px_player != 0 && player->py_player != 0)
			break;
		while (count < win->mlmap->column_map)
		{
			if (win->mlmap->map[index][count] == 'P')
			{
					player->px_player = count;
					player->py_player = index;
			}
			count++;
		}
		count = 0;
		index++;
	}
	mlx_put_image_to_window(win->mlx, win->win, spt->img, 
				WIDTH_SPT * player->px_player, HEIGHT_SPT * player->py_player);
}

static void create_environment(t_win *win, t_sprites *spt)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (index < win->mlmap->row_map)
	{
		while (count < win->mlmap->column_map)
		{
			mlx_put_image_to_window(win->mlx, win->win, spt->floor.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			if (win->mlmap->map[index][count] == '1')
				mlx_put_image_to_window(win->mlx, win->win, spt->wall.img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
			count++;
		}
		count = 0;
		index++;
	}
}

int render_map(t_win *mlx, int p_direction)
{
	create_environment(mlx, mlx->mlspt);
	populate_field(mlx, mlx->mlspt);
	if (p_direction == 1)
		put_player(mlx, &mlx->mlspt->player.down, &mlx->mlspt->player);
	else if (p_direction == 2)
		put_player(mlx, &mlx->mlspt->player.up, &mlx->mlspt->player);
	else if (p_direction == 3)
		put_player(mlx, &mlx->mlspt->player.left, &mlx->mlspt->player);
	else if (p_direction == 4)
		put_player(mlx, &mlx->mlspt->player.rigth, &mlx->mlspt->player);
	return (0);
}