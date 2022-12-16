/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:07:57 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 14:07:57 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		*((unsigned char *)str + index) = 0;
		index++;
	}
}
