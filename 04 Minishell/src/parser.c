/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 04:35:25 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/20 23:50:15 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*dollar_handler(char *str, char q)
{
	int		i;
	int		j;
	char	*result;
	char	*env;

	if (q == 39)
		return (str);
	result = NULL;
	i = 0;
	while (str[i])
	{
		j = i;
		while (str[i] && str[i] != '$')
			i++;
		result = ft_strjoin_v3(result, ft_strdup_v2(str, j, i));
		if (str[i] == '$')
		{
			dollar_help(str, i);
			env = get_env_var(&str[++i], g_var.env, &i, &j);
			if (env)
				result = ft_strjoin_v3(result, env);
		}
	}
	free(str);
	return (result);
}

char	*handle_regular(char *str, int *index)
{
	int		i;
	char	*result;

	i = *index;
	while (str[i] && !is_it_special(str[i]) && str[i] != 34 && str[i] != 39)
		i++;
	result = ft_strdup_v2(str, *index, i);
	*index = i;
	return (result);
}

void	handle_others(char *str, int *index)
{
	int		i;
	char	*result;

	result = NULL;
	i = *index;
	while (str[i] && !is_it_special(str[i]))
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			result = ft_strjoin_v3(result, dollar_handler
					(ft_strdup_v3(str, &i, str[i - 1]), str[i - 1]));
		}
		else
			result = ft_strjoin_v3(result,
					dollar_handler(handle_regular(str, &i), 0));
	}
	link_lstadd_back(&g_var.lst, link_lstnew(result, 'b'));
	*index = i;
}

void	special_handler(char *str, int *index, char q)
{
	int		backup;
	int		i;
	char	*result;

	backup = *index;
	i = 1;
	if (str[i + backup] == q && str[i + backup] != '|')
		i++;
	result = ft_strdup_v2(str, backup, i + backup);
	link_lstadd_back(&g_var.lst, link_lstnew(result, q));
	*index = i + backup;
}

int	start_parser(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	link_lstclear(&g_var.lst);
	while (i < len)
	{
		while (str[i] == ' ' || str[i] == 9)
			i++;
		if (str[i] == '>' || str[i] == '<' || str[i] == '|')
			special_handler(str, &i, str[i]);
		else if (str[i] && str[i] != ' ')
			handle_others(str, &i);
	}
	return (0);
}
