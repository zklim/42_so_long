/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:22:53 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/22 13:45:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->mlx = NULL;
	map->mlx_win = NULL;
	map->grid = NULL;
	map->start_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	map->rows = 0;
	map->columns = 0;
	map->exit_opened = 0;
	map->exited = 0;
	map->collected = 0;
	map->walk_count = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		print_error_exit("No map provided");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		print_error_exit("Not .ber file");
	initialize_map(&map);
	validate_map(av[1], &map);
	initialize_mlx(&map);
	return (0);
}
