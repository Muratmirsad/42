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

#endif