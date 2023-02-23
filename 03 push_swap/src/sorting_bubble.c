#include "../include/push_swap.h"

int	*sorting_bubble(int *stack, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	*dest;

	dest = (int*)malloc(sizeof(int) * size);
	dest = ft_memcpy(dest, stack, size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (dest[i] > dest[j])
			{
				tmp = dest[i];
				dest[i] = dest[j];
				dest[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (dest);
}