#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
    size_t  i;

    if (!(src) || !(dest))
        return (0);
    i = 0;
    while(i < dest_size && src[i])
    {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = 0;
    i = 0;
    while (i < dest_size && src[i])
        i++;
    return (i);
}