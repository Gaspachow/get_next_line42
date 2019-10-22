/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:20:07 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/22 15:33:23 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str;
	int				ret;
	char			*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	while (!(check_nl(str)) && ((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(str, buff)))
			return (-1);
		free(str);
		str = tmp;
	}
	if (!str)
	{
		return (0);
	}
	else if ((*line = create_line(&str)))
		return (1);
	else
		return (-1);
}

char	*create_line(char **str)
{
	size_t	len;
	char	*newline;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\0' || (*str)[len + 1] == '\0') // -------- "|| (*str)[len + 1] == '\0'" to ignore last newline
		return (last_line(str));
	if (!(newline = malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memmove(newline, *str, len);
	newline[len] = '\0';
	tmp = ft_substr(*str, len + 1, (ft_strlen(*str) - (len + 1)));
	free(*str);
	*str = tmp;
	return (newline);
}

char	*last_line(char **str)
{
	char	*newline;

	newline = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (newline);
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
