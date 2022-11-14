/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:32:02 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/13 18:32:02 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_add(const char *str, char *rstr, int irstr, int is)
{
	while (*(str + is))
	{
		*(rstr + irstr) = *(str + is);
		irstr++;
		is++;
	}
	return (irstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	is;
	unsigned int	irstr;
	char			*rstr;

	if (!s1 || !s2)
		return (0);
	is = ft_strlen(s1);
	is += ft_strlen(s2);
	rstr = (char *)malloc(is + 1);
	if (!(rstr))
		return (0);
	irstr = ft_add(s1, rstr, 0, 0);
	irstr = ft_add(s2, rstr, irstr, 0);
	*(rstr + irstr) = 0;
	return (rstr);
}
