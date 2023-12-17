/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:17:47 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/14 15:02:58 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_x(t_data *data)
{
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->raydir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->raydir_x;
	data->wall_x -= floor(data->wall_x);
}

void	ray_casting_2(t_data *data)
{
	double	camera_x;

	camera_x = 2 * data->x / (double)WIDTH - 1;
	data->raydir_x = data->dir_x + data->plane_x * camera_x;
	data->raydir_y = data->dir_y + data->plane_y * camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->raydir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->raydir_y);
	data->hit = 0;
}

void	ray_casting_3(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
			* data->delta_dist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y)
			* data->delta_dist_y;
	}
}

void	ray_casting_4(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->int_map[data->map_y][data->map_x] > 0)
			data->hit = 1;
	}
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(HEIGHT / data->perp_wall_dist);
}

int	ray_casting(t_data *data)
{
	data->x = -1;
	while (++(data->x) < WIDTH)
	{
		ray_casting_2(data);
		ray_casting_3(data);
		ray_casting_4(data);
		calc_wall_x(data);
		data->tex_x = (int)(data->wall_x * (double)64);
		data->step = 1.0 * 64 / data->line_height;
		data->tex_pos = (data->draw_start - HEIGHT / 2
				+ data->line_height / 2) * data->step;
		data->y = 0;
		while (data->y < HEIGHT)
		{
			calc_texture_pixel_color(data);
			data->y++;
		}
	}
	return (0);
}
