/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:15:47 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/20 23:08:40 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	len_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	is_equal(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			return (0);
	return (1);
}

int	arg_isdigit(char *a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(a);
	while (a[i] >= '0' && a[i] <= '9')
		i++;
	if (len == i)
		return (1);
	else
		return (0);
}

void	ft_exit(void)
{
	int	i;

	i = 0;
	if (g_var.str[i + 1] == NULL)
	{
		printf("exit\n");
		exit(1);
	}
	else if (arg_isdigit(g_var.str[i + 1]) && g_var.str[i + 2] != NULL)
	{
		printf("exit\n");
		printf("minishell$: exit: too many arguments\n");
	}
	else if (arg_isdigit(g_var.str[i + 1]) && g_var.str[i + 2] == NULL)
	{
		printf("exit\n");
		exit(ft_atoi(g_var.str[i + 1]));
	}
	else
	{
		printf("exit\n");
		printf("minishell$: exit: %s: numeric argument required",
			g_var.str[i + 1]);
		exit(255);
	}
}

int	double_len(char **str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
