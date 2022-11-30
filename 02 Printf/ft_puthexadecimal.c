# include "libftprintf.h"

static void	ft_put(int nb, int c)
{
	nb = nb - 23 + c;
	write(1, &nb, 1);
}

void	ft_puthexadecimal(unsigned int nb, int c)
{
	if (nb > 16)
	{
		ft_puthexadecimal(nb / 16, c);
		ft_puthexadecimal(nb % 16, c);
	}
	else if (nb >= 10)
		ft_put(nb % 10, c);
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}