/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:36:54 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/20 23:42:41 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_env_var(char *str, char **env, int *i, int *j)
{
	int	index;
	int	len;

	index = 0;
	if (str[0] == 0)
		return (only_dolar());
	if (str[index] == '?')
	{
		*i += 1;
		return (ft_itoa(g_var.exit_status));
	}
	while (ft_isalnum(str[index]))
		index++;
	*j = *i;
	*i += index;
	len = *i - *j;
	while (*env)
	{
		if (ft_strncmp_v3(str, *env, len) == 0 && (*env)[len] == '=')
			break ;
		env++;
	}
	if (!(*env))
		return (NULL);
	return (ft_strdup(&((*env)[len + 1])));
}

char	*ft_strjoin_v3(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*result;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	free(s1);
	free(s2);
	result[i] = '\0';
	return (result);
}

char	*ft_strdup_v2(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[start] && start < end)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlen_v2(char *str, char q, int i)
{
	while (str[i] && str[i] != q)
		i++;
	return (i);
}

char	*ft_strdup_v3(char *str, int *start, char end)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen_v2(str, end, *start) - *start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[*start] && str[*start] != end)
	{
		result[i] = str[*start];
		i++;
		(*start)++;
	}
	result[i] = '\0';
	(*start)++;
	return (result);
}
