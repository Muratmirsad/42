#include "libft.h"

void    ft_striteri(char *str, void (*f)(unsigned int, char*))
{
    int i;

    i = 0;
    while (str[i])
    {
        f(i, &str[i]);
        i++;
    }
}