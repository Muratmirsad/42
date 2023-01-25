#include "push_swap.h"

void	ft_error(int code)
{
	if (code == 1)
	{
		printf("error code: %d\n", code);
		exit(1);
	}
	else if (code == 2)
	{
		printf("error code: %d\n", code);
		exit(2);
	}
}