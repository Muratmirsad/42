#include "libft.h"

int ft_memcmp(const void *ptr, const void *find, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        if (*((const char *)ptr + i) != *((const char *)find + i))
            return (*((const char *)ptr + i) - *((const char *)find + i));
        i++;
    }
    return (0);
}