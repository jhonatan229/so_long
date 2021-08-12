/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:04:53 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/11 21:16:54 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	verify_pos(t_win *mlx, int x, int y)
{
	if (mlx->mlmap->map[y][x] == '0' || mlx->mlmap->map[y][x] == 'C')
	{
		mlx->mlspt->px_player = x;
		mlx->mlspt->py_player = y;
		mlx->mlmap->map[y][x] = '0';
	}
}

int	actions(int keycode, t_win *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	int	x = mlx->mlspt->px_player;
	int	y = mlx->mlspt->py_player;
	printf("press: %i\n", keycode);
	if (keycode == 65307)
	{
		free_map(mlx->mlmap);
		exit(0);
	}
	if (keycode == 97)
		x--;//img->x -= 20;
	else if (keycode == 115)
		y++;//img->y -= 20;
	else if (keycode == 119)
		y--;//img->y += 20;
	else if (keycode == 100)
		x++;//img->x += 20;
	verify_pos(mlx, x, y);
	render_map(mlx);
	return (0);
}
