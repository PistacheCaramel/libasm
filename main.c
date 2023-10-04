#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <errno.h>
       #include <sys/wait.h>

extern char * ft_strcpy(char *dest, const char *src);
extern int ft_strlen(char *s);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern	ssize_t ft_read(int fd, void *buf, size_t count);
extern  char *ft_strdup(const char *s);

void	test_ft_strcpy()
{
	char	dest[100];
	char	*src;

	src = "coucou";
	if (!strncmp(ft_strcpy(dest, src), src, strlen(src) + 1))
		printf("Test1: OK\n");
	else
		printf("Test1: FALSE\nsrc:%s\nres:%s\n", src, ft_strcpy(dest, src));
	src = "";
	if (!strncmp(ft_strcpy(dest, src), src, strlen(src) + 1))
		printf("Test2: OK\n");
	else
		printf("Test2: FALSE\nsrc:%s\nres:%s\n", src, ft_strcpy(dest, src));

}

void	check_strcmp(char *s1, char *s2, int test)
{
	int	a;
	int	b;

	a = strcmp(s1, s2);
	b = ft_strcmp(s1, s2);
	if (a == b || (a < 0 && b < 0) || (a > 0 && b > 0))
		printf("Test%d: OK\n", test);
	else
		printf("Test%d: FALSE\ns1:%s\ns2:%s\nstrcmp:%d\nft_strcmp:%d\n", test, s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

}
void	test_ft_strcmp()
{
	char	*s1;
	char	*s2;

	s1 = "sl";
	s2 = "slo";
	check_strcmp(s1, s2, 1);
	s1 = "slo";
	s2 = "sl";
	check_strcmp(s1, s2, 2);
	s1 = "";
	s2 = "42";
	check_strcmp(s1, s2, 3);
	s1 = "42";
	s2 = "";
	check_strcmp(s1, s2, 4);
	s1 = "";
	s2 = "";
	check_strcmp(s1, s2, 5);
	s1 = "4242";
	s2 = "4242";
	check_strcmp(s1, s2, 6);
	s1 = "lo";
	s2 = "slo";
	check_strcmp(s1, s2, 7);
	check_strcmp(s2, s1, 8);

	
}

void	print_buffer(char *buffer, size_t size)
{	
	if (buffer)
	{
		size_t	i = 0;
		while (i < size && buffer[i])
			i++;
		if (i == size)
			write(1, buffer, size);
		else
			write(1, buffer, i);
	       printf("\n");
	}
	else
		printf("No buffer\n");
}
void	write_checks(void *buffer, size_t size, int test)
{
	int	fd;
	int	fd1;
	int	res;
	size_t	write_sys;
	size_t	my_write;
	int	errno_sys;
	int	my_errno;

	fd = open("systest", O_CREAT | O_TRUNC, O_RDWR);
	if (fd < 0)
		perror("fd0");
	fd1 = open("test1", O_CREAT | O_TRUNC, O_RDWR);
	if (fd1 < 0)
		perror("fd1");
	write_sys = write(fd, buffer, size);
	errno_sys = errno;
	my_write = ft_write(fd1, buffer, size);
	my_errno = errno;
	lseek(fd, 0, SEEK_SET);
	lseek(fd1, 0, SEEK_SET);
	char	buffer0[size + 1];
	char	buffer1[size + 1];
	bzero(buffer0, size + 1);
	bzero(buffer1, size + 1);
	if (read(fd, buffer0, size) < 0)
	{
		perror("read");
		return;
	}
	if (read(fd1, buffer1, size) < 0)
	{
		perror("read");
		return;
	}
	if (close(fd) < 0)
		perror("close");
	if (close(fd1) < 0)
		perror("close");
	res = memcmp(buffer0, buffer1, size);
	if (res == 0 && errno_sys == my_errno && my_write == write_sys)
		printf("Test%d: OK\n", test);
	else
	{
		printf("Test%d: FALSE\nwrite_sys:%ld\nft_write:%ld\nerrno_sys:%d\nerrno_ft_write:%d\n", test, write_sys, my_write, errno_sys, my_errno);
		write(1, "buffer_write_sys:", strlen("buffer_write_sys:"));
		print_buffer(buffer0, size);
		write(1, "buffer_ft_write:", strlen("buffer_write_sys:"));
		print_buffer(buffer1, size);
		printf("\n");
	}
}

void	test_ft_write()
{
	printf("Test with files:\n");
	write_checks("coucou", 7, 1);
	write_checks("", 1, 2);
	write_checks(NULL, 1, 3);
	remove("systest");
	remove("test1");
}
int	main()
{
	printf("-----TESTS ft_strcpy-----\n\n");
	test_ft_strcpy();
	printf("-----TESTS ft_strcmp-----\n\n");
	test_ft_strcmp();
	printf("-----TESTS ft_write-----\n\n");
	test_ft_write();
	//char	*str;

//	(void)ac;
//	(void)av;
	//char	*str;
/*	char	*buffer;
	int fd;
	buffer = calloc(sizeof(char), 50);
	fd = open("ft_read.s", O_RDONLY);*/
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
	/*printf("%ld\n", read(fd, NULL, 49));
	perror(NULL);
	printf("%s\n", buffer);
	bzero(buffer, 50);
	close(fd);	
	fd = open("ft_read.s", O_RDONLY);
	printf("%ld\n", ft_read(fd, NULL, 49));
	perror(NULL);
	printf("%s\n", buffer);
	close(fd);
	free(buffer);*/
	/*str = strdup(av[1]);
	printf("%s\n", str);
	free(str);
	str = ft_strdup(av[1]);
	printf("%s\n", str);
	free(str);*/
	return (0);
}
