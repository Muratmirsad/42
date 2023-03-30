#include "../include/so_long.h"

static int	char_control(char c, t_map_stack *t_holder)
{
	if (c == 'E')
		t_holder->e++;
	else if (c == 'P')
		t_holder->p++;
	if (t_holder->e > 1 || t_holder->p > 1)
		return (0);
	else if (c == '0'
		|| c == '1'
		|| c == 'C'
		|| c == 'E'
		|| c == 'P'
		|| c == '\n')
		return (1);
	return (0);
}

static void	map_control(char *line, char **map, t_map_stack *t_holder)
{
	static int	last_line = -1;
	int			i;

	i = 0;
	if (last_line != (int)ft_strlen(line) && last_line != -1)
	{
		while (i <= t_holder->last_column)
			free(map[i++]);
		free(map);
		free(line);
		ft_error();
	}
	while (line[i])
	{
		if (!char_control(line[i++], t_holder))
		{
			i = 0;
			while (i <= t_holder->last_column)
				free(map[i++]);
			free(map);
			free(line);
			ft_error();
		}
	}
	last_line = i;
}

char	**read_map(t_map_stack *t_holder)
{
	char		**map;
	char		*line;
	int			i;

	i = 0;
	t_holder->e = 0;
	t_holder->p = 0;
	map = (char **)malloc(sizeof(char *) * 16);
	while (1)
	{
		if (!(line = get_next_line(t_holder->fd)))
			break ;
		map_control(line, map, t_holder);
		map[i++] = line;
		t_holder->last_column = i - 1;
	}
	if (!t_holder->e || !t_holder->p)
		ft_error();
	return (map);
}
