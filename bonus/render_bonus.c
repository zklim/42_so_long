/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:47:13 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/22 11:31:23 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int render(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.background.img, map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.character.img[map->frame % 4], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
	mlx_do_sync(map->mlx);
	return 0;
}