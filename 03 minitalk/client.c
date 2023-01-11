#include "minitalk.h"

void	ft_ok(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Process Successful");
}

static void	ft_signal(int pid, char c, int bits, int a_bit)
{
	while (bits >= 0)
	{
		a_bit = c>>bits--;
		if (a_bit % 2 == 0)
		{
			ft_printf("0");
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_printf("1");
			kill(pid, SIGUSR2);
		}
		usleep(100);
	}
}

int	main(int ar, char **av)
{
	int	pid;
	int	i;

	if (ar != 3)
		return (0);
	(void)ar;
	pid = ft_atoi(av[1]);
	i = 0;
	signal(SIGUSR1, ft_ok);
	while (av[2][i])
		ft_signal(pid, av[2][i++], 7, 0);
	ft_signal(pid, 10, 7, 0);
	ft_printf("\n");
}