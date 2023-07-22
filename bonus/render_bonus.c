/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:47:13 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/22 16:35:06 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	direction(t_map *map)
{
	if (map->player.direction == UP)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.background.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.back.img[map->frame], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
	}
	else if (map->player.direction == DOWN)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.background.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.front.img[map->frame], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
	}
	else if (map->player.direction == LEFT)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.background.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.left.img[map->frame], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
	}
	else if (map->player.direction == RIGHT)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.background.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.right.img[map->frame], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
	}
}

int render(t_map *map)
{
	static int	frame;

	if (!map->exited)
	{
		if (frame == 2000)
		{
			if (map->frame == 4)
				map->frame = 0;
			direction(map);
			map->frame++;
			frame = 0;
		}
	}
	frame++;
	return 0;
}