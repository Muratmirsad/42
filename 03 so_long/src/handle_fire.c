#include "../include/so_long.h"

void	fire_handle(char **map, t_map_stack *t_holder)
{
	int	x;
	int	y;

	while (y < t_holder->last_column)
	{
		x = 1;
		while (x < (int)ft_strlen(map[y]))
		{
			if (map[y][x] == 'x')
			{
				map[y - 1][x] = 'x';
				map[y][x + 1] = 'x';
				map[y + 1][x] = 'x';
				map[y][x - 1] = 'x';
			}
			x++;
		}
		y++;
	}
}
