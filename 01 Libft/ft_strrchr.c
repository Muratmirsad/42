#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int i;

    i = 0;
    while (*(str + i))
        i++;
    i--;
    while (i >= 0)
    {
        if (*(str + i) == c)
<<<<<<< HEAD
            return ((char *)str + i);
=======
            return (str + i);
>>>>>>> 5fc2bd9bd40116e130a4d2564823920972754631
        i--;
    }
    return (0);
}