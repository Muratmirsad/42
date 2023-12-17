/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:59:43 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/15 15:30:44 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rgb(t_data *map_data)
{
	if (map_data->c_red < 0 || map_data->c_red > 255
		|| map_data->c_green < 0 || map_data->c_green > 255
		|| map_data->c_blue < 0 || map_data->c_blue > 255
		|| map_data->f_red < 0 || map_data->f_red > 255
		|| map_data->f_green < 0 || map_data->f_green > 255
		|| map_data->c_blue < 0 || map_data->f_blue > 255)
		wrong_map_exit(map_data, 21);
}

void	check_map_characters(t_data *map_data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((!is_it_ws(map[i][j])) && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != 'S')
				wrong_map_exit(map_data, 25);
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S')
			{
				if (map_data->direction == '0')
					map_data->direction = map[i][j];
				else
					wrong_map_exit(map_data, 26);
			}
		}
	}
	if (map_data->direction == '0')
		wrong_map_exit(map_data, 27);
}

void	check_horizantal(t_data *map_data, char **map, int i, int j)
{
	int	backup;

	backup = j;
	while (map[i][j] != '1')
	{
		if (is_it_ws(map[i][j]) || map[i][j] == '\0')
			wrong_map_exit(map_data, 28);
		j++;
	}
	j = backup;
	while (map[i][j] != '1')
	{
		if (i == 0 || is_it_ws(map[i][j]))
			wrong_map_exit(map_data, 28);
		j--;
	}
}

void	check_vertical(t_data *map_data, char **map, int i, size_t j)
{
	int	backup;

	backup = i;
	while (map[i][j] != '1')
	{
		if (!map[i + 1] || ft_strlen(map[i + 1]) < j || is_it_ws(map[i][j]))
			wrong_map_exit(map_data, 28);
		i++;
	}
	i = backup;
	while (map[i][j] != '1')
	{
		if (i == 0 || ft_strlen(map[i - 1]) < j)
			wrong_map_exit(map_data, 28);
		if (is_it_ws(map[i][j]))
			wrong_map_exit(map_data, 28);
		i--;
	}
}

void	check_borders(t_data *map_data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == map_data->direction)
			{
				check_vertical(map_data, map, i, j);
				check_horizantal(map_data, map, i, j);
			}
		}
	}
}
