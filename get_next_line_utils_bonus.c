#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strncpy(char *dest, const char *src, size_t n)
{
        size_t  i;

        i = 0;
        while (src[i] && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
                dest[i++] = '\0';
        return (dest);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	if (!(result = malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
		result[i++] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
  while (*s != '\0')
  {
    if (*s == c)
      return ((char *)s);
    s++;
  }
  if (*s == c)
    return ((char *)s);
  return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(result))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
