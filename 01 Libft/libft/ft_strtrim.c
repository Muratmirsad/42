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

char    *ft_strtrim(char const *str, char const *cut)
{
	size_t	i;

	if (!str || !cut)
		return (0);
	while (*str && ft_strchr(cut, *str))
		str++;
	i = ft_strlen(str);
	while (i && ft_strchr(cut, str[i]))
		i--;
	return (ft_substr(str, 0, i + 1));
}
