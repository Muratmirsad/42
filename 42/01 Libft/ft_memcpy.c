#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t len)
{
    size_t i;

    //(char *)src;
    //(char *)dest;
    if (src == dest || !(len))
        return (dest);
    i = 0;
    while (i < len)
    {
        *((char *)dest + i) = *((char *)src + i);
        i++;
    }
    return (dest);
}