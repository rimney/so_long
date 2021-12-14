/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:45:46 by rimney            #+#    #+#             */
/*   Updated: 2021/12/13 15:41:30 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moves(int key, t_map *map)
{
	if (key == D_BUTTON)
		ft_key_move_p_right(map);
	if (key == A_BUTTON)
		ft_key_move_p_left(map);
	if (key == S_BUTTON)
		ft_key_move_p_down(map);
	if (key == W_BUTTON)
		ft_key_move_p_up(map);
	if (key == ESC_BUTTON)
		exit(0);
	ft_draw_map(map);
	ft_moves_counter(key, map);
	return (1);
}
