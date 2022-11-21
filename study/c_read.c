#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char    *ft_strnjoin(char *str1, char *str2, int n)
{
        char    *result;
        int     i;
        int     j;

        i = 0; 
        j = 0; 
        result = malloc(ft_strlen(str1) + n + 1);
        if (!result)
                return (NULL);
        if (str1 == NULL)
        {
                ft_memcpy(result, str2, ft_strlen(str2));
                return (result);
        }
        while (str1[i] != '\0')
        {
                result[i] = str1[i];
                i++;
        }
        while (str2[j] != '\0' && j < n)
                result[i++] = str2[j++];
        result[i] = '\0';
        return (result);
}

int	main(void)
{
	char	buf[4];
	int	my_file_fd;
	static char* tmp;
	
	my_file_fd = open("my_file2", O_RDONLY);
	read(my_file_fd, buf, 4);
	tmp = ft_strdup(buf);
	while (read(my_file_fd, buf, 4) == 4)	
		tmp = ft_strnjoin(tmp, buf, 4);

/*	int z = read(my_file_fd, buf, 6);
	printf("l10 - %s\n", buf);
	printf("l10 - read returns %d\n", z);
	int y =	read(my_file_fd, buf, 6);
	printf("l12 - %s\n", buf);
	printf("l12 - read returns %d\n", y);
	int x = read(my_file_fd, buf, 6);
	printf("l14 - %s\n", buf);
	printf("l14 - read returns %d\n", x);
*/		
	return (0);
}
