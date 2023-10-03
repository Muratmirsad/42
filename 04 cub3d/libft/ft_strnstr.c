/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:27:41 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/13 17:27:41 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *dst, size_t len)
{
	size_t	i;
	int		b;

	i = 0;
	b = 0;
	if (!src && !dst)
		return (0);
	if (!dst[i])
	{
		return ((char *)src);
	}	
	while (i < len && src[i])
	{
		while (dst[b] && src[i + b] == dst[b] && i + b < len)
		{
			b++;
		}
		if (!dst[b])
		{
			return ((char *)(src + i));
		}
		i++;
	}
	return (0);
}
