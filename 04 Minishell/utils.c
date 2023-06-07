/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:31 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/06 19:05:24 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmpv2(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s2)
		return (1);
	while (i < n && ((unsigned char)s1[i] || (unsigned char)s2[i]))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i]
			|| (unsigned char)s1[i] < (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*find_in_env(char *find)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	while (g_var.env_size > i)
	{
		j = 0;
		index = 0;
		while (g_var.env[i][j] && (find[index] == g_var.env[i][j]))
		{
			j++;
			index++;
			if (index == ft_strlen(find) && g_var.env[i][j] == '=')
				return (g_var.env[i]);
		}
		i++;
	}
	return (0);
}

int	is_alphanum(char *str, int len)
{
	int	i;

	if (!ft_isalpha(*str))
		return (0);
	i = -1;
	while (str[++i] && i < len)
	{
		if (!ft_isalnum(str[i]))
			return (0);
	}
	return (1);
}

int		splt_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void    free_func(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i++]);
    }
    free(str);
}

int    strequal(char *str, char *ptr)
{
    int i;
    int len;

    i = 0;
    len = 0;
    ft_tolower(str);
   	ft_tolower(ptr);
	if (ft_strlen(str) != ft_strlen(ptr))
		return (0);
    while (str[i])
    {
        if (str[i] == ptr[i])
            len++;
        else
            break;
        i++;
    }
    if (ft_strlen(ptr) == len)
    {
        return(1);
    }
    else
        return(0);
}

int	double_len(char **str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void     ft_unset(char *str)
{
	int i;
	int k;
	int flag;
	int len;

	i = 0;
	k = 0;
	flag = 0;
	len = ft_strlen(str);
	while (g_var.env[i])
	{
		if (ft_strncmp(g_var.env[i], str, len))
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag)
	{
		while (g_var.env[i])
		{
			g_var.env[i] = g_var.env[i + 1];
			i++;
		}
		free(g_var.env[i]);
	}
}
