/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:21:09 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/11 17:21:09 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;

	if (dest_size)
	{
		i = 0;
		while (i < dest_size - 1 && src[i])
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = 0;
	}
	i = ft_strlen(src);
	return (i);
}
