/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:59:01 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 17:17:58 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cmd_pipe(void)
{
	int	i;

	i = 0;
	while (g_var.pipe_count > i)
	{
		g_var.cmds[i]->f_out = g_var.pipe[i][1];
		i++;
	}
	i = 1;
	while (g_var.pipe_count + 1 > i)
	{
		g_var.cmds[i]->f_in = g_var.pipe[i - 1][0];
		i++;
	}
}

int	print_error(char *file, int i)
{
	if (i == -1)
	{
		printf("minishell: %s: No such file or directory\n", file);
	}
	else
	{
		printf("minishell: syntax error near unexpected token `%c'\n",
			g_var.str[i][0]);
		g_var.exit_status = 258;
	}
	return (-1);
}

void	rdr_write_helper(char *line, int i)
{
	write(g_var.cmds[g_var.pipe_cntv2]->f_in, line, i);
	write(g_var.cmds[g_var.pipe_cntv2]->f_in, "\n", 1);
}

int	rdr_pipe_help(void)
{
	printf("minishell: syntax error near unexpected token `newline'\n");
	g_var.exit_status = 258;
	return (1);
}

void	close_file(void)
{
	int	i;

	i = 0;
	while (g_var.pipe_count > i)
	{
		if (g_var.cmds[i]->f_in != g_var.pipe[i][0])
			close(g_var.pipe[i][0]);
		if (g_var.cmds[i]->f_out != g_var.pipe[i][1])
			close(g_var.pipe[i][1]);
		i++;
	}
}
