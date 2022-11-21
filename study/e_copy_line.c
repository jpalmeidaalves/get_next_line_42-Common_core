#include<stdlib.h>
#include "get_next_line.h"

char    *ft_copy_line(char *acum)
{
        char    *line;
        int     i;

        i = 0;
        if (!acum)
                return(NULL);
        while (acum [i] && acum[i] != '\n')     //get lenght of the line up to the '\n'
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
        line[i++] = '\n';         //finish line with a '\n'
        line[i] = '\0';           //and put null terminator in the end
        return (line);
}


#include <stdio.h>
#include <string.h>

int     main(void)
{
        char str[] = "1asdfga234\n56789";
        char    *ptr_str;
        ptr_str = ft_copy_line(str);
        printf("%s\n ", ptr_str);
        printf("%s\n", str);
        return (0);
}
