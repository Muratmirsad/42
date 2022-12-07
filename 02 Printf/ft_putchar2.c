# include "ft_printf.h"

void	ft_putchar2(const char *str, int i)
{
	(void)i;
	write(1, &str[0], 1);
}