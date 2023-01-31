/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:42 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/31 19:37:28 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	ft_error(int code);
int		*read_arg(char **av, int *size);
void	ft_pa(int *ipa, int *ipb, int *cnta, int *cntb);
void	ft_pb(int *ipa, int *ipb, int *cnta, int *cntb);
void	ft_ra(int *ip, int cnt);
void	ft_rb(int *ip, int cnt);
void	ft_rr(int *ipa, int *ipb, int cnta, int cntb);
void	ft_rra(int *ip, int cnt);
void	ft_rrb(int *ip, int cnt);
void	ft_rrr(int *ipa, int *ipb, int cnta, int cntb);
void	ft_sa(int *ip);
void	ft_sb(int *ip);
void	ft_ss(int *ip1, int *ip2);

#endif