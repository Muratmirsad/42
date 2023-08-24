/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrarrbrrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:33:02 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/01 21:33:05 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_rotate(int *ip, int cnt)
{
	int	tmp;

	tmp = ip[cnt - 1];
	ft_memmove(ip + 1, ip, (cnt - 1) * 4);
	ip[0] = tmp;
}

void	ft_rra(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(int *ipa, int *ipb, int cnta, int cntb)
{
	ft_rotate(ipa, cnta);
	ft_rotate(ipb, cntb);
	ft_putstr_fd("rrr\n", 1);
}
