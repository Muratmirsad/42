/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:50 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/30 19:22:40 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_move2(int *player, char **map, int move)
{
	if (move == 3 && map[player[1] + 1][player[0]] != '1')
	{
		if (map[player[1] + 1][player[0]] == 'c')
		{
			map[player[1] + 1][player[0]] = '2';
			player[2]--;
		}
		player[1] += 1;
	}
	else if (move == 4 && map[player[1]][player[0] - 1] != '1')
	{
		if (map[player[1]][player[0] - 1] == 'c')
		{
			map[player[1]][player[0] - 1] = '2';
			player[2]--;
		}
		player[0] -= 1;
	}
	else
		return (0);
	return (1);
}

int	player_move(int *player, char **map, int move)
{
	if (move == 1 && map[player[1] - 1][player[0]] != '1')
	{
		if (map[player[1] - 1][player[0]] == 'c')
		{
			map[player[1] - 1][player[0]] = '2';
			player[2]--;
		}
		player[1] -= 1;
		move = 1;
	}
	else if (move == 2 && map[player[1]][player[0] + 1] != '1')
	{
		if (map[player[1]][player[0] + 1] == 'c')
		{
			map[player[1]][player[0] + 1] = '2';
			player[2]--;
		}
		player[0] += 1;
		move = 1;
	}
	else
		move = player_move2(player, map, move);
	if (map[player[1]][player[0]] == 'e' && !player[2])
		exit(1);
	return (move);
}
