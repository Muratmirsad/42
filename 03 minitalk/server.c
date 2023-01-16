/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:21:02 by mdiraga           #+#    #+#             */
/*   Updated: 2023/01/13 16:25:38 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_control(int cpid, int c)
{
	if (c == 10)
		kill(cpid, SIGUSR1);
}

static void	ft_run(int sig, siginfo_t *info, void *context)
{
	static int	bits = 7;
	static int	cpid;
	static char	c;

	(void)context;
	cpid = info->si_pid;
	if (sig == SIGUSR1)
		bits--;
	else if (sig == SIGUSR2)
		c += 1 << bits--;
	if (bits < 0)
	{
		write(1, &c, 1);
		if (bits == -1)
			ft_control(cpid, c);
		c = 0;
		bits = 7;
	}
}

int	main(void)
{
	struct sigaction	keep_signal;

	ft_printf("server pid: %d\n", getpid());
	keep_signal.sa_sigaction = ft_run;
	keep_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &keep_signal, 0);
	sigaction(SIGUSR2, &keep_signal, 0);
	while (1)
		pause();
}