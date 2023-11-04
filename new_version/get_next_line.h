/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:14:01 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/04 17:21:10 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1, char *old_remainder);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(const char *s);

#endif
