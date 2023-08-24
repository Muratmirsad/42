/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:33:52 by bkarlida          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:17 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*result;	

	c = (unsigned char)c;
	i = ft_strlen(str);
	result = (char *)str;
	if (c == 0)
		return (&result[i]);
	while (i >= 0)
	{
		if (result[i] == c)
			return (&result[i]);
		if (i > 0)
			i--;
		else
			break ;
	}
	return (0);
}
