#include "libft.h"

int ft_isascii(int a)
{
    if (a >= 0 && a <= 177)
        return (1);
    return (0);
}