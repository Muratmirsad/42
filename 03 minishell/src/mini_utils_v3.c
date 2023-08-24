/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:53:35 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 17:18:13 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	signal_helper(void)
{
	if (g_var.quit_flag == 1)
	{
		write(1, "\033[2D", 4);
		write(1, "  ", 2);
		write(1, "\033[2D", 4);
		ioctl(-1, TIOCSTI, "\n");
		g_var.quit_flag = 0;
	}
	g_var.quit_flag = 1;
}

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		if (g_var.rdr_left)
		{
			g_var.test = 1;
			g_var.exit_status = 1;
			write(1, "\033[A", 3);
			ioctl(0, TIOCSTI, "\n");
		}
		else
		{
			g_var.rdr_left = 1;
			write(1, "\033[A", 3);
			ioctl(0, TIOCSTI, "\n");
		}
	}
	else if (signal == SIGQUIT)
	{
		signal_helper();
	}
}

void	ioctl_helper(void)
{
	write(1, "\033[2D", 4);
	write(1, "\033[0mexit\n", 9);
}

int	var_count(t_ink_list	*tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (tmp->flag == 'b')
			i++;
		if (tmp->flag == '|')
			break ;
		tmp = tmp->next;
	}
	return (i);
}

int	pipe_help(void)
{
	printf("minishell: syntax error near unexpected token `newline'\n");
	g_var.exit_status = 258;
	return (0);
}
