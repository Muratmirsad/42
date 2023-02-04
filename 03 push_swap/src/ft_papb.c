/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_papb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:28 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/31 19:34:47 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_push(int *ip1, int *ip2, int cnt1, int cnt2)
{
	ft_memmove(ip1 + 1, ip1, cnt1 * 4);
	*(ip1) = *(ip2);
	ft_memmove(ip2, ip2 + 1, cnt2 * 4);
}

void	ft_pa(int *ipa, int *ipb, int *cnta, int *cntb)
{
	if (!cntb)
		return ;
	ft_push(ipa, ipb, *cnta, *cntb);
	printf("pa\n");
	*cnta += 1;
	*cntb -= 1;
}

void	ft_pb(int *ipa, int *ipb, int *cnta, int *cntb)
{
	if (!cnta)
		return ;
	ft_push(ipb, ipa, *cntb, *cnta);
	printf("pb\n");
	*cntb += 1;
	*cnta -= 1;
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
	ft_pb(ip1, ip2, &a, &b);

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

/*

░░░░░█▀▀▀░█▀▀█░█▀▀▀░█░█░░░░░░
░░░░░█▀▀░░█▀▀█░▀▀▀█░▀█▀░░░░░░
░░░░░▀▀▀▀░▀░░▀░▀▀▀▀░░▀░░░░░░░
▀█▀░█░█░▀█▀░█▀█░█▀▀▄░█░█▀▀█░█░░
░█░░█░█░░█░░█░█░█▀▀█░█░█▀▀█░█░░
░▀░░▀▀▀░░▀░░▀▀▀░▀░░▀░▀░▀░░▀░▀▀░

*/