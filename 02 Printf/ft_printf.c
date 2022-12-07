# include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list ar;

	va_start(ar, str);
	i = 0;
	while (*(str + i))
	{
		if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar(str[i++], 0);
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			ft_putnbr(va_arg(ar, int), i++);
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr(va_arg(ar, char*), i++);
		else if (str[i] == '%' && str[i + 1] == 'u')
			ft_putunsigned(va_arg(ar, unsigned int), i++);
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
			ft_puthexadecimal(va_arg(ar, unsigned int), (int)str[++i]);
		else if (str[i] == '%' && str[i + 1] == 'p')
			ft_putpointer(va_arg(ar, unsigned long long), i++);
		else if (!(str[i] == '%'))
			ft_putchar(str[i], i);
		i++;
	}
	va_end(ar);
	return (i);
}
