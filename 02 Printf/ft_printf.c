# include "libftprintf.h"

static int	ft_control(const char *str)
{
	int	i;
	int	rei;

	i = 0;
	rei = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			if (*(str + i + 1) == 'd'
				|| *(str + i + 1) == 's'
				|| *(str + i + 1) == 'i'
				|| *(str + i + 1) == 'u')
				rei++;
		}
		i++;
	}
	return (rei);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list ar;

	i = ft_control(str);
	va_start(ar, i);
	i = 0;
	while (*(str + i))
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			ft_putnbr(va_arg(ar, int), i++);
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr(va_arg(ar, char*), i++);
		else if (str[i] == '%' && str[i + 1] == 'u')
			ft_putunsigned(va_arg(ar, unsigned int), i++);
		else
			ft_putchar(str[i], i);
		i++;
	}
	va_end(ar);
	write(1, "\n", 1);
	return (0);
}