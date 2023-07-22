/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:47:37 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/07/21 14:03:42 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pipe_init(void)
{
	t_ink_list	*tmp;
	int			i;
	int			len;

	len = 0;
	tmp = g_var.lst;
	while (tmp)
	{
		if (tmp->flag == '|')
			len++;
		tmp = tmp->next;
	}
	g_var.pipe_count = len;
	g_var.pipe = malloc(sizeof(int *) * g_var.pipe_count);
	i = 0;
	while (g_var.pipe_count > i)
	{
		g_var.pipe[i] = malloc(sizeof(int) * 2);
		pipe(g_var.pipe[i]);
		i++;
	}
	g_var.pid = malloc(sizeof(pid_t) * (g_var.pipe_count + 1));
}

int	cmds_helper_v2(int *k, t_ink_list **tmp)
{
	int	i;

	i = 0;
	while (*tmp)
	{
		if ((*tmp)->flag == 'b')
			g_var.help[*k][i++] = ft_strdup((*tmp)->content);
		if ((*tmp)->flag == '|')
			break ;
		(*tmp) = (*tmp)->next;
	}
	g_var.help[*k][i] = 0;
	if ((*tmp))
	{
		if ((*tmp)->flag == '|')
		{
			if ((*tmp)->next)
				(*tmp) = (*tmp)->next;
			else
				if (pipe_help() == 0)
					return (0);
		}
	}
	return (1);
}

int	cmds_helper(void)
{
	t_ink_list	*tmp;
	int			k;

	pipe_init();
	k = 0;
	tmp = g_var.lst;
	g_var.help = malloc(sizeof(char **) * (g_var.pipe_count + 2));
	while (tmp)
	{
		g_var.help[k] = malloc(sizeof(char *) * (var_count(tmp) + 2));
		if (cmds_helper_v2(&k, &tmp) == 0)
			return (1);
		k++;
	}
	g_var.help[k] = NULL;
	return (0);
}

int	cmd_init(void)
{
	int			i;
	t_ink_list	*tmp;

	g_var.free_control = 0;
	if (cmds_helper())
	{
		g_var.free_control = 1;
		return (1);
	}
	g_var.cmds = NULL;
	tmp = g_var.lst;
	g_var.cmds = malloc(sizeof(t_pip *) * (g_var.pipe_count + 2));
	i = 0;
	while ((i < g_var.pipe_count + 1) && tmp)
	{
		g_var.cmds[i] = malloc(sizeof(t_pip));
		g_var.cmds[i]->str = g_var.help[i];
		g_var.cmds[i]->flag = tmp->flag;
		g_var.cmds[i]->f_in = STDIN_FILENO;
		g_var.cmds[i]->f_out = STDOUT_FILENO;
		i++;
		tmp = tmp->next;
	}
	g_var.cmds[i] = NULL;
	return (0);
}
