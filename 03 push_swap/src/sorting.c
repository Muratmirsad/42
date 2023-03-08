/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:05:55 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/01 22:09:00 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting(int *stack_a, int *stack_b, int size_a)
{
	t_stack_holder	*all_stack;
	int				*dest;
	int				*dest2;

	all_stack = 0;
	all_stack = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	dest = sorting_bubble(stack_a, size_a);
	all_stack->biggest = dest[size_a - 1];
	dest = convert(stack_a, dest, size_a, 0);
	dest2 = (int *)malloc(sizeof(int) * size_a);
	all_stack->stack_a = stack_a;
	all_stack->stack_b = stack_b;
	all_stack->dest_a = dest;
	all_stack->dest_b = dest2;
	all_stack->size_a = size_a;
	all_stack->size_b = 0;
	all_stack->size_da = size_a;
	all_stack->size_db = 0;
	all_stack->size = size_a;
	sorting_big_stack(all_stack, 0, 0, 1);
	free(all_stack->dest_a);
	free(all_stack->dest_b);
	free(all_stack);
}
