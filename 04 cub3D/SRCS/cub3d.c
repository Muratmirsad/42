/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:59:07 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/16 16:43:32 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	main_proc(t_data *data)
{
	player_move(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->img.image, 0, 0);
	return (0);
}

void	check_file_name(t_data *map_data, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5)
		wrong_argument_exit(map_data, 11);
	if (name[len - 1] != 'b' || name[len - 2] != 'u' || name[len - 3] != 'c'
		|| name[len - 4] != '.')
		wrong_argument_exit(map_data, 11);
}

void	start_game(t_data *data)
{
	data->mlx_data->mlx = mlx_init();
	data->mlx_data->win = mlx_new_window(data->mlx_data->mlx,
			WIDTH, HEIGHT, "Cub3d");
	start_img(data);
	xpm_to_textures(data);
	mlx_hook(data->mlx_data->win, 2, 0, key_press, data);
	mlx_hook(data->mlx_data->win, 3, 0, key_release, data);
	mlx_hook(data->mlx_data->win, 17, 1L << 2, exit_from_win, data);
	mlx_loop_hook(data->mlx_data->mlx, &main_proc, data);
	mlx_loop(data->mlx_data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*map_data;

	if (ac != 2)
		wrong_argument_exit(NULL, 10);
	map_data = malloc(sizeof(t_data));
	if (!map_data)
		allocation_exit(map_data);
	map_data->map_name = av[1];
	check_file_name(map_data, av[1]);
	check_map(map_data);
	convert_to_int(map_data);
	map_data->mlx_data = (t_data_m *)malloc(sizeof(t_data_m));
	start_game(map_data);
	return (0);
}
