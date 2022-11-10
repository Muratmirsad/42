#include "libft.h"

int ft_isdigit(int a)
{
    if (a < '0' || a > '9')
        return (0);
    return (1);
}