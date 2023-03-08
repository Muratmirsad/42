/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:17 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/08 18:07:23 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_up(t_stack_holder *all, int nb)
{
	while (all->dest_b[0] != nb)
	{
		dest_r(all->dest_b, all->size_db);
		ft_rb(all->stack_b, all->size_b);
	}
	dest_p(all->dest_b, all->dest_a, &all->size_db, &all->size_da);
	ft_pa(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
}

static void	ft_down(t_stack_holder *all, int nb)
{
	while (all->dest_b[0] != nb)
	{
		dest_rr(all->dest_b, all->size_db);
		ft_rrb(all->stack_b, all->size_b);
	}
	dest_p(all->dest_b, all->dest_a, &all->size_db, &all->size_da);
	ft_pa(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
}

void	push_back(t_stack_holder *all, int i, int j, int x)
{
	int	k;
	int	nb;

	nb = all->size_b - 1;
	while (all->size_db)
	{
		k = all->size / 10;
		while (k-- && all->size_db)
		{
			i = 0;
			j = all->size_db - 1;
			while (i < all->size_db && all->dest_b[i] != nb)
				i++;
			while (j >= 0 && all->dest_b[j] != nb)
				j--;
			if (i > all->size_db - j - 1 && all->size_b)
				ft_down(all, nb--);
			else if (all->size_b)
				ft_up(all, nb--);
		}
		x++;
	}
}
