/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:35:37 by uasci             #+#    #+#             */
/*   Updated: 2022/11/10 13:38:16 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *str1, size_t c)
{
	size_t	i ;

	i = 0;
	while ((str[i] != '\0' || str1[i] != '\0') && i < c)
	{
		if (str[i] != str1[i])
			return ((unsigned char)str[i] - (unsigned char)str1[i]);
		i++;
	}
	return (0);
}
