#include "libft.h"

int ft_size(char const *str, char c)
{
    int i;
    int ri;

    i = 0;
    ri = 0;
    while (*(str + i))
    {
        if (*(str + i) == c)
            ri++;
        i++;
        //printf("ft_size\n");
    }
    return (ri + 1);
}

void    ft_change(char **rstr, char const *str, char c)
{
    int i;
    int r1;
    int r2;

    i = 0;
    r1 = 0;
    while (*(str + i))
    {
        r2 = 0;
        while (*(str + i) != c)
        {
            rstr[r1][r2] = str[i];
            r2++;
            i++;
        }
        i++;
        r1++;
    }
}

char    **ft_split(char const *str, char c)
{
    char    **rstr;
    int     istr;
    int     size;
    int     string;

    rstr = (char **)malloc(ft_size(str, c) + 1);
    rstr[ft_size(str, c)][0] = 0;
    istr = 0;
    string = 0;
    while (*(str + istr))
    {
        size = 0;
        while (*(str + istr) != c)
        {
            istr++;
            size++;
            //printf("ikinci boyut\n");
        }
        *(rstr + string) = (char *)malloc(size + 1);
        rstr[string][size] = 0;
        //ft_change(rstr, str, c);
        string++;
        istr++;
    }
    ft_change(rstr, str, c);
    int i = 0;
    while (i <= string)
        printf("%s\n", rstr[i++]);
    return (rstr);
}
