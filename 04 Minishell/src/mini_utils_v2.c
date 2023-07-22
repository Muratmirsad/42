/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:46:28 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/22 16:46:47 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	waitpid_func(int id)
{
	int	i;

	i = 0;
	close_func();
	while (i < id)
	{
		waitpid(g_var.pid[i], &g_var.exit_status, 0);
		if (WIFEXITED(g_var.exit_status))
			g_var.exit_status = WEXITSTATUS(g_var.exit_status);
		i++;
	}
}

int	is_pipe(void)
{
	int	i;

	i = 0;
	while (g_var.str[i])
	{
		if (g_var.str[i][0] == '|')
			return (1);
		i++;
	}
	return (0);
}

void	unlink_func(void)
{
	char	*tmp;
	char	p[128];

	g_var.built_ctrl = 0;
	if (g_var.rdr_left)
	{
		if (getcwd(p, sizeof(p)) == NULL)
			exit(1);
		tmp = ft_strjoin(p, "/.rdirect_left_tmp");
		unlink(tmp);
		free(tmp);
	}
}

void	rdirection_flag(void)
{
	t_ink_list	*tmp;

	tmp = g_var.lst;
	while (tmp)
	{
		if (tmp->flag == '>')
			if (tmp->next)
				tmp->next->flag = 'i';
		if (tmp->flag == '<')
			if (tmp->next)
				tmp->next->flag = 'o';
		tmp = tmp->next;
	}
}

int	check_quote(char *str)
{
	int		i;
	char	c;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				i++;
			if (str[i] != c)
			{
				printf("minishell: syntax error token `%c'\n", c);
				g_var.exit_status = 258;
				return (1);
			}
		}
	}
	return (0);
}
