/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:35:06 by rimney            #+#    #+#             */
/*   Updated: 2021/12/14 19:46:07 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_assign(char **height, int fd)
{
	*height = get_next_line(fd);
	return (*height);
}

int	line_count(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int	ft_count_map_dimentions(t_map *map)
{
	int		fd;
	int		i;
	char	*width;

	fd = open(map->map_fd, O_RDONLY);
	i = 0;
	width = get_next_line(fd);
	map->width = ft_strlen(width) - 1;
	free(width);
	while (line_count(fd))
		i++;
	map->height = i + 1;
	return (0);
}

int	ft_parse_map(t_map *map)
{
	int	i;
	int	fd;

	i = 0;
	ft_count_map_dimentions(map);
	fd = open(map->map_fd, O_RDONLY);
	map->map_parsing = malloc(sizeof(char *) * map->height + 1);
	while ((ft_assign(&map->map_parsing[i], fd)))
		i++;
	map->map_parsing[i] = 0;
	ft_count_elements(map);
	return (i);
}

int	ft_check_map_len(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height - 1)
	{
		if (ft_strlen(map->map_parsing[i]) - 1 != map->width)
		{	
			return (0);
		}
		i++;
	}
	return (1);
}
