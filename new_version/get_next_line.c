/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:14:56 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/04 17:27:02 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000000
#endif
// printf("deb!!\n"); fflush(stdout);

typedef struct data
{
	char	*remainder;
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	char	*line;
	int		bytes_read;
}	t_data;

char	*helper1(t_data *data, int fd)
{
	char *tmp;

	data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	while (data->bytes_read >= 0)
	{
		data->buffer[data->bytes_read] = 0;
		data->remainder = ft_strjoin(data->remainder, data->buffer);
		if (!data->remainder)
			return (NULL);
		data->newline = ft_strchr(data->remainder, '\n');
		if (data->newline)
		{
			data->line = malloc(data->newline - data->remainder + 1 + 1);
			data->line[data->newline - data->remainder] = '\0';
			if (!data->line)
				return (NULL);
			ft_strncpy(data->line, data->remainder, data->newline - data->remainder + 1);
			data->remainder = ft_strdup(data->newline + 1, data->remainder);
			if (!data->remainder)
				return (NULL);
			return (data->line);
		}
		else if (!data->bytes_read && !data->remainder[0])
			break ;
		else if (!data->bytes_read)
		{
			data->line = ft_strdup(data->remainder, data->remainder);
			data->remainder = NULL;
			return (data->line);
		}
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	}
	free(data->remainder);
	data->remainder = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	if (!BUFFER_SIZE || fd == -1)
		return (NULL);
	return (helper1(&data, fd));
}
