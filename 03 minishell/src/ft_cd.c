/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:46:12 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/22 16:46:15 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	cd_back(char *path)
{
	char	*p;

	p = cut_helper(path);
	if (chdir(p) != -1)
		get_pwd(p, 0);
	free(p);
}

static void	cd_next(char *path, char *next)
{
	char	*p;
	char	*a;

	if (ft_strlen(path) != 1)
	{
		p = ft_strdup("/");
		a = ft_strjoin(path, p);
		free(p);
	}
	else
		a = ft_strdup(path);
	p = ft_strjoin(a, next);
	if (chdir(p) != -1)
		get_pwd(p, 0);
	free(p);
	free(a);
}

static int	home_helper(char *home)
{
	int		i;
	int		key;
	char	p[128];

	i = 0;
	key = 0;
	if (getcwd(p, sizeof(p)) == NULL)
	{
		exit(1);
	}
	while (p[i])
	{
		if (p[i] == '/')
			key++;
		if (key == 3)
		{
			home[i] = 0;
			break ;
		}
		home[i] = p[i];
		i++;
	}
	get_pwd(p, 0);
	return (1);
}

static void	cd_tilde(char *home, int i)
{
	char	*p;

	if (i != 0)
	{
		if (g_var.str[i][1] != 0)
		{
			p = ft_strjoin(home, g_var.str[i] + 1);
			if (chdir(p) != -1)
				get_pwd(p, 0);
			free(p);
			return ;
		}
	}
	get_pwd(home, 0);
}

int	cd_func(int i)
{
	char		*path;
	static char	home[128];
	static int	flag = -1;

	if (flag == -1)
	{
		flag = home_helper(home);
		if (i == -1)
			return (0);
	}
	path = get_pwd(0, 1);
	if (g_var.str[i + 1])
	{
		if (strequal(g_var.str[i + 1], ".."))
			cd_back(path);
		else if (g_var.str[i + 1][0] == '~')
			cd_tilde(home, i + 1);
		else if (g_var.str[i + 1])
			cd_next(path, g_var.str[i + 1]);
	}
	else
		cd_tilde(home, 0);
	return (0);
}
