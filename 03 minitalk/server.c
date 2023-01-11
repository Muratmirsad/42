#include "minitalk.h"

static void	ft_run(int sig, siginfo_t *info, void *context)
{
	static int	bits = 7;
	static pid_t			client_pid = 0;
	static char	c;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		bits--;
	else if (sig == SIGUSR2)
		c += 1<<bits--;
	if (bits < 0)
	{
		write(1, &c, 1);
		c = 0;
		bits = 7;
	}
}

int	main()
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