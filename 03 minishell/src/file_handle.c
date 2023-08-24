/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:14:54 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/22 16:44:59 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	rdirect_left_helper(char *find)
{
	char	*line;
	int		i;

	line = readline("> ");
	if (g_var.rdr_left)
	{
		free(line);
		return ;
	}
	else if (line == NULL)
	{
		rdirect_add();
		return ;
	}
	else if (!ft_strcmpv3(find, line))
	{
		i = ft_strlen(line);
		if (g_var.cmds[g_var.pipe_cntv2])
			rdr_write_helper(line, i);
		rdirect_left_helper(find);
	}
	free(line);
}

static int	rdirect_left(char *file)
{
	int	fd;

	unlink_func();
	g_var.rdr_left = 0;
	fd = open(".rdirect_left_tmp", O_RDWR | O_CREAT, 0777);
	g_var.cmds[g_var.pipe_cntv2]->f_in = fd;
	rdirect_left_helper(file);
	close(fd);
	fd = open(".rdirect_left_tmp", O_RDWR, 0777);
	g_var.cmds[g_var.pipe_cntv2]->f_in = fd;
	g_var.rdr_left = 1;
	return (fd);
}

static int	file_helper(char *file, char key)
{
	int	fd;

	fd = 0;
	if (key == '>')
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	else if (key == '<')
	{
		fd = open(file, O_RDWR, 0777);
		g_var.cmds[g_var.pipe_cntv2]->f_in = fd;
	}
	else if (key == 31)
		fd = open(file, O_RDWR | O_APPEND | O_CREAT, 0777);
	else if (key == 30)
		fd = rdirect_left(file);
	if (fd == -1)
		return (print_error(file, -1));
	if (key == '>' || key == 31)
		g_var.cmds[g_var.pipe_cntv2]->f_out = fd;
	return (1);
}

static void	int_init(int *i, int *key)
{
	g_var.pipe_cntv2 = 0;
	*i = -1;
	*key = 0;
}

int	file_handle(void)
{
	int	i;
	int	key;

	int_init(&i, &key);
	while (g_var.str[++i])
	{
		if (g_var.str[i][0] == '|')
			g_var.pipe_cntv2++;
		else if ((g_var.str[i][0] == 60 && g_var.str[i][1] == 60)
				|| (g_var.str[i][0] == 62 && g_var.str[i][1] == 62))
		{
			if (g_var.str[i + 1][0] >= 60 && g_var.str[i + 1][0] <= 62)
				return (print_error(0, i));
			key = file_helper(g_var.str[i + 1], g_var.str[i][0] / 2);
		}
		else if (g_var.str[i][0] == 60 || g_var.str[i][0] == 62)
		{
			if (g_var.str[i + 1][0] >= 60 && g_var.str[i + 1][0] <= 62)
				return (print_error(0, i));
			key = file_helper(g_var.str[i + 1], g_var.str[i][0]);
		}
		if (key == -1)
			break ;
	}
	return (key);
}
