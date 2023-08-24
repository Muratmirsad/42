/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:44:37 by bkarlida          #+#    #+#             */
/*   Updated: 2022/10/27 14:04:48 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = (char *)haystack;
	if (!*needle)
		return (result);
	i = 0;
	while (i < len && *(result + i))
	{
		j = 0;
		while (*(result + i + j) == *(needle + j) && i + j < len)
		{
			if (*(needle + j + 1) == '\0')
				return (result + i);
			j++;
		}
		i++;
	}
	return (0);
}
