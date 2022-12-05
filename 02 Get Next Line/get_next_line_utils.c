# include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_add(const char *str, char *rstr, int irstr, int is)
{
	while (*(str + is))
	{
		*(rstr + irstr) = *(str + is);
		irstr++;
		is++;
	}
	return (irstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	is;
	unsigned int	irstr;
	char			*rstr;

	if (!s1 || !s2)
		return (0);
	is = ft_strlen(s1);
	is += ft_strlen(s2);
	rstr = (char *)malloc(is + 1);
	if (!(rstr))
		return (0);
	irstr = ft_add(s1, rstr, 0, 0);
	irstr = ft_add(s2, rstr, irstr, 0);
	*(rstr + irstr) = 0;
	return (rstr);
}