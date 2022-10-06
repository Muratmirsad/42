void	ft_bzero(void *str, size_t len)
{
    int i;

    i = 0;
    while (i < len)
    {
        str[i] = 0;
        i++;
    }
}