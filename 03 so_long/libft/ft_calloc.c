/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:08:24 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 14:08:24 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t numberofelements, size_t sizeofelements)
{
	char	*str;
	size_t	i;

	i = 0;
	if (numberofelements == 0 || sizeofelements == 0)
		str = (char *)malloc(1);
	else
		str = (char *)malloc(numberofelements * sizeofelements);
	if (!str)
		return (0);
	str[0] = 0;
	while (i < (numberofelements * sizeofelements))
	{
		*(str + i) = 0;
		i++;
	}
	return (str);
}
