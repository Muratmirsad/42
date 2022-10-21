#include "libft.h"

void    *ft_convert(char *rstr, int number, int factor, int x)
{
    while (factor > 0)
    {
        *(rstr + factor + x) = (number % 10) + 48;
        number /= 10;
        factor--;
    }
}

int ft_control(int number, int factor)
{
    while (number > 9)
    {
        number /= 10;
        factor += 1;
    }
    return (factor);
}

char *ft_itoa(int number)
{
    int     i;
    int     factor;
    char    *rstr;
    int     x;

    x = 0;
    if (number < 0)
    {
        x = 1;
        number *= -1;
    }
    i = 0;
    factor = 1;
    factor = ft_control(number, factor);
    rstr = (char *)malloc(factor + x + 1);
    if (!rstr)
        return (0);
    ft_convert(rstr, number, factor, x);
    if (x == 1)
        *(rstr) = '-';
    *(rstr + factor + x + 1) = 0;
    return (rstr);
}