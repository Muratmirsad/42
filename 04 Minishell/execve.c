/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:19:42 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/07 16:39:54 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_splt(void)
{
	int i;
	char *a;
	char **str;

	i = 0;
	str = ft_split(find_in_env("PATH"), ':');
	a = ft_strdup(str[0]);
	free(str[0]);
	str[0] = ft_substr(a, 5, (ft_strlen(a) - 5));
    g_var.path_env = NULL;
	g_var.path_env = malloc(sizeof(char *) * splt_len(str));
	while (str[i])
	{
		g_var.path_env[i] = ft_strjoin(str[i], "/");
		free(str[i]);
		//printf("str = %s\n", str[i]);
		//printf("path_env = %s\n", g_var.path_env[i]);
		i++;
	}
}

char	**add_cmd(void)
{
	int i;
	int k;
	char	**str;
	link_list	*temp;

	i = 0;
	k = 0;
	temp = g_var.lst;
	str = malloc(sizeof(char *) * (g_var.lst_size + 1));
	while (g_var.str[i])
	{
		if (temp->flag == 'b')
		{
			str[k] = ft_strdup(g_var.str[i]);
			k++;
		}
		temp = temp->next;
		i++;
	}
	str[k] = NULL;
	return(str);
}

char	*cmd_acces(void)
{
	int i;
	int j;
	int k;
	char	*a;
	char **str;

	i = 0;
	str = add_cmd();
	while (str[i])
	{
		j = 0;
		k = 0;
		while (g_var.path_env[k])
		{
			j = i;
			a = ft_strjoin(g_var.path_env[k], str[i]);
			if (access(a, 0) == 0)
			{
				return(a);
			}
			j++;
			k++;
		}
		i++;
	}
	return(NULL);
}


void	exec_init(void)
{
	int		i;
	char	*ac;
	int		id;

	i = 0;
	g_var.cmd = add_cmd();
	id = fork();
	if (id == 0)
	{
		ac = cmd_acces();
		if (ac)
		{
			i = execve(ac, g_var.cmd, g_var.env);
			if (i == -1)
				printf("minishell: %s: command not found\n", g_var.str[0]);
		}
		
		exit(127);
	}
	waitpid(id, NULL, 0);
}