/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarbrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:32:42 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/01 21:32:51 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_rotate(int *ip, int cnt)
{
	int	tmp;

	tmp = ip[0];
	ft_memmove(ip, ip + 1, (cnt - 1) * 4);
	ip[cnt - 1] = tmp;
}

void	ft_ra(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(int *ip, int cnt)
{
	ft_rotate(ip, cnt);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(int *ipa, int *ipb, int cnta, int cntb)
{
	ft_rotate(ipa, cnta);
	ft_rotate(ipb, cntb);
	ft_putstr_fd("rr\n", 1);
}
