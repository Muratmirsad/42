/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:59:52 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/12/27 12:59:53 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		nl_checker(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_v2(char *s1, char *s2);
char	*till_next_line(char	*holder);
char	*after_next_line(char *holder);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif
#endif