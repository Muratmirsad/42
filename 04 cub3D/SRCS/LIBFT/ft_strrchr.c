/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:09:29 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/20 11:19:11 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	unsigned int	i;

	c = (unsigned char)c;
	i = 0;
	while (str[i])
		i++;
	if (c == 0)
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		if (i > 0)
			i--;
		else
			break ;
	}
	return (0);
}
