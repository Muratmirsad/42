/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:16:03 by mdiraga           #+#    #+#             */
/*   Updated: 2022/11/14 16:58:35 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(const char *str, char c)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		else if (str[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	ft_word_len(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

static char	*ft_stringer(const char *src, char c)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * ft_word_len(src, c) + 1);
	i = 0;
	while (*src && *src != c)
	{
		ret[i] = *(src++);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	size = ft_word(s, c);
	result = malloc(sizeof(char *) * size + 1);
	if (result == NULL)
		return (0);
	i = 0;
	j = 0;
	while (j < size && s[i])
	{
		while (s[i] == c)
			i++;
		result[j] = ft_stringer(&s[i], c);
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	result[j] = 0;
	return (result);
}
