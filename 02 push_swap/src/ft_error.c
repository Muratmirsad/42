/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:10:22 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/08 23:51:41 by mdiraga          ###   ########.fr       */
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

int	*convert_to_intp(long *lp, int size)
{
	int	i;
	int	*rint;

	i = 0;
	rint = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		rint[i] = (int)lp[i];
		i++;
	}
	free(lp);
	return (rint);
}

void	ft_intcontrol(long *ip, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ip[i] == ip[j] || ip[j] > 2147483647 || ip[j] < -2147483648)
			{
				free(ip);
				ft_error(3);
			}
			j++;
		}
		i++;
	}
}

void	ft_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
}
