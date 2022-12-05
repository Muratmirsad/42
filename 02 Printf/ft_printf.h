#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdio.h"
# include "unistd.h"

int	    ft_printf(const char *str, ...);
void	ft_putunsigned(unsigned int nb, int i);
void	ft_puthexadecimal(unsigned int nb, int c);
void	ft_putstr(const char *str, int i);
void	ft_putchar(const char c, int i);
void	ft_putnbr(int nb, int i);

#endif
