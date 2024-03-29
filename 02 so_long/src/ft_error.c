/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:05 by mdiraga           #+#    #+#             */
/*   Updated: 2023/04/03 03:56:18 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	is_file_current(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (ft_strncmp(av + i - 4, ".ber", 4) != 0 && i > 4)
		ft_error();
}

void	move_rule_7(int total_move)
{
	ft_printf("total move: %d\n", total_move);
	exit(1);
}

int	exit_func(int keycode)
{
	ft_printf("exiting...\n");
	exit(keycode);
	return (0);
}
