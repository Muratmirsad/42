/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:48 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/31 18:05:11 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ar, char **av)
{
	int	size;

	if (ar < 2)
		ft_error(4);
		

	int *p;
	p = read_arg(av, &size);

	while (size-- > 0)
	{
		ft_printf("%d\n", p[size]);
	}
}