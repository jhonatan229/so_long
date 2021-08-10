/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:31:34 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/10 00:16:47 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(void)
{
	t_map	map;
	int		return_map;
	int		index;

	index = 0;
	return_map = ft_read_map("map.xpm", &map);
	if (return_map)
	{
		//error_map(return_map);
		return (1);
	}
	while (index < map.row_map)
		free(map.map[index]);
	return (0);
}
