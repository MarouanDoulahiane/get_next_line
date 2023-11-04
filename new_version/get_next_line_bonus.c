/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:10:58 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/04 14:29:13 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

typedef struct data
{
	char	*remainder[256];
	char	*buffer;
	char	*newline;
	char	*line;
	int		bytes_read;
}	t_data;

void	helper1(t_data *data, int fd)
{
	while ((!data->remainder[fd] || !data->newline) && data->bytes_read > 0)
	{
		data->buffer[data->bytes_read] = '\0';
		if (data->remainder[fd] == NULL)
			data->remainder[fd] = ft_strdup(data->buffer);
		else
			data->remainder[fd] = ft_strjoin(data->remainder[fd], data->buffer);
		if (data->remainder[fd])
			data->newline = ft_strchr(data->remainder[fd], '\n');
		if (!data->remainder[fd] || !data->newline)
		{
			data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
			data->buffer[data->bytes_read] = '\0';
		}
	}
	free(data->buffer);
}

char	*helper2(t_data *data, int fd)
{
	size_t	size;

	size = data->newline - data->remainder[fd] + 1;
	if (data->newline)
	{
		data->line = malloc(data->newline - data->remainder[fd] + 1 + 1);
		ft_strncpy(data->line, data->remainder[fd], size);
		free(data->remainder[fd]);
		data->remainder[fd] = ft_strdup(data->newline + 1);
	}
	else if (data->remainder[fd])
	{
		data->line = ft_strdup(data->remainder[fd]);
		free(data->remainder[fd]);
		data->remainder[fd] = NULL;
	}
	return (data->line);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	data.bytes_read = 0;
	data.newline = NULL;
	data.line = NULL;
	if (data.remainder[fd])
		data.newline = ft_strchr(data.remainder[fd], '\n');
	if (!data.remainder[fd] || !data.newline)
		data.bytes_read = read(fd, data.buffer, BUFFER_SIZE);
	helper1(&data, fd);
	return (helper2(&data, fd));
}
