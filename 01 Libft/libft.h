#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

void    *ft_memcpy(void *dest, const void *src, size_t len);
size_t  ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t  ft_strlcat(char *dest, const char *src, size_t dest_size);

#endif