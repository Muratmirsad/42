#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	    ft_isalpha(int a);
int     ft_isdigit(int a);
int     ft_isalnum(int a);
int     ft_isascii(int a);
int     ft_isprint(int a);
int     ft_strlen(const char *str);
void    *ft_memset(void *str, int c, size_t len);
void    *ft_bzero(void *str, size_t n);
int     ft_memcmp(const void *ptr, const void *find, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t len);
size_t  ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t  ft_strlcat(char *dest, const char *src, size_t dest_size);
int     ft_toupper(int a);
int     ft_tolower(int a);
char    ft_strchr(const char *str, int c);
char    *ft_strrchr(const char *str, int c);
int     ft_strncmp(const char *str, const char *find, size_t n);
void    *ft_memchr(const void *ptr, int c, size_t n);
int     ft_memcmp(const void *ptr, const void *find, size_t n);
int     ft_strnstr(const char *str, const char *find, size_t len);
int 	ft_atoi(char *str);
void    *ft_calloc(size_t numberofelements, size_t sizeofelements);
char    *ft_strdup(const char *str);
char    *ft_substr(char const *str, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrim(char const *str, char const *cut);
char    **ft_split(const char *str, char c);
char    *ft_itoa(int number);
char    *ft_strmapi(const char *str, char (*f)(unsigned int, char));
void    ft_striterii(char *str, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *str, int fd);
void    ft_putendl_fd(char *str, int fd);
void    ft_putnbr_fd(int nb, int fd);

#endif