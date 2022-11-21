#include "get_next_line.h" 

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*adest;
	char	*asrc;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	adest = (char *)dest;
	asrc = (char *)src;
	while (n--)
		adest[n] = asrc[n];
	return (dest);
}
/*
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
}*/

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1;
	copy = (char *)malloc(sizeof(char) * len);
	if (!copy)
		return (0);
	ft_memcpy(copy, s, len);
	return (copy);
}
