# include "libftprintf.h"

void	ft_putunsigned(unsigned int nb, int i)
{
	(void)i;
	if (nb > 9)
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