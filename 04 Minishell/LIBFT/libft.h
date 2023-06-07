/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:56:52 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/02 17:28:07 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(void *content);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del) (void *));
int			ft_isalnum(char a);
int			ft_isalpha(char a);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isprint(int a);
char		*ft_tolower(char *str);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		*ft_memchr(const void *ptr, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putchar_fd(char c, int fd);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
void		ft_striteri(char *s, void (f)(unsigned int, char*));
char		*ft_strdup(const char *s1);
void		ft_putnbr_fd(int n, int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strnstr(const char *str, const char *str1, size_t n);
char		*ft_strrchr(const char *str, int c);
size_t		ft_strlen(const char *s);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_putstr_fd(char *s, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
