/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:46:25 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/11 14:46:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_run(char *str, int index, int nb, int x)
{
	while ((9 <= str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == 43)
		index++;
	x = 1;
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
	return (ft_run(str, 0, 0, 0));
}
