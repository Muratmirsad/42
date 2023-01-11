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

static int	ft_num(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (++i);
}

static void	ft_run(unsigned int nb)
{
	if (nb > 9)
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

int	ft_putunsigned(unsigned int nb, int i)
{
	ft_run(nb);
	i = ft_num(nb);
	return (i);
}
