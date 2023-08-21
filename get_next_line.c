#include "get_next_line.h"

char    *get_next_line(int fd)
{
  static char   *remainder = NULL;
  char          buffer[BUFFER_SIZE + 1];
  int           bytes_read = 0;
  char          *newline = NULL;
  char          *line = NULL;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return NULL;

  while ((newline = ft_strchr(remainder, '\n')) == NULL && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
  {
    buffer[bytes_read] = '\0';
    remainder = ft_strjoin(remainder, buffer);
  }

  if (newline)
  {
    *newline = '\0';
    line = ft_strdup(remainder);
    newline = ft_strdup(newline + 1);
    free(remainder);
    remainder = newline;
  }
  else if (!bytes_read && remainder)
  {
    line = ft_strdup(remainder);
    free(remainder);
    remainder = NULL;
  }

  return line;
}
