/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:42:48 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/20 14:19:27 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		till_i_collapse;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	till_i_collapse = ft_strlen(s1) - 1;
	while (till_i_collapse && ft_strchr(set, s1[till_i_collapse]))
		till_i_collapse--;
	result = ft_substr(s1, 0, till_i_collapse + 1);
	if (result == NULL)
		return (0);
	return (result);
}
