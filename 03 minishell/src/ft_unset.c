/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:05:31 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 07:57:48 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	equ_envp(char *str)
{
	int	i;

	i = 0;
	while (g_var.env[i])
	{
		if (len_equal(g_var.env[i]) == len_equal(str))
		{
			if (!ft_strncmpv2(g_var.env[i], str, len_equal(g_var.env[i])))
				return (i);
		}
		i++;
	}
	return (-1);
}

int	equ_export(char *str)
{
	int	i;

	i = 0;
	while (g_var.export[i])
	{
		if (len_equal(g_var.export[i]) == len_equal(str))
		{
			if (!ft_strncmpv2(g_var.export[i],
					str, len_equal(g_var.export[i])))
				return (i);
		}
		i++;
	}
	return (-1);
}

void	delenv(char *str)
{
	int		index;
	int		len;
	int		i;
	int		j;
	char	**temp;

	index = equ_envp(str);
	if (index == -1)
		return ;
	len = splt_len(g_var.env);
	temp = malloc(sizeof(char *) * (len + 1));
	i = -1;
	j = -1;
	while (++i < len)
	{
		if (i == index)
			j++;
		temp[i] = ft_strdup(g_var.env[++j]);
	}
	temp[i] = 0;
	free_func(g_var.env);
	g_var.env = temp;
}

void	delexport(char *str)
{
	int		index;
	int		len;
	int		i;
	int		j;
	char	**temp;

	index = equ_export(str);
	if (index == -1)
		return ;
	len = splt_len(g_var.export);
	temp = malloc(sizeof(char *) * (len + 1));
	i = -1;
	j = -1;
	while (++i < len)
	{
		if (i == index)
			j++;
		temp[i] = ft_strdup(g_var.export[++j]);
	}
	temp[i] = 0;
	free_func(g_var.export);
	g_var.export = temp;
}

void	ft_unset(void)
{
	int	len;
	int	i;

	len = splt_len(g_var.cmds[0]->str);
	i = 1;
	while (i < len)
	{
		g_var.path_flag = strequal(g_var.cmds[0]->str[i], "PATH");
		delexport(g_var.cmds[0]->str[i]);
		delenv(g_var.cmds[0]->str[i]);
		i++;
	}
}
