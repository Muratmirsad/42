/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:34:32 by bkarlida          #+#    #+#             */
/*   Updated: 2022/10/26 17:59:01 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*nstr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	nstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!nstr)
		return (0);
	while (i < len)
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
