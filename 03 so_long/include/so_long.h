#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct map_stack
{
	int	e;
	int	p;
	int	last_column;
	int	fd;
	int	player_x;
	int	player_y;
}	t_map_stack;

void	ft_error(void);
char	**read_map(t_map_stack *t_holder);
char	*ft_strjoin_allfree(char *s1, char *s2);
void	is_the_map_playable(char **map, t_map_stack *t_holder);

#endif