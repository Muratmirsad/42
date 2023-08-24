/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:31 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/22 16:47:21 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
			if ((size_t)index == ft_strlen(find) && g_var.env[i][j] == '=')
			{
				return (g_var.env[i]);
			}
		}
		i++;
	}
	return (NULL);
}

char	*f_v2(char *find)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = malloc(sizeof(char) * ft_strlen(find));
	while (find[i])
	{
		if (find[i] == '=')
		{
			i++;
			while (find[i])
			{
				str[k] = find[i];
				k++;
				i++;
			}
			str[k] = '\0';
			return (str);
		}
		i++;
	}
	return (NULL);
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

int	splt_len(char **str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
