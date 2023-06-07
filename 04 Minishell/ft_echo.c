/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:13:03 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/20 21:13:32 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo_is_null(char *str)
{
	int i;

	i = 0;
    
	if (!str[i])
    {
        
		return(0);
    }
	else if (str[i] == '-')
		i++;
	else
    {
		return(0);	
    }
	while (str[i])
	{
		if (str[i] != 'n')
		{
			if (str[i])
				return(0);
		}
		i++;
	}
	return(1);
}


void	ft_echo(int	k)
{
	int flag;

	flag = 1;
	k++;
	printf("-------Echo_komutu_çalıştı!------\n");
    if (g_var.lst_size == 1)
    {
        printf("\n");
        return;
    }
	while (ft_echo_is_null(g_var.str[k]))
	{
		flag = 0;
		if (g_var.lst_size == k + 1)
		{
			k++;
			break;
		}
		k++;
	}
    //printf("%s\n", g_var.str[k]);
	while (g_var.str[k])
	{
        
		if ((g_var.str[k][0] != '|' && g_var.str[k][0] != '<' && g_var.str[k][0] != '>'))
		{
			printf("%s", g_var.str[k]);
			if (g_var.str[k + 1])
			{
				printf(" ");
			}
			k++;
		}
		else
		{
			// henüz rdirect ve pipe yapılmadı onları atlayarak echo yazdırılıyor;
			if (g_var.str[k][0] == '|')
			{
				printf("--Pipe_Yapılmadı_Henüz--\n");
			}
			k++;
		}
	}
	if (flag)
		printf("\n");
}