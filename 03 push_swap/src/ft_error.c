/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:10:22 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/02 02:48:36 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_control_main(int *stack, int size)
{
	int	i;

	i = 0;
	while (stack[i] < stack[i + 1] && i < size - 1)
		i++;
	if (i < size - 1)
		return (0);
	return (1);
}

void	ft_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	//system("leaks push_swap");
	exit(code);
}
