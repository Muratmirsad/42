# include "libftprintf.h"

static int	ft_control(const char *str)
{
	int	i;
	int	rei;

	i = 0;
	rei = 0;
	while(*(str + i))
	{
		if(*(str + i) == '%')
		{
			if(*(str + i + 1) == 'd' || *(str + i + 1) == 's')
				rei++;
		}
		i++;
	}
	return (rei);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rei;
	va_list ar;

	i = 0;
	rei = ft_control(str);
	va_start(ar, rei);
	while (*(str + i))
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			ft_putnbr(va_arg(ar, int), i++);
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr(va_arg(ar, char*), i++);
		else
			ft_putchar(str[i], i);
		i++;
	}
	/*
	yer kalmaz ise

	else if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr(va_arg(ar, char*), i++);

	yap
	*/
	printf("\n");
	return (0);
}


/*int	main()
{
	int i = 974259232;
	char *str = "kasfjıojıofnsısnaf    hdasıojhdsaıjdsa";

	ft_printf("%d  s%%%s", i, str);

	return (0);
}*/