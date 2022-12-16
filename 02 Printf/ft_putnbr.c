/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:24:38 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/09 13:20:10 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(long long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (++i);
}

static void	ft_run(long long nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_run(nb * -1);
	}
	else if (nb > 9)
	{
		ft_run(nb / 10);
		ft_run(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}

int	ft_putnbr(long long nb, int i)
{
	ft_run(nb);
	i = ft_num(nb);
	return (i);
}
