#include "libft.h"

void    ft_putnbr_fd(int nb, int fd)
{
    if (nb == -2147483648)
        write(fd, "-2147483648", 11);
    else if (nb < 0)
    {
        write(1, "-", 1);
        ft_putnbr_fd(nb * -1, fd);
    }
    else if (nb > 9)
    {
        ft_putnbr_fd(nb / 10, fd);
        ft_putnbr_fd(nb % 10, fd);
    }
    else
        write(fd, &nb, 1);
}