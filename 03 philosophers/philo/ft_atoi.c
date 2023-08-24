/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:26:20 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/07 19:00:27 by mdiraga          ###   ########.fr       */
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

int	ft_isdigit(int a)
{
	if (a < '0' || a > '9')
		return (0);
	return (1);
}
