/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_the_map_playable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:10 by mdiraga           #+#    #+#             */
/*   Updated: 2023/04/02 23:53:56 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	scan_map(char **map, int row, int col, int *c)
{
	if (map[row][col] == 'E')
		return (1);
	else if (map[row][col] == '1')
		return (0);
	else if (map[row][col] == '2' || map[row][col] == 'c')
		return (0);
	else
	{
		if (map[row][col] == '0')
			map[row][col] = '2';
		else if (map[row][col] == 'C')
		{
			map[row][col] = 'c';
			c[0]--;
		}
		if ((scan_map(map, row - 1, col, c)
				|| scan_map(map, row + 1, col, c)
				|| scan_map(map, row, col - 1, c)
				|| scan_map(map, row, col + 1, c)) == 1 && c[0] == 0)
			return (1);
		else
			return (0);
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

static void	find_p_and_c(char **map, t_map_stack *t_holder, int *c)
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
			}
			else if (map[i][j] == 'C')
				c[0]++;
			j++;
		}
		i++;
	}
}

void	is_the_map_playable(char **map, t_map_stack *t_holder)
{
	int	*c;

	c = (int *)malloc(4);
	c[0] = 0;
	if (wall_control(map, t_holder->last_column))
		ft_error();
	find_p_and_c(map, t_holder, c);
	if (c[0] == 0)
		ft_error();
	t_holder->c_size = c[0];
	if (!scan_map(map, t_holder->player_y, t_holder->player_x, c))
		ft_error();
	free(c);
}
