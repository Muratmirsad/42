#include "minitalk.h"

void	ft_ok(int signal)
{
	if (signal == SIGUSR1) 
		ft_printf("Process Successful");
}

int	ft_atoi(char *str) 
{
	int	i;

	i = 0;
	while (*str) 
		i = (i * 10) + (*str++ - '0');
	return (i);
}

void	ft_procces(int pid, int c) // pid - pid of server, c - char
{
    // 8 bits in byte
	int				n;
	int				byt;
	unsigned char	ch;

	ch = c;
	byt = 8; 
	n = 128;
	while (byt--)
	{
		if (ch / n)
		{
			ch -= n;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(150);
		n /= 2;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		byt;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("You failed.\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	signal(SIGUSR1, ft_ok);
	while (msg[i])
	{
		ft_procces(pid, msg[i]);
		i++;
	}
	byt = 8;
	while (byt--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}