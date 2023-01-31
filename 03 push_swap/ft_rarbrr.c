#include "push_swap.h"

static void ft_rotate(int *ip, int cnt)
{
	int	tmp;

	tmp = ip[0];
	ft_memmove(ip, ip + 1, (cnt - 1) * 4);
	ip[cnt - 1] = tmp;
}

void	ft_ra(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	printf("ra\n");
}

void	ft_rb(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	printf("rb\n");
}

void	ft_rr(int *ipa, int *ipb, int cnta, int cntb)
{
	ft_rotate(ipa, cnta);
	ft_rotate(ipb, cntb);
	printf("rr\n");
}
