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

char    *ft_strjoin(const char *s1, const char *s2)
{
    unsigned int    is;
    unsigned int    irstr;
    char            *rstr;

	if (!s1 || !s2)
		return (0);
    is = ft_strlen(s1);
    is += ft_strlen(s2);
    rstr = (char *)malloc(is + 1);
    if (!(rstr))
        return (0);
    is = 0;
    irstr = 0;
    while (*(s1 + is))
    {
        *(rstr + irstr) = *(s1 + is);
        irstr++;
        is++;
    }
    is = 0;
    while (*(s2 + is))
    {
        *(rstr + irstr) = *(s2 + is);
        irstr++;
        is++;
    }
	*(rstr + irstr) = 0;
    return (rstr);
}