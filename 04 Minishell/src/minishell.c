/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:42 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/07/22 16:44:01 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	rdr_pipe_v2(void)
{
	t_ink_list	*tmp;

	tmp = g_var.lst;
	if (tmp)
		if (tmp->content[0] == '|')
			return (rdr_pipe_help());
	while (tmp)
	{
		if (tmp->flag == '|')
		{
			if (tmp->next != NULL)
			{
				if (tmp->next->flag == '>' || tmp->next->flag == '<')
					return (rdr_pipe_help());
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	rdr_pipe(void)
{
	t_ink_list	*tmp;

	tmp = g_var.lst;
	while (tmp)
	{
		if (tmp->flag == '>' || tmp->flag == '<')
			if (tmp->next == NULL)
				return (rdr_pipe_help());
		if (tmp->content[0] == '>' || tmp->content[0] == '<')
			if (tmp->next->content[0] == '|')
				return (rdr_pipe_help());
		if (tmp->content[0] == '>' && tmp->content[1] == '>')
			if (tmp->next == NULL)
				return (rdr_pipe_help());
		if (tmp->content[0] == '<' && tmp->content[1] == '<')
			if (tmp->next == NULL)
				return (rdr_pipe_help());
		if (tmp->content[0] != 0 && tmp->next != NULL)
			if (tmp->next->content[0] == '|' && tmp->content[0] == '|')
				return (rdr_pipe_help());
		tmp = tmp->next;
	}
	return (0);
}

int	minishell_init(char *mshell)
{
	add_history(mshell);
	if (check_quote(mshell))
	{
		free(mshell);
		return (1);
	}
	start_parser(mshell);
	if (rdr_pipe() || rdr_pipe_v2())
	{
		free(mshell);
		return (2);
	}
	command_prepare();
	rdirection_flag();
	if (cmd_init())
	{
		all_free_v2(mshell);
		return (-1);
	}
	cmd_pipe();
	return (0);
}

int	exec_input(char *mshell)
{
	if (file_handle() == -1)
	{
		all_free(mshell);
		return (1);
	}
	if (g_var.str[0] != NULL)
		exec_init();
	all_free(mshell);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char	*mshell;
	int		flag;

	mshell = NULL;
	null_init(ac, av, envp);
	while (1)
	{
		g_var.test = 0;
		mshell = readline("minishell $ ");
		if (g_var.test)
		{
			free(mshell);
			continue ;
		}
		if (mshell == NULL)
		{
			ioctl_helper();
			break ;
		}
		flag = minishell_init(mshell);
		if (flag == 1 || flag == 2 || flag == -1)
			continue ;
		if (exec_input(mshell) == 1)
			continue ;
	}
}
