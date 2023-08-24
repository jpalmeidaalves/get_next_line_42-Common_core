/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:55:46 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/23 21:34:40 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_update_acum(char *acum)
{
	char	*new_acum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!acum[i])
	{
		free(acum);
		return (NULL);
	}
	while (acum[i] && acum[i] != '\n')
		i++;
	if (ft_strlen(acum) - i == 1)
	{
		free(acum);
		return (NULL);
	}
	new_acum = ft_calloc((ft_strlen(acum) - i), sizeof(char) + 1);
	i++;
	while (acum[i])
		new_acum[j++] = acum[i++];
	free(acum);
	return (new_acum);
}

char	*ft_copy_line(char *acum)
{
	char	*line;
	int		i;

	i = 0;
	if (!acum[i] || !acum)
		return (NULL);
	while (acum[i] && acum[i] != '\n')
		i++;
	line = ft_calloc(i, sizeof(char) + 2);
	i = 0;
	while (acum[i] && acum[i] != '\n')
	{
		line[i] = acum[i];
		i++;
	}
	if (acum[i] == '\n')
	{
		line[i] = acum[i];
		i++;
	}
	return (line);
}

char	*ft_strjoin_gnl(char *acum, char *buf)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!acum)
	{
		acum = (char *)malloc(1 * sizeof(char));
		acum[0] = '\0';
	}
	if (!acum || !buf)
		return (NULL);
	result = malloc(((ft_strlen(acum) + ft_strlen(buf)) + 1) * (sizeof(char)));
	if (!result)
		return (NULL);
	i = -1;
	if (acum)
		while (acum[++i] != '\0')
			result[i] = acum[i];
	j = 0;
	while (buf[j] != '\0')
		result[i++] = buf[j++];
	result[i] = '\0';
	free(acum);
	return (result);
}

char	*ft_read_n_acum(int fd, char *acumulator)
{
	char	*buf;
	int		readed;

	if (!acumulator)
	{
		acumulator = malloc(1);
		acumulator[0] = '\0';
	}
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	readed = 1;
	while (!ft_strchr_gnl(acumulator, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		if (readed > 0)
			acumulator = ft_strjoin_gnl(acumulator, buf);
	}
	free(buf);
	return (acumulator);
}

char	*get_next_line(int fd)
{
	char		*result_line;
	static char	*arr_acum[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	arr_acum[fd] = ft_read_n_acum(fd, arr_acum[fd]);
	result_line = ft_copy_line(arr_acum[fd]);
	if (!arr_acum[fd])
	{
		free(result_line);
		result_line = malloc(1);
		result_line[0] = '\0';
 	}
	arr_acum[fd] = ft_update_acum(arr_acum[fd]);
	return (result_line);
}

#include <stdio.h>
int	main(void)
{
	int	fd1;
	int	fd2;
	char	*str;
	
	fd1 = open("my_file.txt", O_RDONLY);
	fd2 = open("my_file2", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	close (fd1);
	close (fd2);

	
	return (0);
}
