/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:26:46 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/19 15:35:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_map *map)
{
	ft_printf("rendered %d\n", map->exit_count);
	return 0;
}

void    key_check(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		ft_printf("Window closing\n");
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_error_exit(map, 0);
	}
    if (keycode == W || keycode == UP)
    {
        map->exit_count++;
        mlx_loop_hook(map->mlx, render_next_frame, &map);
    }
}

int	key_hook(int keycode, t_map *map)
{
	ft_printf("%d\n", keycode);
    key_check(keycode, map);
	return 0;
}