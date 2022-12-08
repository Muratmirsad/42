/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:02:56 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/08 02:45:53 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putunsigned(unsigned int nb, int i);
int		ft_puthexadecimal(unsigned long long nb, int c);
int		ft_putpointer(unsigned long long p, int c);
int		ft_putstr(const char *str, int i);
int		ft_putchar(const char c, int i);
int		ft_putnbr(long long nb, int i);
char	*ft_itoa(int number);
void	ft_putchar2(const char *str, int i);

#endif
