/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:32:02 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/02 01:03:48 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sorting_2and3_index(int *stack, int size)
{
	if (stack[0] > stack[1])
		ft_sa(stack);
	if (size == 3)
	{
		if (stack[1] > stack[2])
			ft_rra(stack, size);
		if (stack[0] > stack[1])
			ft_sa(stack);
	}
}

static void	sorting_small2(int *stack, int *stack_b, int size, int size_b)
{
	int	*dest;

	dest = sorting_bubble(stack, size);
	while (1)
	{
		if (stack[0] == dest[0] || stack[0] == dest[1])
			ft_pb(stack, stack_b, &size, &size_b);
		else
			ft_ra(stack, size);
		if (size_b == 2)
			break ;
	}
	free(dest);
	sorting_2and3_index(stack, size);
	ft_pa(stack, stack_b, &size, &size_b);
	ft_pa(stack, stack_b, &size, &size_b);
	if (stack[0] > stack[1])
		ft_sa(stack);
}

void	sorting_small_stack(int *stack, int size, int *stack_b)
{
	if (size <= 3)
		sorting_2and3_index(stack, size);
	else
		sorting_small2(stack, stack_b, size, 0);
}
