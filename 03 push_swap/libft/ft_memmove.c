/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:45:10 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 15:45:10 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;

	if (dest == src || !len)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < len)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			*((unsigned char *)dest + len - 1)
				= *((unsigned char *)src + len - 1);
			len--;
		}
	}
	return (dest);
}
