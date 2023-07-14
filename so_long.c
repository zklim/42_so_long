/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:22:53 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/14 12:23:04 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->grid = NULL;
	map->start_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	map->rows = 0;
	map->columns = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->exit_found = 0;
	map->collected = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		print_error_exit(1);
	initialize_map(&map);
	validate_map(av[1], &map);
	initialize_mlx();
	return (0);
}
