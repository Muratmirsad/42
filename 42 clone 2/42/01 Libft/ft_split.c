#include "libft.h"

static  int ft_size(const char *str, char c)
{
    int i;
    int ir;

    i = 0;
    ir = 0;
    while (str[i])
    {
        if (str[i++] == c)
            ir++;
    }
    return (ir + 1);
}

static  void    ft_2dmalloc(char **rstr, char c)
{
    rstr = (char **)malloc(ft_size(rstr, c) * sizeof(char*));
    if (!rstr)
        return (0);
}

char    **ft_split(const char *str, char c)
{
    char    **rstr;
    int     i;
    int     chi;
    int     istr;
    int     string;

    ft_2dmalloc(rstr, c);
    istr = 0;
    string = 0;
    while (str[istr])
    {
        i = 0;
        chi = 0;
        while (str[istr] == c)
            istr++;
        while (str[istr] && str[chi++] != c)
            chi++;
        rstr[string] = (char *)malloc(chi + 1);
        if (!rstr[string])
            return (0);
        while (i < chi)
            rstr[string][i++] = str[istr++];
        rstr[string++][i] = 0;
    }
}