/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:01:46 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 15:45:08 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dollar_help(char *str, int i)
{
	if (str[i + 1] == 0)
		g_var.dolar = 1;
	else
		g_var.dolar = 0;
}

char	*only_dolar(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = '$';
	str[1] = 0;
	return (str);
}

char	**add_cmd(void)
{
	int			i;
	int			k;
	char		**str;
	t_ink_list	*temp;

	i = 0;
	k = 0;
	str = NULL;
	temp = g_var.lst;
	while (g_var.cmds[i])
	{
		str[k] = ft_strdup(g_var.cmds[i]->str[0]);
		k++;
		temp = temp->next;
		i++;
	}
	str[k] = NULL;
	return (str);
}

char	*ft_strjoin_v4(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	i;
	size_t	k;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	k = 0;
	j = 0;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (nstr == NULL)
		return (0);
	while (s1[i])
		nstr[i++] = s1[j++];
	while (s2[k])
		nstr[i++] = s2[k++];
	nstr[i] = '\0';
	return (nstr);
}

int	cmd_acces(int i)
{
	int	k;

	k = 0;
	if (g_var.acces)
		free(g_var.acces);
	g_var.acces = g_var.cmds[i]->str[0];
	g_var.cmds_int = i;
	if (access(g_var.acces, 0) == 0)
		return (0);
	while (g_var.path_env[k])
	{
		g_var.acces = ft_strjoin_v4(g_var.path_env[k], g_var.cmds[i]->str[0]);
		if (g_var.acces == NULL)
		{
			free(g_var.acces);
			return (1);
		}
		g_var.cmds_int = i;
		if (access(g_var.acces, 0) == 0)
			return (0);
		free(g_var.acces);
		k++;
	}
	return (-1);
}
