/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:01:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/12 15:36:45 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

//static void put_player(t_win *win, t_img *spt, t_player *player)
//{
//	int		index;
//	int		count;
//
//	index = 0;
//	count = 0;
//	if (player->px_player == -1 && player->py_player == -1)
//		return ;
//	while (index < win->mlmap->row_map)
//	{
//		if (player->px_player != 0 && player->py_player != 0)
//			break;
//		while (count < win->mlmap->column_map)
//		{
//			if (win->mlmap->map[index][count] == 'P')
//			{
//					player->px_player = count;
//					player->py_player = index;
//					win->mlmap->map[index][count] = '0';
//			}
//			count++;
//		}
//		count = 0;
//		index++;
//	}
//	mlx_put_image_to_window(win->mlx, win->win, spt->img, 
//				WIDTH_SPT * player->px_player, HEIGHT_SPT * player->py_player);
//}

static void print_image(t_win *mlx, t_img *img, int count, int index)
{
	if (count < 0 || index < 0)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 
								WIDTH_SPT * count, HEIGHT_SPT * index);
}

static void create_environment(t_win *win, t_sprites *spt, int count, int index)
{
	while (index < win->mlmap->row_map)
	{
		while (count < win->mlmap->column_map)
		{
			if (win->mlmap->map[index][count] == '0')
				print_image(win, &spt->floor, count, index);
			else if (win->mlmap->map[index][count] == '1')
				print_image(win, &spt->wall, count, index);
			else if (win->mlmap->map[index][count] == 'C')
				print_image(win, &spt->item, count, index);
			else if (win->mlmap->map[index][count] == 'E')
				print_image(win, &spt->door, count, index);
			else if (win->mlmap->map[index][count] == 'P')
			{
				spt->player.px_player = count;
				spt->player.py_player = index;
				win->mlmap->map[index][count] = '0';
			}
					count++;
		}
		count = 0;
		index++;
	}
}

int render_map(t_win *mlx, int p_direction)
{
	create_environment(mlx, mlx->mlspt, 0, 0);
	if (p_direction == 1)
		print_image(mlx, &mlx->mlspt->player.down, mlx->mlspt->player.px_player, 
												mlx->mlspt->player.py_player);
	else if (p_direction == 2)
		print_image(mlx, &mlx->mlspt->player.up, mlx->mlspt->player.px_player, 
												mlx->mlspt->player.py_player);
	else if (p_direction == 3)
		print_image(mlx, &mlx->mlspt->player.left, mlx->mlspt->player.px_player, 
												mlx->mlspt->player.py_player);
	else if (p_direction == 4)
		print_image(mlx, &mlx->mlspt->player.rigth, mlx->mlspt->player.px_player, 
												mlx->mlspt->player.py_player);
	return (0);
}