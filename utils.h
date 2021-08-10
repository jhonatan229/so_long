#ifndef UTILS_H

# define UTILS_H

# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	int		row_map;
	int		column_map;
	int		base;
}				t_map;

int	ft_read_map(char *file, t_map *map);

#endif
