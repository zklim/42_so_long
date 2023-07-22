/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:29:31 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/22 16:47:45 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 9;
    load_sprite(map, &map->graphic.e_front, range, ENEMY_PATH);
	range.start = 11;
	range.end = 20;
    load_sprite(map, &map->graphic.e_back, range, ENEMY_PATH);
	range.start = 22;
	range.end = 31;
    load_sprite(map, &map->graphic.e_left, range, ENEMY_PATH);
	range.start = 33;
	range.end = 42;
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

void	put_images(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->graphic.background.img, j * TILESIZE_X, i
					* TILESIZE_Y);
			if (map->grid[i][j] == WALL)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						map->graphic.wall.img, j * TILESIZE_X, i * TILESIZE_Y);
			if (map->grid[i][j] == PLAYER)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						map->graphic.front.img[0], j * TILESIZE_X, i
						* TILESIZE_Y);
			if (map->grid[i][j] == EXIT)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						map->graphic.exit_closed.img, j * TILESIZE_X, i
						* TILESIZE_Y);
			if (map->grid[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						map->graphic.collectibles.img, j * TILESIZE_X, i
						* TILESIZE_Y);
			j++;
		}
		i++;
	}
}