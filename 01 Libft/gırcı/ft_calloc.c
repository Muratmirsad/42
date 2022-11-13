/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:56:58 by uasci             #+#    #+#             */
/*   Updated: 2022/10/24 11:45:48 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	a = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	a = (void *) malloc(size * count);
	if (!a)
		return (0);
	ft_bzero(a, size * count);
	return (a);
}
