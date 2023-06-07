/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:35:48 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/06 19:12:16 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	int i;

	i = 0;
	while (g_var.env[i])
    {
		printf("%s\n", g_var.env[i++]);
    }
	//printf("%d\n", g_var.env_size);
}

void    ft_pwd(void)
{
   	int i;
   	int j;
   	int k;
    char *a;

	i = 0;
	k = 4;
	printf("-------Pwd_komutu_çalıştı!------\n");
	while (g_var.env[i])
    {
        if (g_var.env[i][0] == 'P' && g_var.env[i][1] == 'W' && g_var.env[i][2] == 'D')
        {
			if (g_var.pwd_new != NULL)
			{
				//free(g_var.env[i]); // dikkat
				g_var.env[i] = g_var.pwd_new;
			}
            while (g_var.env[i][k])
            {
                printf("%c", g_var.env[i][k++]);
            }
            printf("\n");
            break;
        }
        i++;
    }
}
