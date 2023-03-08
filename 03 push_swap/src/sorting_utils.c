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

void	dest_p(int *from, int *to, int *from_size, int *to_size)
{
	if (!from)
		return ;
	ft_memmove(to + 1, to, *to_size * 4);
	*(to) = *(from);
	ft_memmove(from, from + 1, *from_size * 4);
	*to_size += 1;
	*from_size -= 1;
}

void	dest_ss(int *ip)
{
	int	tmp;

	tmp = ip[0];
	ip[0] = ip[1];
	ip[1] = tmp;
}

void	dest_r(int *ip, int cnt)
{
	int	tmp;

	tmp = ip[0];
	ft_memmove(ip, ip + 1, (cnt - 1) * 4);
	ip[cnt - 1] = tmp;
}

void	dest_rr(int *ip, int cnt)
{
	int	tmp;

	tmp = ip[cnt - 1];
	ft_memmove(ip + 1, ip, (cnt - 1) * 4);
	ip[0] = tmp;
}
