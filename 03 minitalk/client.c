/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:20:52 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/12 17:28:47 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_sent()
{
	ft_printf("Signal sent successfully.\n");
}

static void	ft_signal(int pid, char c, int bits, int a_bit)
{
	while (bits >= 0)
	{
		a_bit = c >> bits--;
		if (a_bit % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ar, char **av)
{
	int	pid;
	int	i;

	if (ar != 3)
		return (0);
	i = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_signal_sent);
	while (av[2][i])
		ft_signal(pid, av[2][i++], 7, 0);
	ft_signal(pid, 10, 7, 0);
	usleep(10000);
}
