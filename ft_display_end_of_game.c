/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_end_of_game.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:53:51 by rimney            #+#    #+#             */
/*   Updated: 2021/12/13 18:36:55 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_is_next_to_the_door(t_map *map)
{
	if (map->player_position_x == map->door_position_x
		&& map->player_position_y == map->door_position_y)
		return (1);
	return (0);
}

void	ft_display_end_of_game(t_map *map)
{
	static int	i;

	i = 0;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}
