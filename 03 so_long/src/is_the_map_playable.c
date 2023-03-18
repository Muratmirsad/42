#include "../include/so_long.h"

static int	is_e_here(char **map, int i, int j)
{
	if (map[i][j - 1] == 'E'
		|| map[i - 1][j] == 'E'
		|| map[i][j + 1] == 'E'
		|| map[i + 1][j + 1] == 'E')
		return (1);
	return (0);
}

static void	scan_map(char **map, int i, int j, int *key)
{
	if (is_e_here(map, i, j))
		*key = 1;
	if (map[i][j - 1] != '1' && map[i][j - 1] != '2' && !*key)
	{
		map[i][j - 1] = '2';
		scan_map(map, i, j - 1, key);
	}
	if (map[i - 1][j] != '1' && map[i - 1][j] != '2' && !*key)
	{
		map[i - 1][j] = '2';
		scan_map(map, i - 1, j, key);
	}
	if (map[i][j + 1] != '1' && map[i][j + 1] != '2' && !*key)
	{
		map[i][j + 1] = '2';
		scan_map(map, i, j + 1, key);
	}
	if (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '2' && !*key)
	{
		map[i + 1][j + 1] = '2';
		scan_map(map, i + 1, j + 1, key);
	}
}

static int	wall_control(char **map, int last_column)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (1);
		else if (map[last_column][i] != '1')
			return (1);
		i++;
	}
	i--;
	j = 0;
	while (j <= last_column)
	{
		if (map[j][0] != '1')
			return (1);
		else if (map[j][i] != '1')
			return (1);
		j++;
	}
	return (0);
}

static void	find_player(char **map, t_map_stack *t_holder)
{
	int	i;
	int	j;

	i = 1;
	while (i <= t_holder->last_column)
	{
		j = 1;
		while (map[i][j] != 0)
		{
			if (map[i][j] == 'P')
			{
				t_holder->player_x = j;
				t_holder->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	is_the_map_playable(char **map, t_map_stack *t_holder)
{
	int	key;

	key = 0;
	if (wall_control(map, t_holder->last_column))
		ft_error();
	find_player(map, t_holder);
	scan_map(map, t_holder->player_y, t_holder->player_x, &key);
	if (!key)
		ft_error();
}
