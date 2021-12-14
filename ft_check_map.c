/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:15:13 by rimney            #+#    #+#             */
/*   Updated: 2021/12/13 06:05:40 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	is_map(char c)
{
	return (c == 'C' || c == 'P' || c == '1'
		|| c == '0' || c == 'E' || c == '\n');
}

static int	is_top_bottom(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '\n' ))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_in_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_map(str[i]))
			return (0);
			i++;
	}
	return (1);
}

static int	ft_check_walls_middle(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] != '1' || str[len - 2] != '1')
		return (0);
	return (1);
}

int	ft_check_map(t_map *map)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	if (!is_top_bottom(map->map_parsing[0]))
		return (0);
	while (j < map->height - 1)
	{
		if (!ft_check_walls_middle(map->map_parsing[j])
			|| !ft_is_in_map(map->map_parsing[j]) || !ft_check_map_len(map))
			return (0);
		j++;
	}
	while (map->map_parsing[j][i])
	{
		if (map->map_parsing[j][i] != '1' && map->map_parsing[j][i] != '\0')
			return (0);
		i++;
	}
	if (ft_strlen(map->map_parsing[j]) != map->width)
		return (0);
	return (1);
}
