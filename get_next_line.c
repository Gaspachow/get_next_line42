/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:20:07 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/14 19:16:32 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 256

int		get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	static char		*str;
	size_t			ret;
	char			*tmp;

	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		if(!(tmp = ft_strjoin(str, buff)))
			return (-1);
		free(str);
		str = tmp;
	}
	if (!ret && str[0] == '\0')
		return (0);
	if ((*line = create_line(str, line, fd)))
		return (1);
	else
		return (-1);
}

char	*create_line(char *str, char **line, int fd)
{
	size_t	len;
	char	*newline;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
	{
		newline = malloc((len + 1) * sizeof(char));
		ft_memmove(newline, str, len);
		newline[len] = '\0';
		return (newline);
	}
	else
		get_next_line(fd, line);
	return (0);
}
