/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:57:59 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/15 15:30:07 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocation_exit(t_data *map_data)
{
	(void)map_data;
	printf("Allocation Error\n");
	exit (1);
}

void	wrong_argument_exit(t_data *map_data, int error_code)
{
	(void)map_data;
	if (error_code == 10)
		printf("Wrong Argument Error\n");
	else if (error_code == 11)
		printf("The Map Name is Invalid Error\n");
	exit (error_code);
}

void	wrong_map_exit(t_data *map_data, int code)
{
	(void)map_data;
	if (code == 20)
		printf("Wrong Or Missing Data in .cub File Error\n");
	else if (code == 21)
		printf("Wrong RGB value Error\n");
	else if (code == 22)
		printf("Empty Line In The Map Or Extra Data Error\n");
	else if (code == 23)
		printf("Wrong Texture File Name Error\n");
	else if (code == 24)
		printf("Wrong Character In Line Error\n");
	else if (code == 25)
		printf("Wrong Character In The Map Error\n");
	else if (code == 26)
		printf("Multiple Starting Point Error\n");
	else if (code == 27)
		printf("There Is No Starting Point In The Map Error\n");
	else if (code == 28)
		printf("Map Must Be Covered By Walls Correctly Error\n");
	else if (code == 29)
		printf("Wrong Texture File Error\n");
	exit(code);
}

void	free_double_char(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
	free(ptr);
}

int	exit_from_win(t_data *map)
{
	(void)map;
	exit(1);
}
