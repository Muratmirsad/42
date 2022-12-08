/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:02:23 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/08 02:12:12 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num()
{
	static int	i;
	
	return (++i);
}

static void	ft_put(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put(num / 16);
		ft_put(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'), 1);
		else
			ft_putchar((num - 10 + 'a'), 1);
		ft_num();
	}
}

int	ft_putpointer(unsigned long long p, int nb)
{
	nb = 0;

	nb += ft_putstr("0x", nb);
	ft_put(p);
	nb += ft_num();
	return (nb - 1);
}
