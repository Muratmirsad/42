#include "libft.h"

int ft_strnstr(const char *str, const char *find, size_t len)
{
    size_t  istr;
    size_t  ifind;
    size_t  key;

    istr = 0;
    key = ft_strlen(find);
    while (istr < len - 1)
    {
        ifind = 0;
        while (*((const char *)str + istr) == *((const char *)find + ifind))
        {
            istr++;
            ifind++;
        }
        if (ifind == key)
            return (*((const char *)str + (istr - key)));
        istr++;
    }
    return (0);
}