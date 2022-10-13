#include "libft.h"
#include <stdio.h>

int main()
{
    char src[] = "sealam";
    char dest[] = "denemeaaa";
    int len = 8;
    len = ft_strlcat(dest, src, len);
    printf("%s\n", dest);
    printf("%d\n", len);

    return 0;
}