/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:34:34 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/22 16:40:18 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*path_string(char *prefix, char *suffix, int i)
{
	char	*num;
	char	*str;
	char	*res;

	num = ft_itoa(i);
	str = ft_strjoin(prefix, num);
	res = ft_strjoin(str, suffix);
	free(str);
	return res;
}

void	load_sprite(t_map *map, t_sprite *sprite, t_range range, char *prefix)
{
	int		i;
	char	*path;

	i = range.start;
	while (i < range.end)
	{
		path = path_string(prefix, SUFFIX, i);
		sprite->img[i] = mlx_xpm_file_to_image(map->mlx,
			path, &sprite->width, &sprite->height);	
		free(path);
		i++;
	}
}