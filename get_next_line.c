/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:37:57 by rimney            #+#    #+#             */
/*   Updated: 2021/12/13 06:07:10 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_get_line(char **rest, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
		i++;
	if ((*rest)[i] == '\n')
	{
		*line = ft_substr(*rest, 0, ++i);
		temp = *rest;
		*rest = ft_strdup(*rest + i);
		ft_free(&temp);
	}
	else
	{
		*line = ft_strdup(*rest);
		ft_free(rest);
	}
	if ((*line)[0] == '\0')
		ft_free(line);
}

void	ft_read(int fd, char **rest, char **line, char **buf)
{
	ssize_t	ret;
	char	*temp;

	ret = 1;
	while (ret && !ft_strchr(*rest, '\n'))
	{
		ret = read(fd, *buf, BUFFER_SIZE);
		(*buf)[ret] = '\0';
		temp = *rest;
		*rest = ft_strjoin(temp, *buf);
		ft_free(&temp);
	}
	ft_free(buf);
	ft_get_line(rest, line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		ft_free(&buf);
		return (NULL);
	}
	if (!rest)
		rest = ft_strdup("");
	ft_read(fd, &rest, &line, &buf);
	return (line);
}
