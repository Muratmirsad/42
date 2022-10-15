#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    size_t  i;

    if (dest == src || !(len))
        return (dest);
    if (dest <= src)
    {
        i = 0;
        while (i < len)
        {
            *((char *)dest + i) = *((char *) src + i);
            i++;
        }
        return (dest);
    }
    while (len > 0)
    {
        *((char *)dest + i) = *((char *) src + i);
        len--;
    }
    return (dest);
}
