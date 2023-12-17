/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:54:32 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/12/27 12:55:04 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *holder)
{
	char	*buffer;
	int		amount;

	amount = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (nl_checker(holder) && amount != 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[amount] = '\0';
		holder = ft_strjoin_v2(holder, buffer);
	}
	free (buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder[1024];
	char		*result;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	holder[fd] = read_line(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	result = till_next_line(holder[fd]);
	holder[fd] = after_next_line(holder[fd]);
	return (result);
}
