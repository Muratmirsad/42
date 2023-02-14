#include "../include/so_long.h"

int	char_control(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'C'
		|| c == 'E'
		|| c == 'P')
		return (1);
	return (0);
}

void	map_control(char *line)
{
	static int	last_line = -1;
	int	i;

	i = 0;
	if (last_line != (sizeof(line) - 1) && last_line != -1)
		ft_error();
	while (line[i])
	{
		if (!char_control(line[i++]))
			ft_error();
	}
	last_line = i;
}

void	read_map(int fd)
{
	char	*map;

	while(1)
	{
		map = get_next_line(fd);
		map_control(map);
	}
}