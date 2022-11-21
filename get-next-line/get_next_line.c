#include "get_next_line.h"

char	*get_next_line(int fd)
{
        static char     *tmp;
	char		*buf;
        int     		buf_size = 4;
	
	
	
}       

int     main(void)
{
        int	file_d; 
	file_d = open("my_file.txt", O_RDONLY);
	printf("%s\n", get_next_line(file_d));
        return (0);
}

