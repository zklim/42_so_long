/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:29:31 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/23 12:48:35 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 10;
    load_sprite(map, &map->graphic.e_front, range, ENEMY_PATH);
	range.start = 11;
	range.end = 21;
    load_sprite(map, &map->graphic.e_back, range, ENEMY_PATH);
	range.start = 22;
	range.end = 32;
    load_sprite(map, &map->graphic.e_left, range, ENEMY_PATH);
	range.start = 33;
	range.end = 43;
    load_sprite(map, &map->graphic.e_right, range, ENEMY_PATH);
}

void	load_character(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 4;
    load_sprite(map, &map->graphic.front, range, FRONT_PATH);
    load_sprite(map, &map->graphic.back, range, BACK_PATH);
    load_sprite(map, &map->graphic.left, range, LEFT_PATH);
    load_sprite(map, &map->graphic.right, range, RIGHT_PATH);
}

void	load_images(t_map *map)
{
	map->graphic.background.img = mlx_xpm_file_to_image(map->mlx,
		BACKGROUND_PATH, &map->graphic.background.width, &map->graphic.background.height);
	map->graphic.wall.img = mlx_xpm_file_to_image(map->mlx, WALL_PATH,
		&map->graphic.wall.width, &map->graphic.wall.height);
	map->graphic.exit_closed.img = mlx_xpm_file_to_image(map->mlx,
		EXIT_CLOSED_PATH, &map->graphic.exit_closed.width, &map->graphic.exit_closed.height);
	map->graphic.exit_opened.img = mlx_xpm_file_to_image(map->mlx,
															EXIT_OPENED_PATH,
															&map->graphic.exit_opened.width,
															&map->graphic.exit_opened.height);
	map->graphic.collectibles.img = mlx_xpm_file_to_image(map->mlx,
															COLLECTIBLES_PATH,
															&map->graphic.collectibles.width,
															&map->graphic.collectibles.height);
	load_character(map);
	load_enemy(map);
}

void	images_to_window(t_map *map, int col, int row)
{
	if (map->grid[row][col] == WALL)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.wall.img, col * TILESIZE_X, row * TILESIZE_Y);
	else if (map->grid[row][col] == EXIT)
	{
		if (map->exit_opened && !map->exited)
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.exit_opened.img, col * TILESIZE_X, row
				* TILESIZE_Y);
		else
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.exit_closed.img, col * TILESIZE_X, row
				* TILESIZE_Y);	
	}
	else if (map->grid[row][col] == COLLECTIBLE)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.collectibles.img, col * TILESIZE_X, row
				* TILESIZE_Y);
	else if (map->grid[row][col] == ENEMY)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.e_front.img[map->frame], col * TILESIZE_X, row * TILESIZE_X);
}

void	put_images(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.background.img, col * TILESIZE_X, row
				* TILESIZE_Y);
			images_to_window(map, col, row);
			col++;
		}
		row++;
	}
}