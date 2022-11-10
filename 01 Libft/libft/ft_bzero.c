#include "libft.h"

void    *ft_bzero(void *str, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)str + idx) = 0;
		idx++;
	}
	return (str);
}