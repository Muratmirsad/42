# include "ft_printf.h"

void	ft_putnbr(int nb, int i)
{
	(void)i;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1, i);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}