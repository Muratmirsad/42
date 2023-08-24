/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:12:18 by bkarlida          #+#    #+#             */
/*   Updated: 2022/10/26 16:50:21 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		result = 1;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = ft_nbr(num);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	str[len] = 0;
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
