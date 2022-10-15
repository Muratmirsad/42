#include "libft.h"

int ft_isalpha(int a)
{
    if ((a < 'a' || a > 'z') && (a < 'A' || a > 'Z'))
        return (0);
    return (1);
}