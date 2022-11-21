#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char    *ft_strnjoin(char *str1, char *str2, int n);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif

