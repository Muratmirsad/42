/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:03 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/13 10:07:26 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->dir_x * data->speed)] == 0)
		data->pos_x += data->dir_x * data->speed;
	if (data->int_map[(int)(data->pos_y + data->dir_y * data->speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y += data->dir_y * data->speed;
}

void	move_back(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x - data->dir_x * data->speed)] == 0)
		data->pos_x -= data->dir_x * data->speed;
	if (data->int_map[(int)(data->pos_y - data->dir_y * data->speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y -= data->dir_y * data->speed;
}

void	move_right(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->plane_x * data->speed)] == 0)
		data->pos_x += data->plane_x * data->speed;
	if (data->int_map[(int)(data->pos_y + data->plane_y * data->speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y += data->plane_y * data->speed;
}

void	move_left(t_data *data)
{
	if (data->int_map[(int)(data->pos_y)]
		[(int)(data->pos_x - (data->plane_x * data->speed))] == 0)
		data->pos_x -= data->plane_x * data->speed;
	if (data->int_map[(int)(data->pos_y - data->plane_y * data->speed)]
		[(int)(data->pos_x)] == 0)
		data->pos_y -= data->plane_y * data->speed;
}

void	player_move(t_data *data)
{
	if (data->move[0] == 1)
		move_forward(data);
	else if (data->move[1] == 1)
		move_back(data);
	if (data->move[2] == 1)
		move_left(data);
	else if (data->move[3] == 1)
		move_right(data);
	if (data->move[4] == 1)
		rotate_left(data);
	else if (data->move[5] == 1)
		rotate_right(data);
}
