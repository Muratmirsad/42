/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:11:41 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/13 18:11:41 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*rstr;

	i = ft_strlen(str);
	rstr = (char *)malloc(i + 1);
	if (!rstr)
		return (0);
	i = 0;
	while (*(str + i))
	{
		*(rstr + i) = *(str + i);
		i++;
	}
	*(rstr + i) = 0;
	return (rstr);
}
