#include "libft.h"

char    *ft_strtrim(char const *str, char const *cut)
{
    int is;
    int ic;
    int len;
    int idiff;
    char *rstr;

    is = 0;
    ic = 0;
    len = ft_strlen(str);
    while (*(str + is) == *(cut + ic))
    {
        is++;
        ic++;
        len--;
    }
    is = ft_strlen(str);
    ic = ft_strlen(cut);
    while (*(str + is) == *(cut + ic))
    {
        is--;
        ic--;
        len--;
    }
    rstr = (char *)malloc(len);
    if (!(rstr))
        return (0);
    is = 0;
    ic = 0;
    while (*(str + is) == *(cut + ic))
    {
        is++;
        ic++;
    }
    idiff = 0;
    while (idiff <= len)
    {
        *(rstr + idiff) = *(str + is);
        idiff++;
        is++;
    }
    return (rstr);
}