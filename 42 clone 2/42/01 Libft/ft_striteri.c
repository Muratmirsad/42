#include "libft.h"

void    ft_striterii(char *str, void (*f)(unsigned int, char*))
{
    int i;

    if (!str || !f)
        return (0);
    i = 0;
    while (str[i])
        f(i, &str[i++]);
}