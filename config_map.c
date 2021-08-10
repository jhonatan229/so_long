/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:40:39 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/10 16:06:23 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

static int	verify_number_column(char c, t_map *map)
{
	if (c != '\n' && map->row_map == 0)
		map->base++;
	if (c != '\n')
		map->column_map++;
	if (c == '\n')
	{
		//printf("base: %i, coumns %i\n", map->base, map->column_map);
		if (map->base != map->column_map)
			return (-3);
		else
			map->column_map = 0;
		map->row_map++;
	}
	return (0);
}

static int	count_lines(char *files, t_map *map)
{
	int		fd;
	char	c;
	int		rslt;

	fd = open(files, O_RDONLY);
	if (fd < 0)
		return (fd);
	rslt = read(fd, &c, 1);
	if (rslt < 0)
		return (-1);
	while (rslt > 0)
	{
		if (verify_number_column(c, map) < 0)
			return (-3);
		rslt = read(fd, &c, 1);
	}
	close(fd);
	if (map->base != map->column_map)
		return (-3);
	if (map->column_map < 3 || map->row_map < 3)
		return (-3);
	map->row_map++;
	//printf("lines %i\n", map->row_map);
	return (0);
}

int	ft_read_map(char *file, t_map *map)
{
	int		count;
	int		index;
	int		fd;
	char	*line;

	index = 0;
	map->column_map = 0;
	map->row_map = 0;
	map->base = 0;
	count = count_lines(file, map);
	printf("count: %i\n", count);
	if (count < 0)
		return (count * -1);
	fd = open(file, O_RDONLY);
	map->map = ft_calloc(map->column_map * map->row_map + 1, sizeof(char));
	index = get_next_line(fd, &map->map[index++]);
	while (index < map->row_map)
		get_next_line(fd, &map->map[index++]);
	//index = 0;
	//while (index < map->row_map)
	//{
	//	printf("line %i:%10s\n", index + 1, map->map[index]);
	//	index++;
	//}		
	return (0);
}
