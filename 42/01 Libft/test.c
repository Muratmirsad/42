#include "libft.h"

int main()
{
    //char src[] = "seblam";
    //char dest[] = "la";
    int i = 0;
    int *p;
    p = ft_calloc(5, 4);
    while (i < 20)
    {
        printf("%d\n", p[i]);
        i++;
    }

    return 0;
}