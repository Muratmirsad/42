#include "libft.h"

char	*ft_strnstr(const char *src, const char *dst, size_t len)
{
	size_t	i;
	int		b;

	i = 0;
	b = 0;
	if (!src && !dst)
		return (NULL);
	if (dst[i] == '\0')
	{
		return ((char *)src);
	}	
	while (i < len && src[i] != '\0')
	{
		while (dst[b] != '\0' && src[i + b] == dst[b] && i + b < len)
		{
			b++;
		}
		if (dst[b] == '\0')
		{
			return ((char *)(src + i));
		}
		i++;
	}
	return (NULL);
}
