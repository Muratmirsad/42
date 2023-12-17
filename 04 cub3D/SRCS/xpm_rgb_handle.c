/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_rgb_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:01:43 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/16 16:43:45 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_img(t_data *data)
{
	int	bpp;
	int	sizeline;
	int	endian;

	data->img.image = mlx_new_image(data->mlx_data->mlx, WIDTH, HEIGHT);
	data->img.data = mlx_get_data_addr(data->img.image, &bpp,
			&sizeline, &endian);
	data->img.bpp = bpp;
	data->img.sizeline = sizeline;
	data->img.endian = endian;
}

void	xpm_to_textures(t_data *data)
{
	data->textures[0].image = mlx_xpm_file_to_image(data->mlx_data->mlx,
			data->north, &data->textures[0].w, &data->textures[0].h);
	data->textures[1].image = mlx_xpm_file_to_image(data->mlx_data->mlx,
			data->east, &data->textures[1].w, &data->textures[1].h);
	data->textures[2].image = mlx_xpm_file_to_image(data->mlx_data->mlx,
			data->south, &data->textures[2].w, &data->textures[2].h);
	data->textures[3].image = mlx_xpm_file_to_image(data->mlx_data->mlx,
			data->west, &data->textures[3].w, &data->textures[3].h);
	if (!data->textures[0].image || !data->textures[1].image
		|| !data->textures[2].image || !data->textures[3].image)
		wrong_map_exit(data, 29);
	data->textures[0].data = mlx_get_data_addr(data->textures[0].image,
			&(data->textures[0].bpp), &(data->textures[0].sizeline),
			&(data->textures[0].endian));
	data->textures[1].data = mlx_get_data_addr(data->textures[1].image,
			&(data->textures[1].bpp), &(data->textures[1].sizeline),
			&(data->textures[1].endian));
	data->textures[2].data = mlx_get_data_addr(data->textures[2].image,
			&(data->textures[2].bpp), &(data->textures[2].sizeline),
			&(data->textures[2].endian));
	data->textures[3].data = mlx_get_data_addr(data->textures[3].image,
			&(data->textures[3].bpp), &(data->textures[3].sizeline),
			&(data->textures[3].endian));
}

void	calc_texture_pixel_color(t_data *data)
{
	int	color;

	color = 0;
	if (data->y < data->draw_start)
		img_pix_put(&data->img, data->x, data->y, data->skyc);
	else if (data->y >= data->draw_start && data->y <= data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (64 - 1);
		data->tex_pos += data->step;
		if (data->side == 1 && data->raydir_y > 0)
			color = get_pixel_in_texture(&data->textures[0],
					data->tex_x, data->tex_y);
		else if (data->side == 0 && data->raydir_x < 0)
			color = get_pixel_in_texture(&data->textures[1],
					data->tex_x, data->tex_y);
		else if (data->side == 1 && data->raydir_y < 0)
			color = get_pixel_in_texture(&data->textures[2],
					data->tex_x, data->tex_y);
		else if (data->side == 0 && data->raydir_x > 0)
			color = get_pixel_in_texture(&data->textures[3],
					data->tex_x, data->tex_y);
		img_pix_put(&data->img, data->x, data->y, color);
	}
	else
		img_pix_put(&data->img, data->x, data->y, data->floorc);
}

void	img_pix_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->data + (y * image->sizeline + x * (image->bpp / 8));
	*(int *)pixel = color;
}

unsigned int	get_pixel_in_texture(t_texture *texture, int x, int y)
{
	char	*re;

	re = texture->data + (y * texture->sizeline + x * (texture->bpp / 8));
	return (*((unsigned int *)re));
}
