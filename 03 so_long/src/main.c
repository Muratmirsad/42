#include "../include/so_long.h"
#include <fcntl.h>

int	main(int ar, char **av)
{
	t_map_stack	*t_holder;
	char		**map;

	if (ar != 2)
		return (0);
	t_holder = (t_map_stack *)malloc(sizeof(t_map_stack));
	t_holder->fd = open(av[1], O_RDONLY, 777);
	map = read_map(t_holder);
	is_the_map_playable(map, t_holder);


	system("leaks a.out");
	write(1, "OK!\n", 5);
}
