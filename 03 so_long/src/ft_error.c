#include "../include/so_long.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	system("leaks so_long");
	exit(1);
}

void	is_file_current(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (ft_strncmp(av + i - 4, ".ber", 4) != 0 && i > 4)
		ft_error();
}

int	control_sq(char *c)
{
	if (*c == 'C')
	{
		*c = 'c';
		return (1);
	}
	else if (*c == '0')
	{
		*c = '2';
		return (1);
	}
	else if (*c == 'E')
	{
		*c = 'e';
		return (1);
	}
	return (0);
}
