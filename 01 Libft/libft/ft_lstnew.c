/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:42:00 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 16:59:32 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rcontent;

	rcontent = (t_list *)malloc(sizeof(t_list *));
	if (!rcontent)
		return (0);
	rcontent->content = content;
	rcontent->next = 0;
	return (rcontent);
}
