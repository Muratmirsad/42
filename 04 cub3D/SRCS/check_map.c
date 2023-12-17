/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:12:39 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/15 16:10:15 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_line_count(t_data *map_data)
{
	int		fd;
	int		count;
	char	*line;

	map_data->map_path = ft_strdup(map_data->map_name);
	if (!map_data->map_path)
		allocation_exit(map_data);
	fd = open(map_data->map_path, O_RDONLY);
	if (fd < 0)
		wrong_argument_exit(map_data, 11);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (count);
}

void	check_empty_lines(t_data *map_data, char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if ((!ft_strnstr(map[i], "WE", ft_strlen(map[i])))
			&& (!ft_strnstr(map[i], "NO", ft_strlen(map[i])))
			&& (!ft_strnstr(map[i], "SO", ft_strlen(map[i])))
			&& (!ft_strnstr(map[i], "EA", ft_strlen(map[i])))
			&& (!ft_strnstr(map[i], "F", ft_strlen(map[i])))
			&& (!ft_strnstr(map[i], "C", ft_strlen(map[i])))
			&& (!ft_strnstr(map[i], "1", ft_strlen(map[i])))
			&& (map[i][0] != '\n'))
			wrong_map_exit(map_data, 24);
	}
}

void	get_map(t_data *map_data)
{
	int	i;
	int	fd;

	map_data->line_count = get_line_count(map_data);
	map_data->whole_map = malloc(sizeof(char *) * (map_data->line_count + 1));
	if (!(map_data->whole_map))
		allocation_exit(map_data);
	fd = open(map_data->map_path, O_RDONLY);
	if (fd < 0)
		wrong_argument_exit(map_data, 11);
	i = -1;
	while (++i < map_data->line_count)
		map_data->whole_map[i] = get_next_line(fd);
	map_data->whole_map[i] = NULL;
	check_empty_lines(map_data, map_data->whole_map);
	map_data->direction = '0';
}

void	check_map(t_data *map_data)
{
	int	i;

	get_map(map_data);
	clear_map(map_data);
	check_rgb(map_data);
	check_map_characters(map_data, map_data->map);
	check_borders(map_data, map_data->map);
	map_data->dir_x = -1.0;
	map_data->dir_y = 0.0;
	map_data->plane_x = 0.0;
	map_data->plane_y = 0.66;
	map_data->speed = 0.025;
	map_data->rot_speed = 0.025;
	map_data->skyc = create_rgb(map_data->c_red,
			map_data->c_green, map_data->c_blue);
	map_data->floorc = create_rgb(map_data->f_red,
			map_data->f_green, map_data->f_blue);
	map_data->line_count -= 6;
	map_data->int_map = (int **)malloc(sizeof(int *) * map_data->line_count);
	if (!map_data->int_map)
		allocation_exit(map_data);
	i = -1;
	while (++i < map_data->line_count)
		map_data->int_map[i] = malloc(sizeof(int) * long_line(map_data->map));
}

void	convert_to_int(t_data *map_data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_data->line_count)
	{
		j = -1;
		while (map_data->map[i][++j] && map_data->map[i][j] != '\n')
		{
			if (map_data->map[i][j] > 65)
			{
				map_data->pos_x = j + 0.5;
				map_data->pos_y = i + 0.5;
				set_player_dir(map_data->map[i][j], map_data);
				map_data->int_map[i][j] = 0;
				continue ;
			}
			if (map_data->int_map[i][j] == ' ')
				map_data->int_map[i][j] = 2;
			else
				map_data->int_map[i][j] = map_data->map[i][j] - 48;
		}
		while (j < long_line(map_data->map))
			map_data->int_map[i][j++] = 3;
	}
}
