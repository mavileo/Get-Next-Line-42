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
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	printf("%s\n", line);
}
