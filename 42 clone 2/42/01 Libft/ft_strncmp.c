#include "libft.h"

int ft_strncmp(const char *str, const char *find, size_t n)
{
    int i_str;
    int i_find;
    int key;

    i_str = 0;
    key = ft_strlen(find);
    while (*(str + i_str) && i_str < n)
    {
        i_find = 0;
        while (*(str + i_str) == *(find + i_find))
        {
            i_str++;
            i_find++;
        }
        if (i_find == key)
            return (*(str + (i_str - key)));
        i_str++;
    }
    return (0);
}