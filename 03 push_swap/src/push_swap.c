/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:48 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/09 00:12:37 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ar, char **av)
{
	int	size;
	int	*stack_a;
	int	*stack_b;

	if (ar < 2)
		return (0);
	stack_a = read_arg(av, &size, 0, 1);
	if (size < 2)
		return (0);
	if (sort_control_main(stack_a, size))
		return (0);
	stack_b = ft_calloc(size, sizeof(int));
	if (size <= 5)
		sorting_small_stack(stack_a, size, stack_b);
	else
		sorting(stack_a, stack_b, size);
	free(stack_b);
}

// int max error dönecek