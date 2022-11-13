/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:14:31 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/13 18:14:31 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *str, unsigned int start, size_t len)
{
    unsigned int    i;
    char            *p;

    p = (char *)malloc(len + 1);
    if (!(p))
        return (0);
    i = 0;
    while (len > 0)
    {
        *(p + i) = *(str + start);
        i++;
        start++;
        len--;
	}
	*(p + i) = 0;
    return (p);
}
