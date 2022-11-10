#include "libft.h"

char    *ft_substr(char const *str, unsigned int start, size_t len)
{
    unsigned int    i;
    char            *p;

    p = (char *)malloc(len);
    if (!(p))
        return (0);
    i = 0;
    while (len > 0)
    {
        *(p + i) = *(str + start);
        i++;
        start++;
        len--;
    }
    return (p);
}
