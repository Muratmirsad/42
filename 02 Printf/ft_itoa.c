/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:11:26 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/21 19:59:14 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(char *rstr, int number, int factor, int x)
{
	while (factor-- > 0)
	{
		*(rstr + factor + x) = (number % 10) + 48;
		number /= 10;
	}
	if (x == 1)
		*rstr = '-';
}

static int	ft_control(int number, int factor)
{
	while (number > 9)
	{
		number /= 10;
		factor += 1;
	}
	return (factor);
}

static void	ft_min(char *rstr)
{
	rstr[0] = '-';
	rstr[1] = '2';
	rstr[2] = '1';
	rstr[3] = '4';
	rstr[4] = '7';
	rstr[5] = '4';
	rstr[6] = '8';
	rstr[7] = '3';
	rstr[8] = '6';
	rstr[9] = '4';
	rstr[10] = '8';
	rstr[11] = 0;
}

char	*ft_itoa(int number)
{
	int		factor;
	char	*rstr;
	int		x;

	if (number == -2147483648)
	{
		rstr = (char *)malloc(12);
		if (!rstr)
			return (0);
		ft_min(rstr);
		return (rstr);
	}
	x = 0;
	if (number < 0)
	{
		x = 1;
		number *= -1;
	}
	factor = ft_control(number, 1);
	rstr = (char *)malloc(factor + x + 1);
	if (!rstr)
		return (0);
	ft_convert(rstr, number, factor, x);
	*(rstr + factor + x) = 0;
	return (rstr);
}
