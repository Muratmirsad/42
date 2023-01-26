#include "push_swap.h"

static void	ft_swap(int *ip)
{
	int	tmp;

	tmp = ip[0];
	ip[0] = ip[1];
	ip[1] = tmp;
}

void	ft_sa(int *ip)
{
	ft_swap(ip);
	ft_printf("sa\n");
}

void	ft_sb(int *ip)
{
	ft_swap(ip);
	ft_printf("sb\n");
}