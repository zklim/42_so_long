/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:02 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/11 16:58:14 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_win(int keycode, t_mlx *mlx)
{
	ft_printf("%d\n", keycode);
	if (keycode == ESC)
	{
		ft_printf("Window closed\n");
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		return 0;
	}
	return 1;
}

void	initialize_mlx(void)
{
	t_mlx	mlx;
	t_data	img;
	int i = 5;
	int j = 5;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1000, 1000, "Hello World");
	img.img = mlx_new_image(mlx.mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < 10)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		while (j < 10)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		j = 5;
		i++;
	}
	mlx_key_hook(mlx.mlx_win, close_win, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
}