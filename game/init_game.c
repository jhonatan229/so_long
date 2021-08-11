/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:03:38 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/11 13:13:52 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	ft_start_game(t_win *mlx, t_sprites *spt)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "SO_LONG");
	render_map(mlx);
	mlx_key_hook(mlx->win, move_player, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
