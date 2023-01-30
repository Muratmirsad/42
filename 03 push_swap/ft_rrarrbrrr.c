#include "push_swap.h"

/*

				Tamamlandı.

*/

static void ft_rotate(int *ip, int cnt)
{
	int	i;
	int	tmp;

	tmp = ip[cnt - 1];
	ft_memmove(ip + 1, ip, (cnt - 1) * 4);
	ip[0] = tmp;
}

void	ft_rra(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	printf("rra\n");
}

void	ft_rrb(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	printf("rrb\n");
}

void	ft_rrr(int *ipa, int *ipb, int cnta, int cntb)
{
	ft_rotate(ipa, cnta);
	ft_rotate(ipb, cntb);
	printf("rrr\n");
}

/*
int	main()
{
	int *ip1 = (int*)malloc(20);
	ip1[0] = 1;
	ip1[1] = 2;
	ip1[2] = 3;
	ip1[3] = 4;
	int *ip2 = (int*)malloc(20);
	ip2[0] = 77;
	int i = 0;

	int a = 4;
	int b = 1;
	ft_rrr(ip1, ip2, a, b);

	i = 0;
	while (i < 5)
		printf("%d\n", ip1[i++]);
	printf("---\n");
	i = 0;
	while (i < 5)
		printf("%d\n", ip2[i++]);
	printf("---\n%d | %d\n", a, b);
}
*/