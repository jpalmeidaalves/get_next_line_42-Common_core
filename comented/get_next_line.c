#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_update_acum(char *acum)
{
	char	*new_acum;
	int	i;
	int	j;

	i = 0;	
	j = 0;
	while(acum[i] && acum[i] != '\n') //iterates acum up to '\n'
		i++;
	if (!acum)
	{
		free(acum);
		return (NULL);
	}
	new_acum = (char *)malloc(ft_strlen(acum) - i + 1);
	if (!new_acum)
		return (NULL);
	i++;	//increment index to go through de '\n'
	while (acum[i])
		new_acum[j++] = acum[i++]; 	//copies reamining(after '\n') chars to new_acum
	new_acum[j] = '\0';
	free(acum);
	return(new_acum);	
}

char	*ft_copy_line(char *acum)
{
	char	*line;
	int	i;

	i = 0;
	if (!acum)
		return(NULL);
	while (acum [i] && acum[i] != '\n')	//get lenght of the line up to the '\n'
		i++;
	line = (char *)malloc(i + 2); //allocates memory to acum + '\n' + '\0'
	if (!line)
		return (NULL);
	i = 0;
	while (acum[i] && acum[i] != '\n') //copies acum to line up till the '\n'
	{
		line[i] = acum[i];
		i++;
	}
	line[i++] = '\n';		//finish line with a '\n'
	line[i] = '\0';		//and put null terminator in the end
	return (line);
}

char	*ft_strjoin(char *acum, char *buf)	//concatenate the acumulated str with the buf 
						//returned by the read function
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!acum)	//if first time this function is called, acum does not exist
	{	
		acum = malloc(sizeof(char));	//then allocates memory to a char
		*acum = '\0';			// and initializes acum with a NULL termminator
	}
	if (!acum || !buf)
		return (NULL);
	result = malloc(ft_strlen(acum) + ft_strlen(buf) + 1);
	if (!result)
		return (NULL);
	i = -1;
	if (acum) //if acum already exists copies it to begin of start
		while (acum[++i] != '\0')
			result[i] = acum[i];	
	j = 0; 
	while (buf[j] != '\0')  //copies buf to result, after acum
		result[i++] = buf[j++];
	result[i] = '\0';
	free(acum);
	return (result);
}

char	*ft_read_n_acum(int fd, char *acumulator)
{
	char	*buf;	//Store string readed by read function
	int	readed;	//Store the value returned by the read function (number of readed bytes)

	buf = malloc(BUFFER_SIZE + 1);	//Initializes buf with malloc
	if (!buf)
		return (NULL);
	readed = 1;	//Initializes readed with 1 to avoid conflict in the next while
	while (!ft_strchr(acumulator, '\n') && readed != 0) //check if theres a '\n' in acumulator
							     //and if it's the end of the file. 
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)	//error check
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';	//finish buf with null terminator(what allows it to used 
					//in otherfunctions)
		acumulator = ft_strjoin(acumulator, buf);	//call function to concatenate the
								//acumulator with the new buffer
	}
	free(buf);
	return (acumulator);
}

char	*get_next_line(int fd)
{
	char		*result_l;	//line to be returned
	static char	*acumulator; 	//static variable to acumulate readed buffers
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	acumulator = ft_read_n_acum(fd, acumulator);	//function to read the file and store in 
							//acumalator the successives reads
	if (!acumulator)
		return (NULL);
	result_l = ft_copy_line(acumulator);	//reads the acumulator searching for '\n' and copying
						//the string from  start to the '\n'*
	acumulator = ft_update_acum(acumulator);	//update the acumulator with remaining chars 
							//buffered chars after '\n'
	return(result_l);
}

#include <stdio.h>
int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("my_file.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	fd2 = open("my_file2", O_RDONLY);
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));

	return (0);
}
