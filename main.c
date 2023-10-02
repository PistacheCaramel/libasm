#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

extern char * ft_strcpy(char *dest, const char *src);
extern int ft_strlen(char *s);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern	ssize_t ft_read(int fd, void *buf, size_t count);
extern  char *ft_strdup(const char *s);

int	main(int ac, char **av)
{
	//char	*str;

	(void)ac;
	(void)av;
	//char	*str;
	char	*buffer;
	int fd;
	buffer = calloc(sizeof(char), 50);
	fd = open("ft_read.s", O_RDONLY);
	//str = calloc(ft_strlen(av[1]) + 1, sizeof(char));
	//printf("%s\n", ft_strcpy(str, av[1]));
	//printf("%s\n", ft_strcpy(str, av[1]));
	//free(str);
	//printf("strcmp:%d\n", strcmp(av[1], av[2]));
	//printf("ft_strcmp:%d\n", ft_strcmp(av[1], av[2]));
	//printf("%ld\n", write(6, NULL, 7));
	//perror(NULL);
	//printf("%ld\n", ft_write(6, NULL, 7));
	//perror(NULL);
	printf("%ld\n", read(fd, NULL, 49));
	perror(NULL);
	printf("%s\n", buffer);
	bzero(buffer, 50);
	close(fd);	
	fd = open("ft_read.s", O_RDONLY);
	printf("%ld\n", ft_read(fd, NULL, 49));
	perror(NULL);
	printf("%s\n", buffer);
	close(fd);
	free(buffer);
	/*str = strdup(av[1]);
	printf("%s\n", str);
	free(str);
	str = ft_strdup(av[1]);
	printf("%s\n", str);
	free(str);*/
	return (0);
}
