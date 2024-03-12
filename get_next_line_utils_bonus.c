/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:39:46 by natamazy          #+#    #+#             */
/*   Updated: 2024/01/31 16:39:51 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t k)
{
	char	*r_s;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r_s = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		r_s[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && k--)
	{
		r_s[j++] = s2[i];
		i++;
	}
	r_s[j] = '\0';
	return (r_s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*new_line_finder(char *buff, char **line)
{
	char	*new_line_address;
	char	*tmp;
	int		buff_len;

	new_line_address = ft_strchr(buff, '\n');
	if (new_line_address)
	{
		tmp = *line;
		*line = ft_strjoin(*line, buff, new_line_address - buff + 1);
		free(tmp);
		ft_strlcpy(buff, new_line_address + 1, BUFFER_SIZE);
		return (*line);
	}
	else
	{
		buff_len = ft_strlen(buff);
		tmp = *line;
		*line = ft_strjoin(*line, buff, buff_len);
		free(tmp);
	}
	return (NULL);
}
