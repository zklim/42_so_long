/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:26:46 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/20 16:45:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coord(t_map *map, int x, int y)
{
	if (map->grid[x][y] == COLLECTIBLE)
		map->collected++;
	else if (map->grid[x][y] == EXIT)
	{
		if (map->exit_opened != 0)
			map->exited = 1;
	}
	else if (map->grid[x][y] == WALL)
		return ;
	map->player_x = x;
	map->player_x = y;
}

void	key_check(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		ft_printf("Window closing\n");
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_error_exit(map, 0);
	}
	if (keycode == W || keycode == UP)
	{
		check_coord(map, map->player_x, map->player_y - 1);
	}
}

int	key_hook(int keycode, t_map *map)
{
	key_check(keycode, map);
	return (0);
}