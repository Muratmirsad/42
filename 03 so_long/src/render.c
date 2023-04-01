/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:36:53 by mdiraga           #+#    #+#             */
/*   Updated: 2023/04/01 15:09:28 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	test(t_img_holder *t_i, int i, int j, int key)
{
	if (key == 1)
		mlx_put_image_to_window(t_i->mlx, t_i->win, t_i->wall_ptr, j, i);
	else if (key == 2)
		mlx_put_image_to_window(t_i->mlx, t_i->win, t_i->coll_ptr, j, i);
	else if (key == 3)
		mlx_put_image_to_window(t_i->mlx, t_i->win, t_i->exit_ptr, j, i);
	else if (key == 4)
		mlx_put_image_to_window(t_i->mlx, t_i->win, t_i->void_ptr, j, i);
	else if (key == 5)
		mlx_put_image_to_window(t_i->mlx, t_i->win, t_i->void_ptr, j, i);
	else if (key == 6)
		mlx_put_image_to_window(t_i->mlx, t_i->win, t_i->player_ptr, i, j);
}

static void	put_window(t_img_holder *t_i, int height, char **map, int *p)
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
				test(t_i, i * 64, j * 64, 1);
			else if (map[i][j] == 'c')
				test(t_i, i * 64, j * 64, 2);
			else if (map[i][j] == 'E')
				test(t_i, i * 64, j * 64, 3);
			else if (map[i][j] == '2')
				test(t_i, i * 64, j * 64, 4);
			else if (map[i][j] == '0')
				test(t_i, i * 64, j * 64, 5);
			j++;
		}
		i++;
	}
	test(t_i, p[0] * 64, p[1] * 64, 6);
}

static void	player_xy(int *player, int move, char **map, t_img_holder *t_holder)
{
	static t_img_holder	*t_s;
	static char			**s_map;
	static int			*s_player;
	static int			total_move = 0;
	char				*tmp;

	if (move == 0)
	{
		s_player = player;
		s_map = map;
		t_s = t_holder;
		return ;
	}
	if (move == 7)
		move_rule_7(total_move);
	total_move += player_move(s_player, s_map, move, total_move);
	tmp = ft_itoa(total_move);
	ft_printf("total move: %d\n", total_move);
	mlx_clear_window(t_s->mlx, t_s->win);
	put_window(t_s, t_s->height, s_map, t_s->player);
	mlx_put_image_to_window(t_s->mlx, t_s->win, t_s->black_ptr, 18, 4);
	mlx_string_put(t_s->mlx, t_s->win, 20, 20, 0xFFFFFF, tmp);
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
	mlx_hook(win, 17, 1L << 17, exit_func, NULL);
	mlx_loop(mlx);
}
