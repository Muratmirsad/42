#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "stdarg.h"
# include "stdio.h"
# include "unistd.h"

int	    ft_printf(const char *str, ...);
void	ft_putunsigned(unsigned int nb, int i);
void	ft_putstr(const char *str, int i);
void	ft_putchar(const char c, int i);
void	ft_putnbr(int nb, int i);

#endif