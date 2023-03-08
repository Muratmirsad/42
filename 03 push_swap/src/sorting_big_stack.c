#include "../include/push_swap.h"

static void	ft_up(t_stack_holder *all, int x)
{
	if (!all->size_da)
		return ;
	while (all->dest_a[0] >= x * (all->size / 5))
	{
		dest_r(all->dest_a, all->size_da);
		ft_ra(all->stack_a, all->size_a);
	}
	dest_p(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
	ft_pb(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
}

static void	ft_down(t_stack_holder *all, int x)
{
	if (!all->size_da)
		return ;
	while (all->dest_a[0] >= x * (all->size / 5))
	{
		dest_rr(all->dest_a, all->size_da);
		ft_rra(all->stack_a, all->size_a);
	}
	dest_p(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
	ft_pb(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
}

void	sorting_big_stack(t_stack_holder *all, int i, int j, int x)
{
	int	k;

	if (!(all->size / 5))
		all->size = 5;
	while (all->size_da)
	{
		k = all->size / 5;
		while (k-- && all->size_da)
		{
			i = 0;
			j = all->size_da - 1;
			while (i < all->size_da && all->dest_a[i] >= x * (all->size / 5))
				i++;
			while (j >= 0 && all->dest_a[j] >= x * (all->size / 5))
				j--;
			if (i > all->size_da - j - 1 && all->size_a)
				ft_down(all, x);
			else if (all->size_a)
				ft_up(all, x);
		}
		x++;
	}
	push_back(all, 0, 0, 1);
}
