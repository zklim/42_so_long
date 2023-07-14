/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:23:18 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/14 12:59:29 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *temp_map, int col, int row)
{
	char	*current_coord;

	current_coord = &temp_map->grid[row][col];
	if (row >= temp_map->rows || row < 0 || col >= temp_map->columns || col < 0
		|| *current_coord == WALL)
		return ;
	if (*current_coord == EXIT)
	{
		temp_map->exit_found = 1;
		return ;
	}
	if (*current_coord == COLLECTIBLE)
	{
		temp_map->collected++;
		*current_coord = EMPTY;
	}
	*current_coord = WALL;
	flood_fill(temp_map, col, row - 1);
	flood_fill(temp_map, col, row + 1);
	flood_fill(temp_map, col - 1, row);
	flood_fill(temp_map, col + 1, row);
}

void	valid_check(t_map *map, t_map *temp_map)
{
	if (temp_map->collected != temp_map->collectible_count)
		free_error_exit(map, 8);
	if (temp_map->exit_found != 1)
		free_error_exit(map, 9);
}

void	path_check(t_map *map)
{
	t_map temp_map;

	temp_map = *map;
	flood_fill(&temp_map, map->player_x, map->player_y);
	valid_check(map, &temp_map);
}