/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:56:41 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/14 18:17:45 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (!(*(str + 1)))
			return (i + 1);
		if (!(*(str + 2)))
			return (i + 2);
		if (!(*(str + 3)))
			return (i + 3);
		if (!(*(str + 4)))
			return (i + 4);
		i += 5;
		str += 5;
	}
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (ptr1 < ptr2)
		while (n--)
			*(ptr1++) = *(ptr2++);
	else
		while (n--)
			*(ptr1 + n) = *(ptr2 + n);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	ft_memmove(new, s1, len1);
	ft_memmove(&new[len1], s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
