#include "libft.h"

void    ft_putnbr_fd(int nb, int fd)
{
    if (nb == -2147483648)
<<<<<<< HEAD
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
=======
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
>>>>>>> 5fc2bd9bd40116e130a4d2564823920972754631
}