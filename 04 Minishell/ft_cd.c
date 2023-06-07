/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:05:05 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/07 22:09:12 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// key == ("0" pwd değiştirme isteği, "0"dan farklı değer pwd çekme isteği)
char	*get_pwd(char *path, int key)
{
    static char *pwd = -1;
    
    if (key == 0)
    {
        if (pwd == -1)
        {
            pwd = (char *)malloc(sizeof(char) * 256);
            ft_strlcpy(pwd, path, ft_strlen(path));
            return (0);
        }
        ft_strlcpy(pwd, path, ft_strlen(path) + 1);
        return (0);
    }
    return (pwd);
}

static char	*cut_helper(const char *str)
{
	int i;
	char *rstr;
	
	i = ft_strlen(str) - 1;
	rstr = (char *)malloc(i + 2);
	if (str[i] == '/')
		i--;
	while (i >= 0 && str[i] != '/')
		i--;
	ft_strlcpy(rstr, str, i + 1);
	if (ft_strlen(rstr) < 2)
		ft_strlcpy(rstr, "/", 2);
	return (rstr);
}

static void cd_back(char *path)
{
	char *p;

	p = cut_helper(path);
	printf("cut_back: %s\n", p);
	if (chdir(p) != -1)
		get_pwd(p, 0);
}

static void cd_next(char *path, char *next)
{
	char *p;

	printf("cd_next çalıştı.\n");
	if (ft_strlen(path) != 1)
	{
		p = ft_strdup("/");
		p = ft_strjoin(path, p);
	}
	else
		p = path;
	p = ft_strjoin(p, next);
	if (chdir(p) != -1)
		get_pwd(p, 0);
}

static void home_helper(char *path, char *home)
{
	int i;
	int key;
	
	i = 0;
	key = 0;
	while (path[i])
	{
		if (path[i] == '/')
			key++;
		if (key == 2)
			break ;
		home[i] = path[i];
		i++;
	}
}

static void	cd_tilde(char *home, int i)
{
	char	*p;

	if (i != 0)
	{
		if (g_var.str[i + 1][1] != 0)
		{
			p = ft_strjoin(home, g_var.str[i + 1] + 1);
			if (chdir(p) != -1)
				get_pwd(p, 0);
			return ;
		}
	}
	printf("home dizini: %s\n home chdir: %d\n", home, chdir(home));
	get_pwd(home, 0);
}

int cd_func(int i)				// PWD DURMU YAPILACAK EKSİK VAR!!
{    
	char		*path;
	static char *home;
	static int	flag = -1;
	
	if (flag == -1) // pwd'ye başlangıç konumunu atıyorum
	{
		flag = 1;
		home = (char *)malloc(32);
		path = find_in_env("PWD") + 4;
		home_helper(path, home);
		get_pwd(path, 0);
	}
	path = get_pwd(0, 1);
	if (g_var.str[i + 1])
	{
		if (strequal(g_var.str[i + 1], ".."))
			cd_back(path);
		else if (g_var.str[i + 1][0] == '~')
			cd_tilde(home, i);
		else if (g_var.str[i + 1])
			cd_next(path, g_var.str[i + 1]);
	}
	else
		cd_tilde(home, 0);
	printf("-------%s\n", get_pwd(0, 1));
	return (0);
}
