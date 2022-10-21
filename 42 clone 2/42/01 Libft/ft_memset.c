#include "libft.h"

void    *ft_memset(void *str, int c, size_t len)
{
    int i;

    i = 0;
    while (i < len)
    {
        *((char *)str + i) = c;
        i++;
    }
    return (str);
}
