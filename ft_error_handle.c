/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:02:01 by rimney            #+#    #+#             */
/*   Updated: 2021/12/13 06:05:50 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	ft_check_map_elements(t_map *map)
{
	if (map->coin_count < 1)
		return (0);
	if (map->player_count != 1)
		return (0);
	if (map->door_count != 1)
		return (0);
	return (1);
}

int	ft_put_error(int error)
{
	if (error == 0)
		ft_putstr_fd("Invalid map !\n", 2);
	if (error == 1)
		ft_putstr_fd("file not found\n", 2);
	return (0);
}
