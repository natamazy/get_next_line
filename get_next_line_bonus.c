/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:02 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/12 11:32:50 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	while ((i < (dstsize - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	int			read_size;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff[fd], 0) < 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	read_size = 1;
	while (read_size > 0)
	{
		if (new_line_finder(buff[fd], &line))
			return (line);
		read_size = read(fd, buff[fd], BUFFER_SIZE);
		if (read_size < 0)
			break ;
		buff[fd][read_size] = '\0';
	}
	if (*line && read_size >= 0)
		return (line);
	free(line);
	return (NULL);
}
