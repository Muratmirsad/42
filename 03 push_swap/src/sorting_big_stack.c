/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:42 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/09 00:25:04 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_up(t_stack_holder *all, int x, int xnb)
{
	if (!all->size_da)
		return ;
	while (all->dest_a[0] >= x * (all->size / xnb))
	{
		dest_r(all->dest_a, all->size_da);
		ft_ra(all->stack_a, all->size_a);
	}
	dest_p(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
	ft_pb(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
}

static void	ft_down(t_stack_holder *all, int x, int xnb)
{
	if (!all->size_da)
		return ;
	while (all->dest_a[0] >= x * (all->size / xnb))
	{
		dest_rr(all->dest_a, all->size_da);
		ft_rra(all->stack_a, all->size_a);
	}
	dest_p(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
	ft_pb(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
}

int	ft_xnb(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 200)
		return (7);
	else if (size <= 300)
		return (8);
	else if (size <= 400)
		return (10);
	else if (size <= 500)
		return (11);
	return (12);
}

void	sorting_big_stack(t_stack_holder *all, int i, int j, int x)
{
	int	k;
	int	xnb;

	xnb = ft_xnb(all->size);
	if (!(all->size / 5))
		all->size = 5;
	while (all->size_da)
	{
		k = all->size / xnb;
		while (k-- && all->size_da)
		{
			i = 0;
			j = all->size_da - 1;
			while (i < all->size_da && all->dest_a[i] >= x * (all->size / xnb))
				i++;
			while (j >= 0 && all->dest_a[j] >= x * (all->size / xnb))
				j--;
			if (i > all->size_da - j - 1 && all->size_a)
				ft_down(all, x, xnb);
			else if (all->size_a)
				ft_up(all, x, xnb);
		}
		x++;
	}
	push_back(all, 0, 0, 1);
}
