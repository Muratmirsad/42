/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:03:56 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/08 02:47:22 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		r;
	va_list	ar;

	va_start(ar, str);
	i = 0;
	r = 0;
	while (*(str + i))
	{
		if (str[i] == '%' && str[i + 1] == '%')
			r += ft_putchar(str[i++], 0);
		else if (str[i] == '%' && str[i + 1] == 'c')
			r += ft_putchar(va_arg(ar, int), i++);
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			r += ft_putnbr(va_arg(ar, int), i++);
		else if (str[i] == '%' && str[i + 1] == 's')
			r += ft_putstr(va_arg(ar, char *), i++);
		else if (str[i] == '%' && str[i + 1] == 'u')
			r += ft_putunsigned(va_arg(ar, unsigned int), i++);
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
			r += ft_puthexadecimal(va_arg(ar, unsigned int), (int)str[++i]);
		else if (str[i] == '%' && str[i + 1] == 'p')
			r += ft_putpointer(va_arg(ar, unsigned long long), i++);
		else if (!(str[i] == '%'))
			r += ft_putchar(str[i], i);
		i++;
	}
	va_end(ar);
	return (r);
}
