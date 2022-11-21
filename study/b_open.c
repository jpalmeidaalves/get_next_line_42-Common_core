#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_print_array(char **array)
{
	int i;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; array[i] != NULL; i++)
			printf("%d - %s\n", i, array[i]);
		printf("%d - NULL\n", i);
	}
}

int	main(void)
{
	char 	**arr;
	char	buf[45];
	int my_file_fd = open("my_file.txt", O_RDWR | O_CREAT, 0777);
	ft_putstr_fd("Testing open function.\n", my_file_fd);
	ft_putstr_fd("Testing append text.\n", my_file_fd);
	close(my_file_fd);
	my_file_fd = open("my_file.txt", O_RDONLY);
	read(my_file_fd, buf, 45);
	buf[44] = '\0';
	arr = ft_split(buf, '\n');
	ft_print_array(arr);	
	return (0);
}
