/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:20:07 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/28 16:12:37 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*str[300];
	int				ret;
	char			*tmp;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(check_nl(str[fd])) && ((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
	}
	free(buff);
	if (!str[fd])
		if ((*line = ft_strdup("")))
			return (0);
	return (create_line(&str[fd], line));
}

int		create_line(char **str, char **line)
{
	size_t	len;
	char	*newline;
	char	*tmp;

	if (!*str)
		return (-1);
	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\0')
		return (last_line(str, line));
	if (!(newline = malloc((len + 1) * sizeof(char))))
		return (-1);
	ft_memmove(newline, *str, len);
	newline[len] = '\0';
	tmp = ft_substr(*str, len + 1, (ft_strlen(*str) - (len + 1)));
	free(*str);
	*str = tmp;
	*line = newline;
	return (1);
}

int		last_line(char **str, char **line)
{
	char	*newline;

	newline = ft_strdup(*str);
	free(*str);
	*str = NULL;
	*line = newline;
	return (0);
}

int		check_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		else
			str++;
	}
	return (0);
}
