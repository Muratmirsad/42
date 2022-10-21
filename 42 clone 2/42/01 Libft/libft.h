#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>

void    *ft_memcpy(void *dest, const void *src, size_t len);
size_t  ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t  ft_strlcat(char *dest, const char *src, size_t dest_size);
void    *ft_memset(void *str, int c, size_t len);
int ft_strlen(const char *str);
int ft_strncmp(const char *str, const char *find, size_t n);
void    *memchr(const void *ptr, int c, size_t n);
int ft_memcmp(const void *ptr, const void *find, size_t n);
int ft_strnstr(const char *str, const char *find, size_t len);
void    *ft_calloc(size_t numberofelements, size_t sizeofelements);
char    *ft_strdup(const char *str);
char    *ft_substr(char const *str, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrim(char const *str, char const *cut);
char    **ft_split(char const *str, char c);
char *ft_itoa(int number);
void    ft_putchar_fd(char c, int fd);

#endif