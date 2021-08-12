/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:04:53 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/12 02:33:28 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	verify_pos(t_win *mlx, int x, int y)
{
	if (mlx->mlmap->map[y][x] == '0' || mlx->mlmap->map[y][x] == 'C' || 
										mlx->mlmap->map[y][x] == 'P')
	{
		mlx->mlspt->player.px_player = x;
		mlx->mlspt->player.py_player = y;
		if (mlx->mlmap->map[y][x] == 'C')
		{
			mlx->mlmap->map[y][x] = '0';
			mlx->mlmap->items--;
		}
		mlx->mlspt->player.steps++;
		printf("steps: %i\n", mlx->mlspt->player.steps);
	}
	if (mlx->mlmap->map[y][x] == 'E' && mlx->mlmap->items == 0)
	{
		mlx->mlspt->player.px_player = -1;
		mlx->mlspt->player.py_player = -1;
	}

}

static int check_key(int *x, int *y, int keycode)
{
	if (keycode == 97)
	{
		*x -= 1;//img->x -= 20;
		return (3);
	}
	else if (keycode == 115)
	{
		*y += 1;//img->y -= 20;
		return (1);
	}
	else if (keycode == 119)
	{
		*y -= 1;//img->y += 20;
		return (2);
	}
	else if (keycode == 100)
	{
		*x += 1;//img->x += 20;
		return (4);
	}
	return (1);
}

int	actions(int keycode, t_win *mlx)
{
	int p_direction;

	p_direction = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	int	x = mlx->mlspt->player.px_player;
	int	y = mlx->mlspt->player.py_player;
	if (keycode == 65307)
	{
		free_map(mlx->mlmap);
		exit(0);
	}
	if (mlx->mlspt->player.py_player > 0 && mlx->mlspt->player.px_player > 0)
	{
		p_direction = check_key(&x, &y, keycode);
		verify_pos(mlx, x, y);
	}
	render_map(mlx, p_direction);
	return (0);
}
