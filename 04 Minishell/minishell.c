/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:42 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/06/07 21:19:10 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_prepare(void)
{
	link_list	*tmp;
	int i;

	i = 0;
	tmp = g_var.lst;
	g_var.lst_size = link_lstsize(g_var.lst);
	g_var.str = malloc(sizeof(char *) * (g_var.lst_size + 1));
	while (tmp)
	{
		g_var.str[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	//printf("%s\n", g_var.lst->content);
	g_var.str[i] = NULL;
	/*i = 0;
	while (g_var.str[i])
	{	
		printf("******%s******\n", g_var.str[i++]);
	}*/
}

void	env_malloc(char **envp)
{
	int i;
	int len;

	len = 0;
	while (envp[len])
		len++;
	g_var.env_size = len;
	i = 0;
	g_var.env = malloc(sizeof(char *) * (g_var.env_size + 2));
	while (envp[i])
	{
		g_var.env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_var.env[i] = NULL;
}

void	handle_signal(int sig)
{
	(void)sig;
	exit(0);// eksik tam çalışmıyor
}

void	env_export(char **envp)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (envp[len])
		len++;
	g_var.export_size = len;
	g_var.export = malloc(sizeof(char *) * (g_var.export_size + 1));
	while (envp[i])
	{
		g_var.export[i] = ft_strdup(envp[i]);
		i++;
	}
	g_var.export[i] = NULL;
}

void	null_init(void)
{
	g_var.str = NULL;
	g_var.env = NULL;
	g_var.pwd_new = NULL;
	g_var.export = NULL;
	g_var.cmd = NULL;
	g_var.path_env = NULL;
	g_var.pwd_new = NULL;
	g_var.cont = NULL;
}

void	all_free(void)
{
	int i;

	i = 0;   // pwd_new ve diğerleri freelenecek
	if (g_var.str)
		free_func(g_var.str);
	if (g_var.path_env)
		free_func(g_var.path_env);
	
}

void	control_char(void)
{
	int i;
	int j;
	int k;
	char	*a;
	link_list	*temp;

	i = 0;
	temp = g_var.lst;
	while (g_var.str[i])
	{
		j = 0;
		k = 0;
		//printf("%s\n", g_var.lst->content);
		if (temp->flag == '"')
		{
			while (g_var.str[i][k])
			{
				if (g_var.str[i][k] == '$')
				{
					k++;
					if (!g_var.str[i][k])
						return;
					a = malloc(sizeof(char) * (ft_strlen(g_var.str[i]) - k + 1));
					while (g_var.str[i][k])
					{
						a[j] = g_var.str[i][k];
						k++;
					}
					if (find_in_env(a))
					{
						printf("%s", find_in_env(a));
					}
					
				}
				
			}
			
		}
		i++;
	}
	
}

int main (int ac , char **av, char **envp)
{
    char	*mshell;
	int i;
	
	null_init();
	env_malloc(envp);
	env_export(envp);
    while (1)
    {
        mshell = readline("minishell $ ");
		if(mshell == NULL)
			break;
        add_history(mshell);
        start_parser(mshell);
		command_prepare();
		//control_char();
		i = command_built();
		if (i)
		{
			path_splt();
			exec_init();
		}
		




		
		//all_free();
    }
}