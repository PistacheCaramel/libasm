#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char * ft_strcpy(char *dest, const char *src);
extern int ft_strlen(char *s);
extern int ft_strcmp(const char *s1, const char *s2);

int	main(int ac, char **av)
{
	//char	*str;

	(void)ac;
	//str = calloc(ft_strlen(av[1]) + 1, sizeof(char));
	//printf("%s\n", ft_strcpy(str, av[1]));
	//printf("%s\n", ft_strcpy(str, av[1]));
	//free(str);
	printf("strcmp:%d\n", strcmp(av[1], av[2]));
	printf("ft_strcmp:%d\n", ft_strcmp(av[1], av[2]));
	return (0);
}
