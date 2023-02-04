#include "../include/push_swap.h"

void	sorting(int *stack_a, int *stack_b, int size_a)
{
	int size_b;
	int	index;
	int	key;

	size_b = 0;
	index = 1;
	key = size_a - 1;
	while (key--)
	{
		if (stack_a[0] > stack_a[index])
		{
			ft_pb(stack_a, stack_b, &size_a, &size_b);
			index--;
		}
		index++;
	}

	while (size_a)
		printf("%d\n", stack_a[--size_a]);
	printf("-----\n");
	while (size_b)
		printf("%d\n", stack_b[--size_b]);
}