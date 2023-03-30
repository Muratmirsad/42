#include "../include/so_long.h"

void	convert_images(void *mlx_ptr, t_img_holder *t_imgs)
{
	int img_width;
	int img_height;

	t_imgs->wall_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/wall.xpm", &img_width, &img_height);
	t_imgs->player_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/player.xpm", &img_width, &img_height);
	t_imgs->coll_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/coll.xpm", &img_width, &img_height);
	t_imgs->void_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/void.xpm", &img_width, &img_height);
	t_imgs->exit_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/exit.xpm", &img_width, &img_height);
	t_imgs->black_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/black.xpm", &img_width, &img_height);

	if (!t_imgs->wall_ptr)
		ft_error();
}