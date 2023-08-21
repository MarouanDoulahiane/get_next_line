#include "get_next_line.h"


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
