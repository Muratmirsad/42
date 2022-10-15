#include "libft.h"

int main()
{
    char src[] = "seblam";
    //char dest[] = "la";
    //int i = 0;
    char *p;
    p = ft_strdup(src);
    printf("%s\n", p);

    return 0;
}