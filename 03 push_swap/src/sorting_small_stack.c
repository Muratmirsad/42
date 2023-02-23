#include "../include/push_swap.h"

void	sorting_2and3_index(int *stack, int size)
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

void	sorting_small_stack(int *stack, int size)
{
	if (size <= 3)
		sorting_2and3_index(stack, size);
	else
	{
		
	}
}