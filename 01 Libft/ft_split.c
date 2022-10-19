#include "libft.h"

char    **ft_split(const char *str, char c)
{
    char    **rstr;
    int i;
    int chi;
    int istr;
    int string;

    istr = 0;
    string = 0;
    while (str[istr])
    {
        i = 0;
        chi = 0;
        while (str[istr] == c)
            istr++;
        while (str[istr++] != c)
            chi++;
        rstr[string] = (char *)malloc(chi + 1);
        while (i <= chi)
            rstr[string][i++] = str[istr++];
        rstr[string][i] = 0;
        string++;
    }
    string = 0;
    i = 0;
    while (string < 4)
        printf("%s\n", rstr[string++]);
    return 0;
}