#include "../include/so_long.h"
#include <fcntl.h>

int	main(int ar, char **av)
{
	t_map_stack	*t_holder;
	char		**map;
	int			*player;

	if (ar != 2)
		return (0);
	t_holder = (t_map_stack *)malloc(sizeof(t_map_stack));
	is_file_current(av[1]);
	t_holder->fd = open(av[1], O_RDONLY, 777);
	map = read_map(t_holder);
	is_the_map_playable(map, t_holder);
	player = (int *)malloc(12);
	player[0] = t_holder->player_x;
	player[1] = t_holder->player_y;
	player[2] = t_holder->c_size;
	map[player[1]][player[0]] = '2';
	render(map, t_holder->last_column * 64, player);


	system("leaks so_long");
	write(1, "OK!\n", 5);
}
