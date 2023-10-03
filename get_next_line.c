#include "get_next_line.h"

char    *get_next_line(int fd)
{
  static char   *remainder = NULL;
  char          *buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
  int           bytes_read = 0;
  char          *newline = NULL;
  char          *line = NULL;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return NULL;

  while ((remainder == NULL || (newline = ft_strchr(remainder, '\n')) == NULL) && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
  {
    buffer[bytes_read] = '\0';
    if (remainder == NULL)
      remainder = ft_strdup(buffer);
    else
      remainder = ft_strjoin(remainder, buffer);
  }
  
  free(buffer);


  if (newline)
  {
    *newline = '\0';
    line = ft_strnew(newline - remainder);
    ft_strncpy(line, remainder, newline - remainder);
    remainder = ft_strdup(newline + 1);
  }
  else if (remainder)
  {
    line = ft_strdup(remainder);
    remainder = NULL;
  }


  return line;
}
