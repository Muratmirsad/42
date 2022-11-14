/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:43:25 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 15:43:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr, const void *find, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((const unsigned char *)ptr + i)
			!= *((const unsigned char *)find + i))
			return (*((const unsigned char *)ptr + i)
				- *((const unsigned char *)find + i));
		i++;
	}
	return (0);
}
