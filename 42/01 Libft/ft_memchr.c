#include "libft.h"

void    *ft_memchr(const void *ptr, int c, size_t n)
{
    int i;

    i = 0;
    //*((unsigned char *)ptr);
    while (i < n)
    {
        if (*((unsigned char *)ptr + i) == (unsigned char) c)
            return ((void *)ptr + i);
        i++;
    }
    return (0);
}