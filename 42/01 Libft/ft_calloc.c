#include "libft.h"

void    *ft_calloc(size_t numberofelements, size_t sizeofelements)
{
    char    *str;
    int     i;

    i = 0;
    str = (char *)malloc(numberofelements * sizeofelements);
    while (i < (numberofelements * sizeofelements))
    {
        *(str + i) = 0;
        i++;
    }

    return (str);
}