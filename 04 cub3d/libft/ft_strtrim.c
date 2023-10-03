/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:37:01 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/13 19:37:01 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find(const char *str, int c)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (!c)
		return ((char *)(str + i));
	return (0);
}

char	*ft_strtrim(char const *str, char const *cut)
{
	size_t	i;

	if (!str || !cut)
		return (0);
	while (*str && ft_find(cut, *str))
		str++;
	i = ft_strlen(str);
	while (i && ft_find(cut, str[i]))
		i--;
	return (ft_substr(str, 0, i + 1));
}
