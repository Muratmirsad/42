/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:26:20 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/25 19:26:22 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_run(char *str, int index, long int nb, int x)
{
	while ((9 <= str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == 43)
		index++;
	if (str[index] == 45)
	{
		x = -1;
		index++;
	}
	nb = 0;
	while (48 <= str[index] && str[index] <= 57)
	{
		nb = nb * 10;
		nb = nb + (str[index] - 48);
		index++;
	}
	if (nb * x > 2147483647)
		return (-1);
	if (nb * x < -2147483648)
		return (0);
	return (nb * x);
}

int	ft_atoi(char *str)
{
	return (ft_run(str, 0, 0, 1));
}
