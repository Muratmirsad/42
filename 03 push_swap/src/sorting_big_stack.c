/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:11:20 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/01 22:03:05 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_bit(int nb)
{
	int	bit;

	bit = 0;
	while (nb)
	{
		nb /= 2;
		bit++;
	}
	return (--bit);
}

void	sorting_big_stack(t_stack_holder *all, int bit, int bit_key, int key)
{
	bit_key = find_bit(all->biggest);
	while (bit <= bit_key)
	{
		key = all->size_a;
		while (key)
		{
			if ((all->dest_a[0] >> bit) % 2 == 0)
			{
				dest_pb(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
				ft_pb(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
			}
			else
			{
				dest_ra(all->dest_a, all->size_da);
				ft_ra(all->stack_a, all->size_a);
			}
			key--;
		}
		while (all->size_b)
		{
			dest_pa(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
			ft_pa(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
		}
		bit++;
	}
}
