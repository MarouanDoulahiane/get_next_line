/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:17:50 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/04 20:43:40 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
// printf("deb!!\n"); fflush(stdout);

typedef struct data
{
	char	*remainder[256];
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	char	*line;
	int		bytes_read;
}	t_data;

int	helper(t_data *data, int fd)
{
	if (!data->remainder[fd])
		return (1);
	data->newline = ft_strchr(data->remainder[fd], '\n');
	if (data->newline)
	{
		data->line = malloc(data->newline - data->remainder[fd] + 1 + 1);
		if (!data->line)
			return (1);
		data->line[data->newline - data->remainder[fd]] = '\0';
		ft_strncpy(data->line, data->remainder[fd], 
			data->newline - data->remainder[fd] + 1);
		data->remainder[fd] = ft_strdup(data->newline + 1, data->remainder[fd]);
		if (!data->remainder[fd])
			return (1);
		return (0);
	}
	else if (!data->bytes_read && !data->remainder[fd][0])
		return (2);
	else if (!data->bytes_read)
	{
		data->line = ft_strdup(data->remainder[fd], data->remainder[fd]);
		data->remainder[fd] = NULL;
		return (0);
	}
	return (255);
}

char	*return_line(t_data *data, int fd)
{
	int	choice;

	data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	while (data->bytes_read >= 0)
	{
		data->buffer[data->bytes_read] = 0;
		data->remainder[fd] = ft_strjoin(data->remainder[fd], data->buffer);
		choice = helper(data, fd);
		if (choice == 0)
			return (data->line);
		if (choice == 1)
			return (NULL);
		else if (choice == 2)
			break ;
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	}
	free(data->remainder[fd]);
	data->remainder[fd] = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	if (!BUFFER_SIZE || fd == -1)
		return (NULL);
	if (!data.remainder[fd])
		data.remainder[fd] = ft_strdup("", NULL);
	return (return_line(&data, fd));
}
