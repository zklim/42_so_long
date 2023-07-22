# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 15:22:50 by zhlim             #+#    #+#              #
#    Updated: 2023/07/22 16:30:29 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= so_long.c validate_map.c initialize_mlx.c error_handling.c save_as_grid.c lines_check.c path_check.c key_hook.c
SRCGNL			= $(addprefix libft/get_next_line/, $(addsuffix .c, get_next_line get_next_line_utils))
SRCB			= $(addprefix bonus/, $(addsuffix _bonus.c, so_long validate_map initialize_mlx error_handling save_as_grid lines_check path_check key_hook render load_sprite load_images))

OBJ				= $(patsubst %.c,%.o,$(SRC))
OBJGNL			= $(patsubst %.c,%.o,$(SRCGNL))
OBJB			= $(patsubst %.c,%.o,$(SRCB))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -fsanitize=address

RM				= rm -f

INCLUDES		= -Imlx -Ift_printf/include/ -Ilibft/get_next_line/ -Ilibft/ -I.

NAME			= so_long
NAMEB			= so_long_bonus

LIBFT			= libft/libft.a
LIBFTFLAGS		= -Llibft/ -lft

LIBPRINTF		= libft/ft_printf/libftprintf.a
LIBPRINTFFLAGS	= -Llibft/ft_printf -lftprintf 

LIBMLXFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o:			%.c
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:			$(NAME)

bonus:			$(NAMEB)

$(NAME): 		$(OBJ) $(OBJGNL) 
				$(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) $(LIBMLXFLAGS) -o $@

$(NAMEB):		$(OBJB) $(OBJGNL)
				$(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) $(LIBMLXFLAGS) -o $@

$(OBJ):			$(LIBPRINTF) $(LIBFT)
$(OBJB):		$(LIBPRINTF) $(LIBFT)

$(LIBFT):		
				make -C libft/

$(LIBPRINTF):	
				make -C libft/ft_printf/

clean:		
				$(RM) $(OBJ) $(OBJGNL) $(OBJB)
				make clean -C libft/
				make clean -C libft/ft_printf/
				
fclean:			clean
				$(RM) $(NAME) $(NAMEB)
				make fclean -C libft/
				make fclean -C libft/ft_printf/

re:				fclean all

rebonus:		fclean bonus

.PHONY:			all clean fclean rebonus