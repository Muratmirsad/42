/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:32:40 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 16:59:21 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*p;

	if (!lst)
		return (0);
	i = 1;
	p = lst;
	while (p->next)
	{
		i++;
		p = p->next;
	}
	return (i);
}
