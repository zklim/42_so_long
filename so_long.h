/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:05:42 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/14 12:42:34 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/ft_printf/include/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define ESC 65307

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_map
{
	char	**grid;
	int		start_count;
	int		exit_count;
	int		collectible_count;
	int		rows;
	int		columns;
	int		player_x;
	int		player_y;
	int		exit_found;
	int		collected;
}			t_map;

void		print_error_exit(unsigned int errno);
void		validate_map(char *av, t_map *map);
void		save_as_grid(int fd, t_map *map);
void		initialize_mlx(void);
void		free_error_exit(t_map *map, unsigned int errno);
void		lines_check(t_map *map);
void		path_check(t_map *map);

#endif