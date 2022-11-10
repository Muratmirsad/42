#include "libft.h"

static int  ft_size(const char *str, char c)
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
    return (ir + 2);
}

char    **ft_split(const char *str, char c)
{
    char    **rstr;
    int     i;
    int     chi;
    int     istr;
    int     string;

    rstr = (char **)malloc(ft_size(str, c) * sizeof(char*));
    if (!rstr)
        return (0);
    istr = 0;
    string = 0;
    while (str[istr])
    {
        i = 0;
        chi = 0;
        while (str[istr] == c)
            istr++;
        while (str[istr + chi] && str[istr + chi++] != c)
        rstr[string] = (char *)malloc(chi + 1);
        if (!rstr[string])
            return (0);
        while (i < chi)
            rstr[string][i++] = str[istr++];
        rstr[string++][i] = 0;
    }
	*(rstr + string) = 0;
    return (rstr);
}