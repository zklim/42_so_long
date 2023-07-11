/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:44:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/11 16:58:03 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_exit(unsigned int errno)
{
	if (errno == 1)
		perror("No map provided");
	else if (errno == 2)
		perror("Map is not rectangular");
	else if (errno == 3)
		perror("Walls are not closed");
	else if (errno == 4)
		perror("Unknown character include");
	else if (errno == 5)
		perror("Start and exit numbers is not 1");
	else if (errno == 6)
		perror("Less than 1 collectibles");
	exit(1);
}
