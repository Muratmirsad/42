/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 03:25:25 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/30 21:46:27 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_h

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct	main_struct
{
	char	**map;
	int		map_size;
	int		player_row;
	int		player_col;
}	s_info;

#endif