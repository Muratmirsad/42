/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:36:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/30 17:56:45 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct map_stack
{
	int	e;
	int	p;
	int	last_column;
	int	c_size;
	int	fd;
	int	player_x;
	int	player_y;
}	t_map_stack;

typedef struct img_stack
{
	void	*wall_ptr;
	void	*player_ptr;
	void	*coll_ptr;
	void	*exit_ptr;
	void	*void_ptr;
	void	*black_ptr;
	void	*mlx;
	void	*win;
	int		*player;
	int		height;
}	t_img_holder;

void	ft_error(void);
char	**read_map(t_map_stack *t_holder);
char	*ft_strjoin_allfree(char *s1, char *s2);
void	is_the_map_playable(char **map, t_map_stack *t_holder);
void	is_file_current(char *av);
void	render(char **map, int height, int *player);
void	convert_images(void *mlx_ptr, t_img_holder *t_imgs);
int		control_sq(char *c);
int		player_move(int *player, char **map, int move);
void	move_rule_7(int total_move);
int		exit_func(int keycode);

#endif