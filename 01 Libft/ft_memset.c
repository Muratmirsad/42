#include "libft.h"

void    *ft_memset(void *str, int c, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        *((char *)str + i) = c;
        i++;
    }
    return (str);
}
