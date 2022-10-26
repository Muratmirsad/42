#include "libft.h"

void    ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (*(str + i))
        write(fd, &str[i++], 1);
}