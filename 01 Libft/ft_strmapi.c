/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:54:21 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 16:55:48 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rstr;

	if (!str || !f)
		return (0);
	rstr = (char *)malloc(ft_strlen(str) + 1);
	if (!rstr)
		return (0);
	i = 0;
	while (str[i])
	{
		rstr[i] = f(i, str[i]);
		i++;
	}
	rstr[i] = 0;
	return (rstr);
}
