#include <stdio.h>
#include <stdlib.h>

int	inc_var(int x)
{	
	static int y = 1;
		
	y *= x;
	return (y);
}

int	main(void)
{
	printf("y = %d\n", inc_var(5));
	printf("y = %d\n", inc_var(5));
	printf("y = %d\n", inc_var(5));
}
