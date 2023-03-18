#include "../include/so_long.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	system("leaks a.out");
	exit(1);
}