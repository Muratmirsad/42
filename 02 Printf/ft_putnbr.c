/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:24:38 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/08 02:58:53 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(unsigned long long nb)
{
	unsigned long long	i;

	i = 0;
	while (nb > 10)
	{
		nb /= 10;
		i++;
	}
	return (++i);
}

int	ft_putnbr(long long nb, int i)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1, i);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
	i = ft_num(nb);
	return (++i);
}
