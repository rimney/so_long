/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:33:09 by rimney            #+#    #+#             */
/*   Updated: 2021/12/14 19:44:24 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moves_counter(int key, t_map *map)
{
	if (key == S_BUTTON || key == W_BUTTON
		|| key == A_BUTTON || key == D_BUTTON)
		printf("%d\n", map->moves_count);
	map->moves_count += 1;
	return (key);
}

int	ft_count_elements(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map_parsing[j])
	{
		i = 0;
		while (map->map_parsing[j][i])
		{
			if (map->map_parsing[j][i] == 'C')
				map->coin_count += 1;
			if (map->map_parsing[j][i] == 'E')
				map->door_count += 1;
			if (map->map_parsing[j][i] == 'P')
				map->player_count += 1;
			i++;
		}
		j++;
	}
	return (1);
}
