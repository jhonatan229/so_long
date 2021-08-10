/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:31:34 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/10 17:21:02 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void init_var_map(t_map *map)
{
	map->column_map = 0;
	map->row_map = 0;
	map->base = 0;
	map->player_pos = 0;
	map->items = 0;
	map->exits = 0;
	map->outsider = 0;
}

int	main(void)
{
	t_map	map;
	int		return_map;
	int		index;

	index = 0;
	init_var_map(&map);
	return_map = ft_read_map("map.ber", &map);
	if (return_map)
	{
		//error_map(return_map);
		while (index < map.row_map)
		{
			free(map.map[index]);
			index++;
		}
		free(map.map);
		return (1);
	}
	while (index < map.row_map)
	{
		free(map.map[index]);
		index++;
	}
	free(map.map);
	return (0);
}
