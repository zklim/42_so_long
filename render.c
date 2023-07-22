/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:47:13 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/21 18:08:06 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->player.sprite.img[i], map->player.x * TILESIZE_X, map->player.y * TILESIZE_Y);
		i++;
	}
	return 0;
}