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
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

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
}		new_stack_holder;


void	ft_error(int code);
int		*read_arg(char **av, int *size);
void	sorting(int *stack_a, int *stcak_b, int size_a);
int		*convert_to_smaller(const int *stack, int *dest, int size, int *smaller);
int		*sorting_bubble(int *stack, int size);
void	sorting_small_stack(int *stack, int size);
void	sorting_big_stack(new_stack_holder *all_stack);
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
void	dest_pa(int *ipa, int *ipb, int *cnta, int *cntb);
void	dest_pb(int *ipa, int *ipb, int *cnta, int *cntb);
void	dest_ss(int *ip);
void	dest_ra(int *ip, int cnt);
void	dest_rb(int *ip, int cnt);

#endif