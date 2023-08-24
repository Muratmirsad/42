/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:38:40 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 12:38:40 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*rstr;

	if (!str)
		return (0);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	rstr = (char *)malloc(len + 1);
	if (!(rstr))
		return (0);
	i = 0;
	while (len > 0 && *(str + start))
	{
		*(rstr + i) = *(str + start);
		i++;
		start++;
		len--;
	}
	*(rstr + i) = 0;
	return (rstr);
}
