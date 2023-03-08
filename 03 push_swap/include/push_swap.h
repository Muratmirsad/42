/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:42 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/09 00:12:20 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct stack_holder
{
	int	*stack_a;
	int	*stack_b;
	int	*dest_a;
	int	*dest_b;
	int	size_a;
	int	size_b;
	int	size_da;
	int	size_db;
	int	size;
	int	biggest;
}	t_stack_holder;

void	ft_error(int code);
int		*read_arg(char **av, int *size, int i, int cnt);
void	sorting(int *stack_a, int *stcak_b, int size_a);
int		*convert(const int *stack, int *dest, int size, int *smaller);
int		*sorting_bubble(int *stack, int size);
void	sorting_small_stack(int *stack, int size, int *stack_b);
void	sorting_big_stack(t_stack_holder *all, int bit, int bit_key, int key);
void	push_back(t_stack_holder *all, int i, int j, int x);
int		sort_control_main(int *stack, int size);
int		*convert_to_intp(long *lp, int size);
void	ft_intcontrol(long *ip, int size);
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
void	dest_p(int *from, int *to, int *from_size, int *to_size);
void	dest_ss(int *ip);
void	dest_r(int *ip, int cnt);
void	dest_rr(int *ip, int cnt);

#endif