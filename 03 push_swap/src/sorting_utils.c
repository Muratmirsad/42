/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:10:34 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/01 21:57:30 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_push(int *ip1, int *ip2, int cnt1, int cnt2)
{
	ft_memmove(ip1 + 1, ip1, cnt1 * 4);
	*(ip1) = *(ip2);
	ft_memmove(ip2, ip2 + 1, cnt2 * 4);
}

void	dest_pa(int *ipa, int *ipb, int *cnta, int *cntb)
{
	if (!cntb)
		return ;
	ft_push(ipa, ipb, *cnta, *cntb);
	*cnta += 1;
	*cntb -= 1;
}

void	dest_pb(int *ipa, int *ipb, int *cnta, int *cntb)
{
	if (!cnta)
		return ;
	ft_push(ipb, ipa, *cntb, *cnta);
	*cntb += 1;
	*cnta -= 1;
}

void	dest_ss(int *ip)
{
	int	tmp;

	tmp = ip[0];
	ip[0] = ip[1];
	ip[1] = tmp;
}

void	dest_ra(int *ip, int cnt)
{
	int	tmp;

	tmp = ip[0];
	ft_memmove(ip, ip + 1, (cnt - 1) * 4);
	ip[cnt - 1] = tmp;
}
