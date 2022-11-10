#include "libft.h"

int ft_isalnum(int a)
{
    if (('0' <= a && a <= '9') || ('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z'))
        return (1);
    return (0);
}