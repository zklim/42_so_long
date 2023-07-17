/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:45 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/14 12:26:34 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_sl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	check_first_last_rows(t_map *map)
{
	int		i;
	int		j;
	char	*lines[2];

	i = 0;
	j = 0;
	lines[0] = map->grid[0];
	lines[1] = map->grid[map->rows - 1];
	while (i < 2)
	{
		while (lines[i][j] && lines[i][j] != '\n')
		{
			if (lines[i][j] != '1')
				free_error_exit(map, 3);
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_coordinate(t_map *map, char c, int col, int row)
{
	if (c != EMPTY && c != WALL)
	{
		if (c == PLAYER)
		{
			map->start_count++;
			map->player_x = col;
			map->player_y = row;
		}
		else if (c == EXIT)
			map->exit_count++;
		else if (c == COLLECTIBLE)
			map->collectible_count++;
		else
			free_error_exit(map, 4);
	}
}

int	check_line(t_map *map, int row)
{
	int		i;
	char	*line;

	i = 0;
	line = map->grid[row];
	if (line[i] != '1')
		free_error_exit(map, 3);
	while (line[++i] && line[i] != '\n')
		check_coordinate(map, line[i], i, row);
	if (line[i - 1] != '1')
		free_error_exit(map, 3);
	return (i);
}

void	lines_check(t_map *map)
{
	int	line_length;
	int	i;

	i = 0;
	line_length = 0;
	if (map->grid != NULL)
	{
		line_length = ft_strlen_sl(map->grid[0]);
		map->columns = line_length;
		check_first_last_rows(map);
	}
	while (i < map->rows)
	{
		if (*(map->grid[i]) == '\n')
			break ;
		else if (check_line(map, i) != line_length)
			free_error_exit(map, 2);
		i++;
	}
}
