# include "ft_printf.h"

static void	ft_put(int nb)
{
	nb = nb - 23;
	write(1, &nb, 1);
}

void	ft_putr(int nb)
{
	if (nb > 16)
	{
		ft_putr(nb / 16);
		ft_putr(nb % 16);
	}
	else if (nb >= 10)
		ft_put(nb % 10);
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}

void	ft_putpointer(char *p, int nb)
{
	ft_strdup(&p);
	ft_putr(nb);
}