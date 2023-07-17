# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 15:22:50 by zhlim             #+#    #+#              #
#    Updated: 2023/07/14 12:42:40 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= so_long.c validate_map.c initialize_mlx.c error_handling.c save_as_grid.c lines_check.c path_check.c
SRCGNL			= $(addprefix libft/get_next_line/, $(addsuffix .c, get_next_line get_next_line_utils))

OBJ				= $(patsubst %.c,%.o,$(SRC))
OBJGNL			= $(patsubst %.c,%.o,$(SRCGNL))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -fsanitize=address

RM				= rm -f

INCLUDES		= -I/usr/include -Imlx_linux -Ift_printf/include/ -Ilibft/get_next_line/ -Ilibft/ -I.
# -Imlx -Ift_printf/include/ -Ilibft/get_next_line/ -Ilibft/ -I.

NAME			= so_long

LIBFT			= libft/libft.a
LIBFTFLAGS		= -Llibft/ -lft

LIBPRINTF		= libft/ft_printf/libftprintf.a
LIBPRINTFFLAGS	= -Llibft/ft_printf -lftprintf 

LIBMLXFLAGS		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o:			%.c
				$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@
# $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:			$(NAME)

$(NAME): 		$(OBJ) $(OBJGNL) 
				$(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) $(LIBMLXFLAGS) -o $@
# $(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) $(LIBMLXFLAGS) -o $@

$(OBJ):			$(LIBPRINTF) $(LIBFT)

$(LIBFT):		
				make -C libft/

$(LIBPRINTF):	
				make -C libft/ft_printf/

clean:		
				$(RM) $(OBJ) $(OBJGNL)
				make clean -C libft/
				make clean -C libft/ft_printf/
				
fclean:			clean
				$(RM) $(NAME)
				make fclean -C libft/
				make fclean -C libft/ft_printf/

re:				fclean all

.PHONY:			all clean fclean