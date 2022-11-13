/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:28:21 by uasci             #+#    #+#             */
/*   Updated: 2022/10/22 18:57:46 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_finder(int a)
{
	int	result;

	result = 0;
	if (a == 0)
		return (1);
	else if (a == -2147483648)
		return (11);
	else if (a < 0)
	{
		result++;
		a *= -1;
	}
	while (a > 9)
	{
		a /= 10;
		result++;
	}
	return (++result);
}

void	negative(int *a, char *result)
{
	*a *= -1;
	result[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = digit_finder(n);
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	result[size--] = '\0';
	if (n == 0)
		result[size--] = '0';
	else if (n == -2147483648)
	{
		result[size--] = '8';
		n = -214748364;
	}
	if (n < 0)
		negative(&n, result);
	while (n > 0)
	{
		result[size--] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
