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

void	sorting_big_stack(new_stack_holder *all)
{
	int	bit;
	int	bit_key;
	int	key;

	bit = 0;
	bit_key = find_bit(all->biggest);
	while (bit <= bit_key)
	{
		key = all->size_a;
		while (key)
		{
			if ((all->dest_a[0] >> bit) % 2 == 0)
			{
				printf("test -----> 1\n");
				dest_pb(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
				ft_pb(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
			}
			else
			{
				printf("test -----> 2\n");
				dest_ra(all->dest_a, all->size_da);
				ft_ra(all->stack_a, all->size_a);
			}
			printf("size da: %d\nsize db: %d\nsize a: %d\nsize b: %d\n", all->size_da, all->size_db, all->size_a, all->size_b);
			key--;
		}
		while (all->size_b)
		{
			printf("test -----> 3\n");
			dest_pa(all->dest_a, all->dest_b, &all->size_da, &all->size_db);
			ft_pa(all->stack_a, all->stack_b, &all->size_a, &all->size_b);
		}
		bit++;
	}
}
