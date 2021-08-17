# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 13:48:05 by lhorefto          #+#    #+#              #
#    Updated: 2021/08/12 14:59:55 by lhorefto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

SRCS =			main.c read.c free.c init.c errors.c
				
OBJS			= $(SRCS:.c=.o)

MLX_DIR			= mlx


CC				= gcc
RM				= rm -f
HEADER			= solong.h
CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -L$(MLX_DIR) -lft

$(NAME):		$(OBJS)
				$(CC) -o so_long $(CFLAGS) $(OBJS) libft/libft.a $(MLX_DIR)/libmlx_Linux.a -L/usr/include/X11/extensions -lX11 -lXext

all:			mlx_all $(NAME)

clean:			
				rm -f $(OBJS)
				make -C $(MLX_DIR) clean
				

fclean:			clean
				rm -f $(NAME)
				make -C $(MLX_DIR) clean

re:				fclean all

mlx_all:		
				make -C $(MLX_DIR) all