#include<stdlib.h>
#include "get_next_line.h"

char    *ft_update_acum(char *acum)
{
        char    *new_acum;
        int     i;
        int     j;

        i = 0;
        j = 0;
        while(acum[i] && acum[i] != '\n')
                i++;
        if (!acum)
        {
                free(acum);
                return (NULL);
        }
        new_acum = (char *)malloc(ft_strlen(acum) - i + 1);
        if (!new_acum)
                return (NULL);
        i++;
        while (acum[i])
                new_acum[j++] = acum[i++];
        new_acum[j] = '\0';
        free(acum);
        return(new_acum);
}


#include <stdio.h>
#include <string.h>

int     main(void)
{
        char *str = malloc(11);
	str = strcpy(str, "1234\n56789");
        char    *ptr;
        ptr = ft_update_acum(str);
        printf("ptr: %s\n", ptr);
        printf("ptr lenght:%ld\n", strlen(ptr) );
        printf("freed memory: %s\n ", str);
        return (0);
}
