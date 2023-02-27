#include "../include/push_swap.h"

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
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(int *ip)
{
	ft_swap(ip);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(int *ip1, int *ip2)
{
	ft_swap(ip1);
	ft_swap(ip2);
	ft_putstr_fd("ss\n", 1);
}
