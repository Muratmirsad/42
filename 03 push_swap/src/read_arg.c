/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:40:50 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/31 17:46:37 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_factor(char *p, int i)
{
	if ((p[i] == 43 || p[i] == 45)
		&& !(p[i + 1] >= 48 && p[i + 1] <= 57))
	{
		free(p);
		ft_error(1);
	}
	if (p[i] == 45)
		return (-1);
	return (1);
}

int	*ft_handle(char *p, int i, int factor, int cnt)
{
	int	key;
	int	nb;
	int	*new;

	new = (int *)malloc(4 * cnt);
	cnt = 0;
	while (p[i])
	{
		key = 0;
		nb = 0;
		if (p[i] == 43 || p[i] == 45)
			factor = ft_factor(p, i++);
		while (p[i] >= 48 && p[i] <= 57)
		{
			nb *= 10;
			nb += p[i++] - 48;
			key = 1;
		}
		if (key)
			new[cnt++] = nb * factor;
		factor = 1;
		i++;
	}
	free(p);
	return (new);
}

void	ft_control(char *p)
{
	int	i;

	i = 0;
	while ((p[i] == 32 || p[i] == 43 || p[i] == 45)
		|| (p[i] >= 48 && p[i] <= 57))
		i++;
	if (p[i])
	{
		free(p);
		ft_error(2);
	}

}

void	ft_intcontrol(int *ip, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ip[i] == ip[j])
			{
				free(ip);
				ft_error(3);
			}
			j++;
		}
		i++;
	}
}

int	*read_arg(char **av, int *size)
{
	char	*p;
	int		*intpointer;
	int		i;
	int		cnt;

	cnt = 1;
	i = 2;
	p = ft_strdup(av[1]);
	while (av[i])
	{
		p = ft_strjoin(p, " ");
		p = ft_strjoin(p, av[i++]);
	}
	i = 0;
	while (p[i++])
	{
		if (p[i] == 32 && p[i + 1] != 32)
			cnt++;
	}
	ft_control(p);
	intpointer = ft_handle(p, 0, 1, cnt);
	ft_intcontrol(intpointer, cnt);
	*size = cnt;
	return (intpointer);
}
