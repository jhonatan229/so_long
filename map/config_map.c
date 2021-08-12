/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:29:14 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/11 19:30:51 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void init_var_map(t_map *map)
{
	map->column_map = 0;
	map->row_map = 0;
	map->base = 0;
	map->player_pos = 0;
	map->items = 0;
	map->exits = 0;
	map->outsider = 0;
}

int free_map(t_map *map)
{
	int index;

	index = 0;
	while (index < map->row_map)
	{
		free(map->map[index]);
		index++;
	}
	free(map->map);
	return (0);
}
