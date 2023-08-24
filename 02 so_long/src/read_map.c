/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:44 by mdiraga           #+#    #+#             */
/*   Updated: 2023/04/01 15:04:19 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_utils(t_map_stack *t_holder, char **map, char *line)
{
	int	i;

	i = 0;
	while (i <= t_holder->last_column)
		free(map[i++]);
	free(map);
	free(line);
	ft_error();
}

static void	map_control(char *line, char **map, t_map_stack *t_holder)
{
	static int	last_line = -2;
	int			i;

	if (line[(int)ft_strlen(line) - 1] != '\n')
		last_line--;
	if (last_line != (int)ft_strlen(line) && last_line != -2)
		free_utils(t_holder, map, line);
	i = 0;
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
		line = get_next_line(t_holder->fd);
		if (!line)
			break ;
		map_control(line, map, t_holder);
		map[i++] = line;
		t_holder->last_column = i - 1;
	}
	if (!t_holder->e || !t_holder->p)
		ft_error();
	return (map);
}
