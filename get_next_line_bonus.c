#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
  static char   *remainder[8192] = {NULL};
  char          *buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
  int           bytes_read = 0;
  char          *newline = NULL;
  char          *line = NULL;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return NULL;

	while ((!remainder[fd] || (newline = ft_strchr(remainder[fd], '\n')) == NULL) && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
  {
    buffer[bytes_read] = '\0';
		if (remainder[fd] == NULL)
			remainder[fd] = ft_strdup(buffer);
		else
		  remainder[fd] = ft_strjoin(remainder[fd], buffer);
  }

  free(buffer);

  if (newline)
{
		*newline = '\0';
    line = ft_strnew(newline - remainder[fd]);
    ft_strncpy(line, remainder[fd], newline - remainder[fd]);
    remainder[fd] = ft_strdup(newline + 1);
}
  else if (!bytes_read && remainder[fd])
  {
    line = ft_strdup(remainder[fd]);
    remainder[fd] = NULL;
  }

  return line;
}
