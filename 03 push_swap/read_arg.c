#include "push_swap.h"

void	ft_convert(int nb)
{
	int	*int_p;
	int_p = ft_intjoin(int_p, nb);
}

int	ft_factor(char *p, int i)
{
	if ((p[i] == 43 || p[i] == 45) &&
		!(p[i + 1] >= 48 && p[i + 1] <= 57))
		ft_error(1);
	if (p[i] == 45)
		return (-1);
	return (1);
}
//                           0          1        0
int *ft_handle(char *p, int i, int factor, int nb)
{
	int	key;

	while (p[i])
	{
		key = 0;
		if (p[i] == 43 || p[i] == 45)
			factor = ft_factor(p, i++);
		while (p[i] >= 48 && p[i] <= 57)
		{
			nb *= 10;
			nb += p[i++] - 48;
			key = 1;
		}
		
		if (key)
			ft_convert(nb * factor);
		factor = 1;
		nb = 0;
		i++;
	}
}

void	ft_control(char *p)
{
	int	i;

	i = 0;
	while ((p[i] == 32 || p[i] == 43 || p[i] == 45) ||
			(p[i] >= 48 && p[i] <= 57))
		i++;
	if (p[i])
		ft_error(2);
}

int	read_arg(char **av)
{
	char	*p;
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (av[i])
	{
		p = ft_strjoin(p, av[i++]);
		p = ft_strjoin(p, " ");
		cnt++;
	}
	ft_control(p);
	ft_handle(p, 0, 1, 0);
	return (cnt);
}

int main(int ar, char **av)
{
	(void)ar;
	read_arg(av);
}