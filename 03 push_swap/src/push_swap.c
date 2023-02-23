/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:48 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/31 18:05:11 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ar, char **av)
{
	int	size;
	int	*stack_a;
	int	*stack_b;

	(void)ar;
	stack_a = read_arg(av, &size);
	if (size < 2)
		ft_error(4);
	stack_b = ft_calloc(size, sizeof(int));
	if (size <= 5)
		sorting_small_stack(stack_a, size);
	else
		sorting(stack_a, stack_b, size);
	free(stack_b);
	int i = 0;
	while (i < 3)
		printf("%d\n", stack_a[i++]);
}