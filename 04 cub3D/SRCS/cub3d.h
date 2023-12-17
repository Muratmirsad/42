/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:24:18 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/15 15:29:53 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include "LIBFT/libft.h"
# include "GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include <stdio.h> //! sil!!!
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct mlx_data_test
{
	void	*mlx;
	void	*win;
}	t_data_m;

typedef struct s_texture
{
	void	*image;
	char	*data;
	int		use;
	int		w;
	int		h;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_texture;

typedef struct s_image
{
	void	*window;
	int		*image;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_image;

typedef struct s_data
{
	int			line_count;
	char		*map_name;
	char		*map_path;
	char		**whole_map;
	char		**map;
	int			**int_map;
	char		*floor;
	int			f_red;
	int			f_green;
	int			f_blue;
	char		*ceiling;
	int			c_red;
	int			c_green;
	int			c_blue;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		direction;
	double		pos_x;
	int			draw_start;
	int			draw_end;
	int			side;
	int			line_height;
	int			x;
	int			y;
	int			map_x;
	int			map_y;
	int			hit;
	int			step_x;
	int			step_y;
	int			tex_x;
	int			tex_y;
	int			floorc;
	int			skyc;
	double		tex_pos;
	double		step;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_x;
	double		perp_wall_dist;
	double		raydir_y;
	double		raydir_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	double		rot_speed;
	int			move[6];
	t_texture	textures[4];
	t_data_m	*mlx_data;
	t_image		img;
}	t_data;

void			check_map(t_data *map_data);
void			allocation_exit(t_data *map_data);
void			wrong_argument_exit(t_data *map_data, int error_code);
void			wrong_map_exit(t_data *map_data, int code);
int				is_line_empty(char *line);
char			**ft_split_special(const char *s, t_data *map_data);
void			clear_map(t_data *map_data);
void			get_textures(t_data *map_data, char *trimmed);
void			get_ceiling_floor(t_data *map_data, char *trimmed);
void			free_double_char(char **ptr);
int				is_it_ws(int c);
void			check_rgb(t_data *map_data);
void			check_map_characters(t_data *map_data, char **map);
void			check_borders(t_data *map_data, char **map);
int				long_line(char **map);
void			convert_to_int(t_data *map_data);

//???!

void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
void			fill_player_dir(t_data *data, double x, double y);
void			set_player_dir(char c, t_data *data);
int				create_rgb(int red, int green, int blue);
void			img_pix_put(t_image *image, int x, int y, int color);
unsigned int	get_pixel_in_texture(t_texture *texture, int x, int y);
void			move_forward(t_data *data);
void			move_back(t_data *data);
void			move_right(t_data *data);
void			move_left(t_data *data);
void			player_move(t_data *data);
void			xpm_to_textures(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
int				ray_casting(t_data *data);
void			start_img(t_data *data);
void			calc_texture_pixel_color(t_data *data);
int				exit_from_win(t_data *map);

#endif