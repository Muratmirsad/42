/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:32:12 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/08 18:17:18 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*convert(const int *stack, int *dest, int size, int *smaller)
{
	int	i;
	int	j;

	smaller = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (dest[i] == stack[j])
				smaller[j] = i;
			j++;
		}
		i++;
	}
	free(dest);
	return (smaller);
}
