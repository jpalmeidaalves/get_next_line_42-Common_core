int     ft_has_linebreak(char *str )
{
        while (*str != '\0')
        {
                if (*str++ == '\n')
                        return (1);
        }
        return(0);
}
#include <stdio.h>
int	main(void)
{
	char	*s2 = "12345789";
	if (ft_has_linebreak(s2))	
		printf("yes - return 1");
	else
		printf("NO - return 0");
}
