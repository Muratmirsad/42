#include "libft.h"

int ft_isascii(int a)
{
    if (a < 32 || a > 126)
        return (0);
    return (1);
}