/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:47:08 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/22 16:47:12 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_it_special(char c)
{
	if (c == ' ' || c == 9 || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

int	link_lstsize(t_ink_list *lst)
{
	int			i;
	t_ink_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

char	*cut_helper(const char *str)
{
	char	*rstr;
	int		i;

	i = ft_strlen(str) - 1;
	rstr = (char *)malloc(i + 2);
	if (str[i] == '/')
		i--;
	while (i >= 0 && str[i] != '/')
		i--;
	ft_strlcpy(rstr, str, i + 1);
	if (ft_strlen(rstr) < 2)
		ft_strlcpy(rstr, "/", 2);
	return (rstr);
}

void	ft_pwd(void)
{
	char	p[256];

	getcwd(p, sizeof(p));
	printf("%s\n", p);
}

void	ft_env(void)
{
	int	i;

	i = 0;
	ft_pwd();
	while (g_var.env[i])
		printf("%s\n", g_var.env[i++]);
}
