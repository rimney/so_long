/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:19:58 by rimney            #+#    #+#             */
/*   Updated: 2021/12/14 19:46:17 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define S_BUTTON 1
# define A_BUTTON 0
# define ESC_BUTTON 53
# define W_BUTTON 13
# define D_BUTTON 2
# include "get_next_line.h"
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int		width;
	int		height;
	void	*win_ptr;
	void	*mlx_ptr;
	char	*wall_img_path;
	void	*wall_img;
	char	*yajora_path;
	void	*yajora_img;
	char	*coin_path;
	void	*coin_img;
	char	*door_locked_path;
	void	*door_locked_img;
	char	*door_opened_path;
	char	*door_opened_img;
	int		xml_w;
	int		xml_h;
	char	*player_img_path;
	void	*player_img;
	int		player_position_x;
	int		player_position_y;
	int		door_position_x;
	int		door_position_y;
	char	**map_parsing;
	char	*map_fd;
	int		map_x;
	int		map_y;
	int		coin_count;
	int		door_count;
	int		player_count;
	int		moves_count;
}	t_map;
void	ft_draw_map(t_map *map);
int		ft_check_map(t_map *map);
int		ft_count_map_dimentions(t_map *map);
int		ft_parse_map(t_map *map);
int		ft_check_map_len(t_map *map);
void	ft_draw_wall(t_map *map);
void	ft_draw_floor(t_map *map);
void	ft_draw_coin(t_map *map);
void	ft_draw_door(t_map *map);
void	ft_draw_player(t_map *map);
int		ft_count_elements(t_map *map);
void	ft_print_2d(t_map *map);
int		ft_moves(int key, t_map *map);
void	ft_move_p_right(t_map *map);
void	ft_move_p_down(t_map *map);
void	ft_move_p_left(t_map *map);
void	ft_move_p_up(t_map *map);
int		ft_put_error(int error);
int		ft_check_map_elements(t_map *map);
void	ft_swich_door(t_map *map);
int		ft_player_is_next_to_the_door(t_map *map);
void	ft_display_end_of_game(t_map *map);
int		ft_close(t_map *map);
void	ft_key_move_p_right(t_map *map);
void	ft_key_move_p_left(t_map *map);
void	ft_key_move_p_up(t_map *map);
void	ft_key_move_p_down(t_map *map);
int		ft_moves_counter(int key, t_map *map);
int		ft_check_filename(char *name);
#endif
