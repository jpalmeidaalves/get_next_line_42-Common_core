/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:26:11 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/23 21:34:09 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *acum, char *buf);
char	*ft_read_n_acum(int fd, char *acumulator);
char	*get_next_line(int fd);
char	*ft_copy_line(char *acum);
char	*ft_update_acum(char *acum);
char	*ft_strchr(char *s, int c);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *str, size_t n);

#endif
