/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:03:14 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/08 02:41:26 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(unsigned long long nb)
{
	unsigned long long	i;

	i = 0;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (++i);
}

static void	ft_put(int nb, int c)
{
	nb = nb - 23 + c;
	write(1, &nb, 1);
}

static void	ft_run(unsigned long long nb, int c)
{
	if (nb >= 16)
	{
		ft_run(nb / 16, c);
		ft_run(nb % 16, c);
	}
	else if (nb >= 10)
	{
		ft_put(nb % 10, c);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}

int	ft_puthexadecimal(unsigned long long nb, int c)
{
	ft_run(nb, c);
	c = ft_num(nb);
	return (c);
}
