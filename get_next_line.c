/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:20:07 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/14 16:29:33 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE

int	get_next_line(int fd, char **line)
{
	unsigned char buff[BUFFER_SIZE + 1];
	static char *file_content;
	size_t	ret;

	while (ret = read(fd, *buf, BUFFER_SIZE))
	{
		buf[ret] = '\0';
	}


	while (*buf != '\n')
	{
		**line = *buff;
		*line++;
		buff++;
	}
}

int	gnl_reader(int fd, char *file)
{

}

int	*detect_newline(unsigned char *str)
{
	while (*str)
		if (*str == '\n')
			return (1);
	return (0);
}

size_t line_len(unsigned char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\n' && *str != 'EOF')
		i++;
	return (i);
}