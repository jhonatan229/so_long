/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:01:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/12 17:24:11 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void print_image(t_win *mlx, t_img *img, int count, int index)
{
	if (count < 0 || index < 0)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
}

static void create_environment(t_win *win, t_img *p_spt, int count, int index)
{
	while (index < win->mlmap->row_map)
	{
		while (count < win->mlmap->column_map)
		{
			if (win->mlmap->map[index][count] == '0')
				print_image(win, &win->mlspt->floor, count, index);
			else if (win->mlmap->map[index][count] == '1')
				print_image(win, &win->mlspt->wall, count, index);
			else if (win->mlmap->map[index][count] == 'C')
				print_image(win, &win->mlspt->item, count, index);
			else if (win->mlmap->map[index][count] == 'E')
				print_image(win, &win->mlspt->door, count, index);
			else if (win->mlmap->map[index][count] == 'H')
				print_image(win, &win->mlspt->hostil, count, index);
			else if (win->mlmap->map[index][count] == 'P')
			{
				win->mlspt->player.py_player = index;
				win->mlspt->player.px_player = count;
				print_image(win, p_spt, count, index);
			}	
			count++;
		}
		count = 0;
		index++;
	}
}

int render_map(t_win *mlx, int p_direction)
{
	if (p_direction == 1)
		create_environment(mlx, &mlx->mlspt->player.down, 0, 0);
	else if (p_direction == 2)
		create_environment(mlx, &mlx->mlspt->player.up, 0, 0);
	else if (p_direction == 3)
		create_environment(mlx, &mlx->mlspt->player.left, 0, 0);
	else if (p_direction == 4)
		create_environment(mlx, &mlx->mlspt->player.rigth, 0, 0);
	return (0);
}