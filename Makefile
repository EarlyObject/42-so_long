# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 10:25:17 by asydykna          #+#    #+#              #
#    Updated: 2021/10/18 10:31:48 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft.a
LIBFT_PATH = libft
MLX_PATH = mlx
MLX = libmlx.a
MLX_LINK = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c clean_exit.c initialization.c key_management.c parse.c utils.c \
	error_mngmt.c parse_checks.c graphics.c map_mngmt.c player.c

OBJ = $(SRC:.c=.o)

CC = gcc -g -Imlx

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

VPATH = src include

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_PATH)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a $(LIBFT)
	$(CC) -g3 $(CFLAGS) $(OBJ) $(MLX_LINK) $(LIBFT) -o $(NAME)


all: $(NAME)

clean:
	$(RM) $(OBJ)
	#$(MAKE) clean -C $(MLX_PATH)
	#make clean -C $(LIBFT_PATH)

fclean: clean
	#$(RM) $(NAME) $(LIBFT) $(MLX)
	#make fclean -C $(LIBFT_PATH)

re: fclean all

norm:
	norminette ./src ./include $(LIBFT_PATH)

#.SILENT: $(OBJ)

.PHONY: all clean fclean re norm