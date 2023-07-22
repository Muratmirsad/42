/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:55:58 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/22 16:44:35 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strncmp_v3(const char *s1, const char *s2, size_t n)
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

int	strequal(char *str, char *ptr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (ft_strlen(str) != ft_strlen(ptr))
		return (0);
	while (str[i])
	{
		if (str[i] == ptr[i])
			len++;
		else
			break ;
		i++;
	}
	if (ft_strlen(ptr) == (size_t)len)
	{
		return (1);
	}
	else
		return (0);
}

void	free_func_three(char ***str)
{
	int	k;

	k = 0;
	while (str[k])
	{
		free_func(str[k]);
		k++;
	}
	free(str);
}

void	free_func(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}

void	free_func_int(int **str)
{
	int	i;

	i = 0;
	while (i < g_var.pipe_count)
	{
		free(str[i++]);
	}
	free(str);
}
