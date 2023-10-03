/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:31:24 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/16 14:32:02 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
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

static int	ft_add(const char *str, char *rstr, int irstr, int is)
{
	if (!str)
		return (0);
	while (*(str + is))
	{
		*(rstr + irstr) = *(str + is);
		irstr++;
		is++;
	}
	return (irstr);
}

char	*ft_strjoin_mod(char *s1, const char *s2)
{
	unsigned int	is;
	unsigned int	irstr;
	char			*rstr;

	is = 0;
	if (!s1 && !s2)
		return (0);
	if (s1)
		is += ft_strlen(s1);
	is += ft_strlen(s2);
	rstr = (char *)malloc(is + 1);
	if (!(rstr))
		return (0);
	irstr = ft_add(s1, rstr, 0, 0);
	irstr = ft_add(s2, rstr, irstr, 0);
	*(rstr + irstr) = 0;
	free(s1);
	return (rstr);
}
