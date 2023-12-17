/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:07 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/14 15:02:24 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->move[0] = 1;
	else if (keycode == 1)
		data->move[1] = 1;
	else if (keycode == 0)
		data->move[2] = 1;
	else if (keycode == 2)
		data->move[3] = 1;
	else if (keycode == 123)
		data->move[4] = 1;
	else if (keycode == 124)
		data->move[5] = 1;
	if (keycode == 53)
		exit_from_win(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->move[0] = 0;
	else if (keycode == 1)
		data->move[1] = 0;
	else if (keycode == 0)
		data->move[2] = 0;
	else if (keycode == 2)
		data->move[3] = 0;
	else if (keycode == 123)
		data->move[4] = 0;
	else if (keycode == 124)
		data->move[5] = 0;
	return (0);
}
