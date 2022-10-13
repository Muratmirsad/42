#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t dest_size)
{
    size_t  id;
    size_t  is;

    while (*(dest + id))
        id++;
    while (*(src + is) && is < dest_size)
    {
        *(dest + id) = *(src + is);
        id++;
        is++;
    }
    *(dest + id) = 0;
    return (is);
}