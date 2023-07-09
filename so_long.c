/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:22:53 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/09 18:18:42 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char** av)
{
    void    *mlx;
    void    *mlx_win;
    char    *line;
    t_data  img;
    int     fd;
    int     i = 5;
    int     j = 5;

    if (ac < 2)
    {
        perror("No map provided");
        return 1;
    }
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    ft_printf(line);
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello World");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    while (i < 10)
    {
        my_mlx_pixel_put(&img, i, j, 0x00FF0000);
        while(j < 10)
        {
            my_mlx_pixel_put(&img, i, j, 0x00FF0000);
            j++;
        }
        j = 5;
        i++;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);

    close(fd);
    return 0;
}