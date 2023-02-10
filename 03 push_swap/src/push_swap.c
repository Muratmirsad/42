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

	if (ar < 2)
		ft_error(4);
	stack_a = read_arg(av, &size);
	stack_b = ft_calloc(size, sizeof(int));
	sorting(stack_a, stack_b, size);
	free(stack_b);
}