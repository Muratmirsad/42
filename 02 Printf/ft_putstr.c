# include "libftprintf.h"

void	ft_putstr(const char *str, int i)
{
	i = 0;
	while (*(str + i))
	{
		write(1, &str[i], 1);
		i++;
	}
}