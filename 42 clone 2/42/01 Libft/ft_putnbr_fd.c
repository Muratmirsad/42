#include "libft.h"

void    ft_putnbr_fd(int nb, int fd)
{
    if (nb == -2147483648)
        write(1, '-2147483648', 11);
    else if (nb < 0)
    {
        write(1, '-', 1);
        ft_number(nb * -1);
    }
    else if (nb > 9)
    {
        ft_number(nb / 10);
        ft_number(nb % 10);
    }
    else
        write(1, &nb, 1);
}