# include "libftprintf.h"

void	ft_putchar(const char c, int i)
{
	(void)i;
	write(1, &c, 1);
}