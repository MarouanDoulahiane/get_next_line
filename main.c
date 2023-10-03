#include "get_next_line.h"
#include <stdio.h>
int main() {
	int fd = open("test", O_CREAT | O_RDWR);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
	}
	
	return 0;
}