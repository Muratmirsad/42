/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:41:50 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/08 02:43:53 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(unsigned long long nb)
{
	unsigned long long	i;

	i = 0;
	while (nb > 16)
	{
		nb /= 16;
		i++;
	}
	return (++i);
}

int	ft_putunsigned(unsigned int nb, int i)
{
	if (nb > 9)
	{
		ft_putunsigned(nb / 10, i);
		ft_putunsigned(nb % 10, i);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
	i = ft_num(nb);
	return (i);
}
