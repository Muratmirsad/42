#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
	if (c == 0)
		return (str);
    while (*(str + i))
    {
        if (*(str + i) == c)
            return (str + i);
        i++;
    }
    return (0);
}