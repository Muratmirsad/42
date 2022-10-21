#include "libft.h"

char    ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
    while (*(str + i))
    {
        if (*(str + i) == c)
            return (*(str + i));
        i++;
    }
    return (0);
}