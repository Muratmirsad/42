# include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	*c;

	c = (char*)malloc(1);
	c[1] = 0;
	str = (char*)malloc(0);
	str[0] = 0;

	while (1)
	{
		if (!(read(fd, c, 1)))
			return (0);
		if (c[0] == '\n')
			break;

		str = ft_strjoin(str, c);
	}
	free(c);
	return(str);
}