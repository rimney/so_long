/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:47:50 by rimney            #+#    #+#             */
/*   Updated: 2021/12/14 15:27:41 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_map *map)
{
	exit(0);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	return (0);
}

void	ft_key_move_p_right(t_map *map)
{
	if (map->map_parsing[map->player_position_y]
		[map->player_position_x + 1] == '0')
		ft_move_p_right (map);
	else if (map->map_parsing[map->player_position_y]
		[map->player_position_x + 1] == 'C')
	{
		ft_move_p_right(map);
		map->coin_count -= 1;
	}
}

void	ft_key_move_p_left(t_map *map)
{
	if (map->map_parsing[map->player_position_y]
		[map->player_position_x - 1] == '0')
		ft_move_p_left(map);
	else if (map->map_parsing[map->player_position_y]
		[map->player_position_x - 1] == 'C')
	{
		ft_move_p_left(map);
		map->coin_count -= 1;
	}
}

void	ft_key_move_p_down(t_map *map)
{
	if (map->map_parsing[map->player_position_y + 1]
		[map->player_position_x] == '0')
		ft_move_p_down(map);
	else if (map->map_parsing[map->player_position_y + 1]
		[map->player_position_x] == 'C')
	{
		ft_move_p_down(map);
		map->coin_count -= 1;
	}
}

void	ft_key_move_p_up(t_map *map)
{
	if (map->map_parsing[map->player_position_y - 1]
		[map->player_position_x] == '0')
		ft_move_p_up(map);
	else if (map->map_parsing[map->player_position_y - 1]
		[map->player_position_x] == 'C')
	{
		ft_move_p_up(map);
		map->coin_count -= 1;
	}
}
