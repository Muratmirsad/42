#include "libft.h"

int ft_memcmp(const void *ptr, const void *find, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        if (*((const unsigned char *)ptr + i) != *((const unsigned char *)find + i))
            return (*((const unsigned char *)ptr + i) - *((const unsigned char *)find + i));
        i++;
    }
    return (0);
}