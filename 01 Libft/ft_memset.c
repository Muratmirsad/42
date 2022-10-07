void    *ft_memset(void *str, int c, size_t len)
{
    int i;

    i = 0;
    while (i < len)
    {
        str[i] = c;
        i++;
    }
    return (str);
}
