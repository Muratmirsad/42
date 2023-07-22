/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:22:47 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/22 16:44:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	built_control(void)
{
	if (g_var.pipe_count >= 1)
	{
		g_var.built_ctrl = 1;
		return (0);
	}
	return (1);
}

void	close_func(void)
{
	int	i;

	i = -1;
	while (++i < g_var.pipe_count)
	{
		close(g_var.pipe[i][1]);
		close(g_var.pipe[i][0]);
	}
	i = 0;
	while (i < g_var.pipe_count + 1)
	{
		if (g_var.cmds[i]->f_in > 1)
			close(g_var.cmds[i]->f_in);
		if (g_var.cmds[i]->f_out > 1)
			close(g_var.cmds[i]->f_out);
		i++;
	}
}

void	close_fd(t_pip *cmds)
{
	int	i;

	i = 0;
	while (i < g_var.pipe_count)
	{
		if (cmds->f_in != g_var.pipe[i][0])
			close(g_var.pipe[i][0]);
		if (cmds->f_out != g_var.pipe[i][1])
			close(g_var.pipe[i][1]);
		i++;
	}
}

int	ft_strcmpv3(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	if (!(s1[i] - s2[i]))
		return (1);
	else
		return (0);
}

char	*get_pwd(char *path, int key)
{
	static char	pwd[256];

	if (key == 0)
	{
		if (pwd == (char *)0)
		{
			ft_strlcpy(pwd, path, ft_strlen(path));
			return (0);
		}
		ft_strlcpy(pwd, path, ft_strlen(path) + 1);
		return (0);
	}
	return (pwd);
}
