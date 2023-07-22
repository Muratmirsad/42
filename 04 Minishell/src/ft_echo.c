/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:13:03 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/22 17:03:33 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo_is_null(char *str, int k)
{
	int	i;

	i = 0;
	if (g_var.echo_help == 2)
		return (1);
	if (g_var.cmds[k]->str[1][0] != '-' && g_var.cmds[k]->str[1][1] != 'n')
	{
		g_var.echo_help = 1;
		return (1);
	}
	if (g_var.echo_help == 1)
		return (1);
	if (str[i] != '-')
		return (1);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	g_var.echo_help = 2;
	return (0);
}

int	ft_echo_help(int k)
{
	if (splt_len(g_var.cmds[k]->str) == 1)
	{
		printf("\n");
		return (0);
	}
	g_var.echo_help = 0;
	return (1);
}

void	ft_echo(int k)
{
	int	i;

	i = 1;
	if (ft_echo_help(k) == 0)
		return ;
	while (g_var.cmds[k]->str[i])
	{
		if (!ft_echo_is_null(g_var.cmds[k]->str[i], k))
			i++;
		else if (g_var.cmds[k]->str[i])
		{
			printf("%s", g_var.cmds[k]->str[i]);
			if (g_var.cmds[k]->str[i++ + 1])
				printf(" ");
		}
		else
			i++;
	}
	if (g_var.echo_help == 1)
		printf("\n");
}
