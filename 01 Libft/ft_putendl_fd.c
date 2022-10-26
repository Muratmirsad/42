#include "libft.h"

void    ft_putendl_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (*(str + i))
        write(fd, &str[i], 1);
    write(1, "\n", 1);
}