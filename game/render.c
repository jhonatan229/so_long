/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:01:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/11 20:51:52 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static int populate_field(t_win *win, t_sprites *spt)
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
	return (0);
}

static int put_player(t_win *win, t_sprites *spt)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (index < win->mlmap->row_map)
	{
		if (spt->px_player != 0 && spt->py_player != 0)
			break;
		while (count < win->mlmap->column_map)
		{
			if (win->mlmap->map[index][count] == 'P')
			{
					spt->px_player = count;
					spt->py_player = index;
			}
			count++;
		}
		count = 0;
		index++;
	}
	mlx_put_image_to_window(win->mlx, win->win, spt->player.img, 
							WIDTH_SPT * spt->px_player, HEIGHT_SPT * spt->py_player);
	return (0);
}

static int create_environment(t_win *win, t_sprites *spt)
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
	return (0);
}

int render_map(t_win *mlx)
{
	create_environment(mlx, mlx->mlspt);
	populate_field(mlx, mlx->mlspt);
	put_player(mlx, mlx->mlspt);
	return (0);
}