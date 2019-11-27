#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/* int main()
{
	int fd = open("testfile.txt", O_RDONLY);
	char buff[10];
	buff[9] = 0;
	int res = read(fd, buff, 10);
	printf("%s\n", buff);
	int res2 = read(fd, buff, 10);
	printf("%s\n", buff);
} */

int main()
{
	int fd = open("testfile.txt", O_RDONLY);
	char *line;
	int count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		printf("%s\n", line);
	}
	printf("%s\n", line);
}

/* int main()
{
	char *s1 = NULL;
	char s2[] = "dfgwe";
	char *rest;
	rest = malloc(sizeof(char) * 100);
	ft_strjoin(s1, s2, rest);
	printf("1\n");
	char *s4 = NULL;
	char s3[] = "dfgwe";
	ft_strjoin(s3, s4, rest);
	printf("2\n");
	char *s5 = NULL;
	char *s6 = NULL;
	ft_strjoin(s1, s2, rest);
	printf("3\n");
}
 */