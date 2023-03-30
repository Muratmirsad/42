#include "../include/so_long.h"

static void	put_window(t_img_holder *t_imgs, int height, char **map, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (i <= height / 64)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(t_imgs->mlx, t_imgs->win, t_imgs->wall_ptr, j * 64, i * 64);
			else if (map[i][j] == 'c')
				mlx_put_image_to_window(t_imgs->mlx, t_imgs->win, t_imgs->coll_ptr, j * 64, i * 64);
			else if (map[i][j] == 'e')
				mlx_put_image_to_window(t_imgs->mlx, t_imgs->win, t_imgs->exit_ptr, j * 64, i * 64);
			else if (map[i][j] == '2')
				mlx_put_image_to_window(t_imgs->mlx, t_imgs->win, t_imgs->void_ptr, j * 64, i * 64);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(t_imgs->mlx, t_imgs->win, t_imgs->void_ptr, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(t_imgs->mlx, t_imgs->win, t_imgs->player_ptr, p[0] * 64, p[1] * 64);
}

static void	player_xy(int *player, int move, char **map, t_img_holder *t_holder)
{
	static t_img_holder	*t_s_holder;
	static char			**s_map;
	static int			*s_player;
	static int			total_move = 1;
	char				*tmp;

	if (move == 0)
	{
		s_player = player;
		s_map = map;
		t_s_holder = t_holder;
		return ;
	}
	tmp = ft_itoa(total_move);
	ft_printf("total move: %d\n", total_move);
	total_move += player_move(s_player, s_map, move);
	mlx_clear_window(t_s_holder->mlx, t_s_holder->win);
	put_window(t_s_holder, t_s_holder->height, s_map, t_s_holder->player);
	mlx_put_image_to_window(t_s_holder->mlx, t_s_holder->win, t_s_holder->black_ptr, 18, 4);
	mlx_string_put(t_s_holder->mlx, t_s_holder->win, 20, 20, 0xFFFFFF, tmp);
	free(tmp);
}

static int	key_func(int keycode)
{
	if (keycode == 13)
	{
		player_xy(0, 1, 0, 0);
	}
	else if (keycode == 2)
	{
		player_xy(0, 2, 0, 0);
	}
	else if (keycode == 1)
	{
		player_xy(0, 3, 0, 0);
	}
	else if (keycode == 0x00)
	{
		player_xy(0, 4, 0, 0);
	}
	else if (keycode == 53)
	{
		ft_putstr_fd("exiting...\n", 1);
		exit(1);
	}
	return (0);
}

void	render(char **map, int height, int *player)
{
	t_img_holder	*t_imgs;
	void			*mlx;
	void			*win;
	int				width;

	t_imgs = (t_img_holder *)malloc(sizeof(t_img_holder));
	width = (ft_strlen(map[0]) - 1) * 64;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height + 64, "so_long");
	convert_images(mlx, t_imgs);
	t_imgs->win = win;
	t_imgs->mlx = mlx;
	t_imgs->player = player;
	t_imgs->height = height;
	player_xy(player, 0, map, t_imgs);
	put_window(t_imgs, height, map, player);
	mlx_hook(win, 2, 1L << 0, key_func, NULL);

	mlx_loop(mlx);
}
