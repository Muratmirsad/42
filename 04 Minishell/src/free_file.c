/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:25 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/22 16:46:01 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	rdirect_add(void)
{
	g_var.rdr_left = 1;
	write(1, "\033[2D", 4);
	write(1, "  ", 2);
	write(1, "\033[2D", 4);
	ioctl(-1, TIOCSTI, "\n");
}

void	all_free_add(char *mshell)
{
	if (g_var.pipe_count >= 0)
		if (g_var.pipe)
			free(g_var.pipe);
	if (g_var.pid)
		free(g_var.pid);
	g_var.pid = NULL;
	if (g_var.acces)
		free(g_var.acces);
	if (mshell)
		free(mshell);
	unlink_func();
}

void	all_free(char *mshell)
{
	int	i;

	i = -1;
	if (g_var.str)
		free_func(g_var.str);
	while (++i < g_var.pipe_count + 1)
	{
		if (g_var.help[i])
			free_func(g_var.help[i]);
		if (g_var.cmds[i])
			free(g_var.cmds[i]);
	}
	if (g_var.help)
		free(g_var.help);
	if (g_var.cmds)
		free(g_var.cmds);
	i = -1;
	while (++i < g_var.pipe_count)
		if (g_var.pipe[i])
			free(g_var.pipe[i]);
	all_free_add(mshell);
}

void	all_free_add_v2(char *mshell)
{
	int	i;

	i = 0;
	while (++i < g_var.pipe_count)
		if (g_var.pipe[i])
			free(g_var.pipe[i]);
	if (g_var.pipe_count >= 0)
		free(g_var.pipe);
	if (g_var.pid)
		free(g_var.pid);
	g_var.pid = NULL;
	if (mshell)
		free(mshell);
}

void	all_free_v2(char *mshell)
{
	int	i;

	i = 0;
	if (g_var.str)
		free_func(g_var.str);
	if (g_var.free_control == 0)
	{
		while (i < g_var.pipe_count + 1)
		{
			if (g_var.help[i])
				free_func(g_var.help[i]);
			if (g_var.cmds)
				free(g_var.cmds[i]);
			i++;
		}
		if (g_var.cmds)
			free(g_var.cmds);
		if (g_var.help)
			free(g_var.help);
	}
	all_free_add_v2(mshell);
}
