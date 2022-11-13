/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:52:57 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/13 16:52:57 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dest_size)
{
	size_t	len_size;
	size_t	i;

	len_size = ft_strlen(src);
	i = 0;
	if (dest_size == 0)
		return (len_size);
	while (*dst && dest_size)
	{
		dst++;
		dest_size--;
		i++;
	}
	while (*src && dest_size > 1)
	{
		*dst++ = *src++;
		dest_size--;
	}
	if (dest_size != 0)
		*dst = '\0';
	return (len_size + i);
}
