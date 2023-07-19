/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:02 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/19 18:07:08 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	destroy_win(t_map *map)
{
	(void)*map;
	ft_printf("Window closing\n");
	exit(0);
	return 0;
}

void	initialize_mlx(t_map *map)
{
	t_data	img;
	char	*tileset_path = "./textures/Tilesets/Grass.xpm";
	int		img_width;
	int		img_height;

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, 1000, 1000, "so_long");
	img.img = mlx_xpm_file_to_image(map->mlx, tileset_path, &img_width, &img_height);
	ft_printf("%p, %d, %d", img.img, img_width, img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 16, 16, 0x00000000);
	mlx_key_hook(map->mlx_win, key_hook, &map->mlx);
	mlx_hook(map->mlx_win, 17, 0, destroy_win, &map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, img.img, 0, 0);
	mlx_loop(map->mlx);
}