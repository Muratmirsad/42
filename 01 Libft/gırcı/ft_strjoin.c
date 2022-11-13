/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:46:22 by uasci             #+#    #+#             */
/*   Updated: 2022/10/21 15:09:33 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*array;

	k = 0;
	i = 0;
	if (s1 != NULL)
	{
		array = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (array == NULL)
			return (NULL);
		while (s1[i])
		{
			array[i] = s1[i];
			i++;
		}
		while (s2[k] != '\0')
			array[i++] = s2[k++];
		array[i] = '\0';
		return (array);
	}
	return (0);
}
