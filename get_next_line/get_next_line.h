/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:26:11 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/22 19:48:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char    *ft_strjoin(char *acum, char *buf);
char    *ft_read_n_acum(int fd, char *acumulator);
char	*get_next_line(int fd);
char    *ft_copy_line(char *acum);
char    *ft_update_acum(char *acum);
char    *ft_strchr(char *s, int c);

#endif
