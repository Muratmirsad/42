#include "../include/push_swap.h"

void	sorting(int *stack_a, int *stack_b, int size_a)
{
	int size_b;
	int	key;
	int	nb;

	size_b = 0;
	nb = stack_a[size_a / 2];
	key = size_a;
	while (key--)
	{
		if (stack_a[0] > nb)
			ft_pb(stack_a, stack_b, &size_a, &size_b);
		else
			ft_ra(stack_a, size_a);
	}
	sorting_2(stack_a, stack_b, size_a, size_b);
	while (size_b)
	{
		ft_pa(stack_a, stack_b, &size_a, &size_b);
		ft_ra(stack_a, size_a);
	}
	/*key = size_a;
	while (key)
		printf("%d\n", stack_a[size_a - key--]);
	printf("-----\n");
	key = size_b;
	while (key)
		printf("%d\n", stack_b[size_b - key--]);*/
}