#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char    *ft_strjoin(char *acum, char *buf)
{
        char    *result;
        size_t  i;
        size_t  j;

        if (!acum)
        {
                acum = malloc(sizeof(char));
                *acum = '\0';
        }
        if (!acum || !buf)
                return (NULL);
        result = malloc(ft_strlen(acum) + ft_strlen(buf) + 1);
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



char    *get_next_line(int fd)
{
	int	buf_size = 7;
        char    buf[buf_size];
        static char     *tmp;
        		
        read(fd, buf, buf_size);
        tmp = ft_strjoin(tmp, buf);
        printf("tmp(43) = %s\n", tmp);
        read(fd, buf, buf_size);
        printf("buf(45) = %s\n", buf);
        tmp = ft_strjoin(tmp, buf);
        read(fd, buf, buf_size);
        printf("buf(47) = %s\n", buf);
        tmp = ft_strjoin(tmp, buf);
        return (tmp);
}

int     main(void)
{
        int     file_d;
        file_d = open("my_file.txt", O_RDONLY);
        printf("Acumulated string: %s\n", get_next_line(file_d));
        return (0);
}

