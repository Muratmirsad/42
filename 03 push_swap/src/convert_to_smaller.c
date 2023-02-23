#include "../include/push_swap.h"

int	*convert_to_smaller(const int *stack, int *dest, int size, int *smaller)
{
	int	i;
	int	j;

	smaller = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while(j < size)
		{
			if (dest[i] == stack[j])
				smaller[i] = j;
			j++;
		}
		i++;
	}
	free(dest);
	return (smaller);
}
