/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:37:38 by rimney            #+#    #+#             */
/*   Updated: 2021/12/13 19:01:03 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assign_map(t_map *map, int i, int j)
{
	if (map->map_parsing[j][i] == '\n')
		i++;
	if (map->map_parsing[j][i] == '1')
		ft_draw_wall(map);
	if (map->map_parsing[j][i] == '0')
		ft_draw_floor(map);
	if (map->map_parsing[j][i] == 'C')
		ft_draw_coin(map);
	if (map->map_parsing[j][i] == 'E')
	{
		map->door_position_y = j;
		map->door_position_x = i;
		ft_draw_door(map);
	}
	if (map->map_parsing[j][i] == 'P')
	{
		map->player_position_x = i;
		map->player_position_y = j;
		ft_draw_player(map);
	}
}

void	ft_put_images(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map_parsing[j])
	{
		i = 0;
		while (map->map_parsing[j][i])
		{
			map->map_x = i * 80;
			map->map_y = j * 80;
			ft_assign_map(map, i, j);
			i++;
		}
		j++;
	}
}

void	ft_assign_images(t_map *map)
{
	map->yajora_path = "./xpms/yajora.xpm";
	map->wall_img_path = "./xpms/wall.xpm";
	map->player_img_path = "./xpms/player.xpm";
	map->door_locked_path = "./xpms/door_locked.xpm";
	map->door_opened_path = "./xpms/door_opened.xpm";
	map->coin_path = "./xpms/coin.xpm";
	map->wall_img = mlx_xpm_file_to_image(map->mlx_ptr, map->wall_img_path,
			&map->xml_w, &map->xml_h);
	map->yajora_img = mlx_xpm_file_to_image(map->mlx_ptr, map->yajora_path,
			&map->xml_w, &map->xml_h);
	map->player_img = mlx_xpm_file_to_image(map->mlx_ptr, map->player_img_path,
			&map->xml_w, &map->xml_h);
	map->door_locked_img = mlx_xpm_file_to_image(map->mlx_ptr,
			map->door_locked_path, &map->xml_w, &map->xml_h);
	map->door_opened_img = mlx_xpm_file_to_image(map->mlx_ptr,
			map->door_opened_path, &map->xml_w, &map->xml_h);
	map->coin_img = mlx_xpm_file_to_image(map->mlx_ptr, map->coin_path,
			&map->xml_w, &map->xml_h);
}

void	ft_draw_map(t_map *map)
{
	ft_assign_images(map);
	ft_put_images(map);
	if (map->coin_count == 0)
		ft_swich_door(map);
	if (ft_player_is_next_to_the_door(map))
		ft_display_end_of_game(map);
	mlx_key_hook(map->win_ptr, &ft_moves, map);
	mlx_hook(map->win_ptr, 17, 1L << 0, ft_close, map);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	map.map_fd = argv[1];
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !ft_check_filename(argv[1]))
		return (ft_put_error(1));
	if (argc == 2)
	{
		ft_parse_map(&map);
		if (!ft_check_map(&map) || !ft_check_map_elements(&map))
			return (ft_put_error(0));
		map.mlx_ptr = mlx_init();
		map.win_ptr = mlx_new_window(map.mlx_ptr, map.width * 80,
				map.height * 80, "so_long");
		ft_draw_map(&map);
		mlx_loop(map.mlx_ptr);
	}
	return (0);
}
