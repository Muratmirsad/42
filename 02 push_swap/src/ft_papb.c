/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_papb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:28 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/01 21:32:34 by mdiraga          ###   ########.fr       */
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
	ft_putstr_fd("pa\n", 1);
	*cnta += 1;
	*cntb -= 1;
}

void	ft_pb(int *ipa, int *ipb, int *cnta, int *cntb)
{
	if (!cnta)
		return ;
	ft_push(ipb, ipa, *cntb, *cnta);
	ft_putstr_fd("pb\n", 1);
	*cntb += 1;
	*cnta -= 1;
}
