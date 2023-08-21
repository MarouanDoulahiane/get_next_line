#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strncpy(char *dest, const char *src, size_t n);
char    *get_next_line(int fd);

#endif
