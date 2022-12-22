/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:31:04 by mdiraga           #+#    #+#             */
/*   Updated: 2022/12/16 14:32:09 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_error(char *str, char *buff)
{
	free(str);
	free(buff);
	return (0);
}

static char	*ft_swap(const char *str, int rstr_size, int i)
{
	static int	index;
	char		*rstr;
	int			key;

	key = index;
	while (str[index] && str[index] != '\n')
	{
		rstr_size++;
		index++;
	}
	if (str[index] == '\n')
	{
		rstr_size++;
		index++;
	}
	if (key == index)
		return (0);
	rstr = (char *)malloc(rstr_size + 1);
	if (!rstr)
		return (0);
	rstr[rstr_size] = 0;
	while (rstr_size > 0)
		rstr[rstr_size-- - 1] = str[index + i-- - 1];
	return (rstr);
}

static char	*ft_run(int fd, int bytes, char *rstr, char *buff)
{
	static char	*str;
	static int	key;

	while (bytes && !key)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_error(str, buff));
		buff[bytes] = 0;
		str = ft_strjoin(str, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	if (!key)
		rstr = ft_swap(str, 0, 0);
	if (!rstr && !key)
	{
		key = 1;
		free(str);
		return (0);
	}
	return (rstr);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*rstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	rstr = ft_run(fd, 1, 0, buff);
	return (rstr);
}
