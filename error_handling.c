/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:44:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/20 13:41:43 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(unsigned int errno)
{
	if (errno == 0);
	else if (errno == 1)
		perror("No map provided");
	else if (errno == 2)
		perror("Map is not rectangular");
	else if (errno == 3)
		perror("Walls are not closed");
	else if (errno == 4)
		perror("Unknown character include");
	else if (errno == 5)
		perror("Start or exit number is not 1");
	else if (errno == 6)
		perror("Less than 1 collectibles");
	else if (errno == 7)
		perror("No map found");
	else if (errno == 8)
		perror("Can't pick up all collectibles");
	else if (errno == 9)
		perror("Exit is unreachable");
	else if (errno == 10)
		perror("Not .ber file");
}

void	print_error_exit(unsigned int errno)
{
	print_error(errno);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	free_error_exit(t_map *map, unsigned int errno)
{
	print_error(errno);
	free_map(map);
	exit(0);
}
