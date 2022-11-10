#include "libft.h"

int ft_toupper(int a)
{
    if (97 <= a && a <= 122)
        a -= 32;
    return (a);
}