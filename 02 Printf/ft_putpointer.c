# include "ft_printf.h"

static void	ft_put(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put(num / 16);
		ft_put(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'), 1);
		else
			ft_putchar((num - 10 + 'a'), 1);
	}
}

void	ft_putpointer(unsigned long long p, int nb)
{
	ft_putstr("0x", nb);
	ft_put(p);
}