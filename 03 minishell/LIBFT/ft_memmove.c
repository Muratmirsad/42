/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:39:01 by bkarlida          #+#    #+#             */
/*   Updated: 2022/10/31 21:35:20 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	sourc = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		while (len > i)
		{
			dest[i] = sourc[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			dest[len] = sourc[len];
	}
	return (dest);
}
