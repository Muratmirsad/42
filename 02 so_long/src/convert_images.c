/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:36 by mdiraga           #+#    #+#             */
/*   Updated: 2023/03/30 19:17:41 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	convert_images(void *p, t_img_holder *t_imgs)
{
	int	x;
	int	y;

	t_imgs->wall_ptr = mlx_xpm_file_to_image(p, "assets/wall.xpm", &x, &y);
	t_imgs->player_ptr = mlx_xpm_file_to_image(p, "assets/player.xpm", &x, &y);
	t_imgs->coll_ptr = mlx_xpm_file_to_image(p, "assets/coll.xpm", &x, &y);
	t_imgs->void_ptr = mlx_xpm_file_to_image(p, "assets/void.xpm", &x, &y);
	t_imgs->exit_ptr = mlx_xpm_file_to_image(p, "assets/exit.xpm", &x, &y);
	t_imgs->black_ptr = mlx_xpm_file_to_image(p, "assets/black.xpm", &x, &y);
	if (t_imgs->wall_ptr == 0x0)
		ft_error();
	else if (t_imgs->player_ptr == 0x0)
		ft_error();
	else if (t_imgs->coll_ptr == 0x0)
		ft_error();
	else if (t_imgs->void_ptr == 0x0)
		ft_error();
	else if (t_imgs->exit_ptr == 0x0)
		ft_error();
	else if (t_imgs->black_ptr == 0x0)
		ft_error();
}
