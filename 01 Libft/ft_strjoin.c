#include "libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    unsigned int    is;
    unsigned int    irstr;
    char            *rstr;
    
    is = ft_strlen(s1);
    is += ft_strlen(s2);
    rstr = (char *)malloc(is);
    if (!(rstr))
        return (0);
    is = 0;
    irstr = 0;
    while (*(s1 + is))
    {
        *(rstr + irstr) = *(s1 + is);
        irstr++;
        is++;
    }
    is = 0;
    while (*(s2 + is))
    {
        *(rstr + irstr) = *(s2 + is);
        irstr++;
        is++;
    }
    return (rstr);
}