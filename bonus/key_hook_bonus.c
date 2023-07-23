/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:26:46 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/23 12:47:39 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// int draw_char(t_map *map, int cache_x, int cache_y, t_sprite *dir)
// {
// 	if (map->exit.x == map->player.x && map->exit.y == map->player.y)
// 		mlx_put_image_to_window(map->mlx, map->mlx_win,
// 			map->graphic.exit_closed.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
// 	else
// 	{
// 		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.background.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
// 		mlx_put_image_to_window(map->mlx, map->mlx_win, dir->img[0], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
// 	}
// 	mlx_put_image_to_window(map->mlx, map->mlx_win,
// 			map->graphic.background.img, cache_x * TILESIZE_X, cache_y * TILESIZE_Y);
// 	return 0;
// }

int	check_component(t_map *map, int x, int y)
{
	if (map->grid[y][x] == COLLECTIBLE)
	{
		map->collected++;
		map->grid[y][x] = EMPTY;
		if (map->collected == map->collectible_count)
			map->exit_opened = 1;
	}
	else if (map->grid[y][x] == EXIT)
	{
		if (map->exit_opened)
			map->exited = 1;
		else
			return 0;
	}
	else if (map->grid[y][x] == WALL)
		return 0;
	return 1;
}

void	check_coord(t_map *map, int x, int y)
{
	if (!check_component(map, x, y))
		return ;
	map->grid[map->player.y][map->player.x] = EMPTY;
	if (!map->exited)
		map->grid[y][x] = PLAYER;
	map->player.x = x;
	map->player.y = y;
	ft_printf("Walk count: %d\n", ++map->walk_count);
}

void	direction(int keycode, t_map *map)
{
	if (keycode == W || keycode == UP)
	{
		map->player.direction = UP;
		check_coord(map, map->player.x, map->player.y - 1);
	}
	else if (keycode == S || keycode == DOWN)
	{
		map->player.direction = DOWN;
		check_coord(map, map->player.x, map->player.y + 1);	
	}
	else if (keycode == A || keycode == LEFT)
	{
		map->player.direction = LEFT;
		check_coord(map, map->player.x - 1, map->player.y);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		map->player.direction = RIGHT;
		check_coord(map, map->player.x + 1, map->player.y);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		ft_printf("Window closing\n");
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_error_exit(map, 0);
	}
	if (!map->exited)
	{
		direction(keycode, map);
		if (map->exited)
			ft_printf("You finished the game!\n");
	}
	return (0);
}