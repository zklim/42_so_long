/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:12:35 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/11 17:24:21 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_1(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '1')
			print_error_exit(3);
		i++;
	}
	return (i);
}

int	check_mid(char *line, int *start, int *exit_c, int *collect)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		print_error_exit(3);
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1')
		{
			if (line[i] == 'P')
				*start = *start + 1;
			else if (line[i] == 'E')
				*exit_c = *exit_c + 1;
			else if (line[i] == 'C')
				*collect = *collect + 1;
			else
				print_error_exit(4);
		}
	}
	if (line[i - 1] != '1')
		print_error_exit(3);
	return (i);
}


void	lines_check(int fd, int *start, int *exit_c, int *collect)
{
	char	*line;
	int		line_length;

	line = get_next_line(fd);
	line_length = check_1(line);
	while (line)
	{
		line = get_next_line(fd);
		if (*line == '\n')
			break ;
		else if (check_mid(line, start, exit_c, collect) != line_length)
			print_error_exit(2);
	}
}

void	components_check(int *start, int *exit_c, int *collect)
{
	if (*start != 1 || *exit_c != 1)
		print_error_exit(5);
	if (*collect < 1)
		print_error_exit(6);
}

void	validate_map(int ac, char *map)
{
	int fd;
	int start_count;
	int exit_count;
	int collectible_count;

	start_count = 0;
	exit_count = 0;
	collectible_count = 0;
	if (ac != 2)
		print_error_exit(1);
	fd = open(map, O_RDONLY);
	lines_check(fd, &start_count, &exit_count, &collectible_count);
	components_check(&start_count, &exit_count, &collectible_count);
    path_check(fd, &start_count, &exit_count, &collectible_count);
	close(fd);
}
