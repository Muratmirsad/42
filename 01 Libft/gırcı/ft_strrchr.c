/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:16:51 by uasci             #+#    #+#             */
/*   Updated: 2022/10/22 18:59:41 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include<stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			ptr = (char *)(s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		ptr = (char *)(s + i);
	return (ptr);
}
