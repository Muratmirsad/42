/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 03:24:50 by mdiraga           #+#    #+#             */
/*   Updated: 2023/10/20 16:39:55 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	control_func(char **map, int row, int col, int *c)
{    
	if (map[row][col] == 'n' || map[row][col] == 's'
		|| map[row][col] == 'e' || map[row][col] == 'w')
		return ;
	else if (map[row][col] == 'N' || map[row][col] == 'S'
			|| map[row][col] == 'E' || map[row][col] == 'W')
		map[row][col] += 32;
	else if (map[row][col] == '0')
	{
		map[row][col] = '2';
		*c--;
	}
	else if (map[row][col] == '2') //! DENEYSEL
		*c--;
}


static int	scan_map(char **map, int row, int col, int *c)
{
	if (*c < 0)
		return (1);
	else if (map[row][col] == '1')
		return (0);
	else if (map[row][col] == '2'
				|| map[row][col] == 'n'
				|| map[row][col] == 's'
				|| map[row][col] == 'e'
				|| map[row][col] == 'w')
		return (0);
	else
	{
		control_func(map, row, col, c);
		if ((scan_map(map, row - 1, col, c)
				|| scan_map(map, row + 1, col, c)
				|| scan_map(map, row, col - 1, c)
				|| scan_map(map, row, col + 1, c)) == 1 && *c < 0)
			return (1);
		else
			return (0);
	}
}

//	.cub formatindaki dosyanin gereksinimlerini kontrol eden ve bu dosyayi acarak, FD degeri donduren bir fonksiyon
void    ft_read_file(s_info *s_main, char *map_name)
{
    char	*line;
    int		fd;
 
    s_main->map_size = 0;
	if ((map_name[0] == '.' && map_name[1] == 'c'
		&& map_name[2] == 'u' && map_name[3] == 'b')
		|| ft_strlen(map_name) < 5)
        exit(2); //TODO ERROR
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
        exit(1); //TODO ERROR
    while (1) //TODO line free
    {
        line = get_next_line(fd); 
        if (!line)
            break ;
        else if (*line == '\n')
            continue ;
		s_main->map[s_main->map_size++] = line;
    }
    close(fd);
}

//	playerin baslangic konumunu arayan bir fonksiyon, eger player bulunamazsa 0, bir veya daha fazla baslangic konumu bulursa 0dasn farkli bir deger dondurecek
static int	find_player_location(s_info *s_main)
{
	int	key;
	int	row;
	int	col;

	key = 0;
	row = 0;
	col = 0;
	while (row <= s_main->map_size)
	{
		while (s_main->map[row][col])
		{
			if (s_main->map[row][col] == 'N'
				|| s_main->map[row][col] == 'S'
				|| s_main->map[row][col] == 'E'
				|| s_main->map[row][col] == 'W')
			{
				key++;
				s_main->player_row = row;
				s_main->player_col = col;
			}
			col++;
		}
		row++;
	}
	return (key); //TODO ERROR | if key == 0 player bulunamadi | if key > 1 1den fazla mplayer var 
}

// BASLANGIC
void    parser(s_info *s_main, char *map_name)
{
	int	c;

	c = 10000;
    ft_read_file(s_main, map_name);
	if (find_player_location(s_main) != 1)
		exit(3); //! ERROR
	scan_map(s_main->map, s_main->player_row, s_main->player_col, &c);
}
