/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:02 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/20 16:51:57 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_graphic *graphic, t_map *map)
{
	graphic->background.img = mlx_xpm_file_to_image(map->mlx, BACKGROUND_PATH,
			&graphic->background.width, &graphic->background.height);
	graphic->wall.img = mlx_xpm_file_to_image(map->mlx, WALL_PATH,
			&graphic->wall.width, &graphic->wall.height);
	graphic->exit_closed.img = mlx_xpm_file_to_image(map->mlx, EXIT_CLOSED_PATH,
			&graphic->exit_closed.width, &graphic->exit_closed.height);
	graphic->exit_opened.img = mlx_xpm_file_to_image(map->mlx, EXIT_OPENED_PATH,
			&graphic->exit_opened.width, &graphic->exit_opened.height);
	graphic->collectibles.img = mlx_xpm_file_to_image(map->mlx,
			COLLECTIBLES_PATH, &graphic->collectibles.width,
			&graphic->collectibles.height);
	graphic->character.img = mlx_xpm_file_to_image(map->mlx, CHARACTER_PATH,
			&graphic->character.width, &graphic->character.height);
}

void	put_images(t_graphic *graphic, t_map *map)
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
					graphic->background.img, j * TILESIZE_X, i * TILESIZE_Y);
			if (map->grid[i][j] == WALL)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						graphic->wall.img, j * TILESIZE_X, i * TILESIZE_Y);
			if (map->grid[i][j] == PLAYER)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						graphic->character.img, j * TILESIZE_X, i * TILESIZE_Y);
			if (map->grid[i][j] == EXIT)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						graphic->exit_closed.img, j * TILESIZE_X, i
						* TILESIZE_Y);
			if (map->grid[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
						graphic->collectibles.img, j * TILESIZE_X, i
						* TILESIZE_Y);
			j++;
		}
		i++;
	}
}

int	destroy_win(t_map *map)
{
	(void)*map;
	ft_printf("Window closing\n");
	exit(0);
	return (0);
}

void	initialize_mlx(t_map *map)
{
	t_graphic graphic;

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->columns * TILESIZE_X, map->rows
			* TILESIZE_Y, "so_long");
	load_images(&graphic, map);
	put_images(&graphic, map);
	mlx_key_hook(map->mlx_win, key_hook, &map->mlx);
	mlx_hook(map->mlx_win, 17, 0, destroy_win, &map);
	// mlx_loop_hook(map->mlx, render, map);
	mlx_loop(map->mlx);
}