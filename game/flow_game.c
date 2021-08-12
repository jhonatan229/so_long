/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:04:53 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/12 18:25:28 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	verify_pos(t_win *mlx, int x, int y, int mark)
{
	if (mlx->mlmap->map[y][x] == '0' || mlx->mlmap->map[y][x] == 'C' || 
										mlx->mlmap->map[y][x] == 'P')
	{
		if (mlx->mlmap->map[y][x] == 'C')
			mlx->mlmap->items--;
		mlx->mlmap->map[mlx->mlspt->player.py_player][mlx->mlspt->player.px_player] = '0';
		mlx->mlmap->map[y][x] = 'P';
		if (mark == 1)
			mlx->mlspt->player.steps++;
	}
	else if (mlx->mlmap->map[y][x] == 'E' && mlx->mlmap->items == 0)
	{
		mlx->mlmap->map[mlx->mlspt->player.py_player][mlx->mlspt->player.px_player] = '0';
		mlx->mlspt->player.px_player = -1;
		mlx->mlspt->player.py_player = -1;
	}
	else if (mlx->mlmap->map[y][x] == 'H')
		reset_game(mlx);
}

static int check_key(int *x, int *y, int keycode, t_player *player)
{
	if (keycode == 97)
	{
		*x -= 1;//img->x -= 20;
		player->spt_move = 3;
	}
	else if (keycode == 115)
	{
		*y += 1;//img->y -= 20;
		player->spt_move = 1;
	}
	else if (keycode == 119)
	{
		*y -= 1;//img->y += 20;
		player->spt_move = 2;
	}
	else if (keycode == 100)
	{
		*x += 1;//img->x += 20;
		player->spt_move = 4;
	}
	else
		return (0);
	return (1);
}

int	actions(int keycode, t_win *mlx)
{
	int mark;
	
	int	x = mlx->mlspt->player.px_player;
	int	y = mlx->mlspt->player.py_player;
	if (keycode == 65307)
	{
		free_map(mlx->mlmap);
		exit(0);
	}
	else if (keycode == 114)
		reset_game(mlx);
	else if (mlx->mlspt->player.py_player > 0 && mlx->mlspt->player.px_player > 0)
	{
		mark = check_key(&x, &y, keycode, &mlx->mlspt->player);
		verify_pos(mlx, x, y, mark);
	}
	return (0);
}
