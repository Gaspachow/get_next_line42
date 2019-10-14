/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:20:07 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/14 17:39:49 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE

int		get_next_line(int fd, char **line)
{
	unsigned char	buff[BUFFER_SIZE + 1];
	static char		*file_content;
	size_t			ret;
	char			*tmp;

	while (ret = read(fd, *buf, BUFFER_SIZE))
	{
		buff[ret] = '\0';
		if(!(tmp = ft_strjoin(file_content, buff)))
			return (-1);
		free(file_content);
		file_content = tmp;
	}
	if (!ret)
		return (0);
	while ()
}

int		*detect_nl(unsigned char *str)
{
	while (*str)
		if (*str == '\n')
			return (1);
	return (0);
}
