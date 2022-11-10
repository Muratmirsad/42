#include "libft.h"

char    *ft_strdup(const char *str)
{
    int     i;
    char    *rstr;

    i = ft_strlen(str);
    rstr = (char *)malloc(i);
    i = 0;
    while (*(str + i))
    {
        *(rstr + i) = *(str + i);
        i++;
    }
    return (rstr);
}