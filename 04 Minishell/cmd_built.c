/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:30 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/07 18:13:21 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_print(void)
{
	int i;
	int k;
	int flag;

	i = 0;
	while (g_var.export[i])
	{
		flag = 0;
		k = 0;
		printf("declare -x ");
		while (g_var.export[i][k])
		{
			if (g_var.export[i][k] == '=')
			{
				printf("%c", g_var.export[i][k]);
				k++;
				printf("%c", '"');
				flag = 1;
				printf("%c", g_var.export[i][k]);
			}
			else
				printf("%c", g_var.export[i][k]);
			k++;
		}
		if (flag)
		{
			printf("%c", '"');
		}
		printf("\n");
		i++;
	}
}

int		command_built(void)
{
	int i;
	static int flag;

	i = 0;
	flag = 0;
	while (g_var.str[i])
	{
		if (strequal(g_var.str[i], "echo"))
		{
			ft_echo(i); // echo bitimşşşşşşşşş
			return(0);
		}
		else if (strequal(g_var.str[i], "cd"))
		{
			cd_func(i); // bitmedi
			return(0);
		}
		else if (strequal(g_var.str[i], "env"))
		{
			ft_env();
			return(0);
		}
        else if (strequal(g_var.str[i], "pwd"))
		{
			ft_pwd();
			return(0);
		}
    	else if (strequal(g_var.str[i], "unset"))
		{
			while (g_var.str[i])
			{
				if (g_var.str[i + 1] != NULL)
					ft_unset(g_var.str[i + 1]);
				i++;
			}
			return(0);
		}
		else if (strequal(g_var.str[i], "exit"))
		{
			if (i == 0)
			{
				ft_exit();
				return(0);
			}
		}
		else if (strequal(g_var.str[i], "export"))
		{
			if (g_var.lst_size > 1)
			{
				ft_export();
			}
			else
				export_print();
			return(0);
		}
		i++;
	}
	return(1);
}