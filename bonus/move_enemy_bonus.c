/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:50:59 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/23 18:41:01 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	random_dir(t_map *map, int max, int seed)
{
	int	seed2;
	int	rand;

	seed2 = seed + map->collected * map->walk_count * map->player.x;
	rand = seed2 % max + 1;
	ft_printf("%d, %d\n", seed2, rand);
	return (rand);
}

static int	check_direction(t_map *map, int row, int col)
{
	if (map->grid[row][col] != PLAYER && map->grid[row][col] != EMPTY)
		return (0);
	else if (map->grid[row][col] == PLAYER)
		map->player_dead = 1;
	return (1);
}

static void	rand_movement(t_map *map, int row, int col, int seed)
{
	int	dir;

	if (check_direction(map, row - 1, col))
	{
		dir = random_dir(map, 4, seed);
		if (dir == 1)
		{
			if (!check_direction(map, row - 1, col))
				return ;
			map->grid[row - 1][col] = ENEMY_UP;
			map->grid[row][col] = EMPTY;
		}
		if (dir == 2)
		{
			if (!check_direction(map, row + 1, col))
				return ;
			map->grid[row + 1][col] = ENEMY_DOWN;
			map->grid[row][col] = EMPTY;
		}
		if (dir == 3)
		{
			if (!check_direction(map, row, col - 1))
				return ;
			map->grid[row][col - 1] = ENEMY_LEFT;
			map->grid[row][col] = EMPTY;
		}
		if (dir == 4)
		{
			if (!check_direction(map, row, col + 1))
				return ;
			map->grid[row][col + 1] = ENEMY_RIGHT;
			map->grid[row][col] = EMPTY;
		}
	}
}

void	move_enemy(t_map *map, int *e_frame)
{
	int         row;
	int         col;
	static int  seed;

	row = 0;
	if (*e_frame == E_FRAME)
	{
		while (row < map->rows)
		{
			col = 0;
			while (col < map->columns)
			{
				if (map->grid[row][col] == ENEMY_UP
					|| map->grid[row][col] == ENEMY_DOWN
					|| map->grid[row][col] == ENEMY_LEFT
					|| map->grid[row][col] == ENEMY_RIGHT)
					rand_movement(map, row, col, ++seed);
				col++;
			}
			row++;
		}
		*e_frame = 0;
	}
	if (seed == 2147483647)
		seed = 0;
}
