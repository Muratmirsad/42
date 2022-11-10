#include "libft.h"

int ft_tolower(int a)
{
    if (65 <= a && a <= 90)
        a += 32;
    return (a);
}