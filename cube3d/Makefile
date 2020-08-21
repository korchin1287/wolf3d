# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nofloren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 19:05:52 by nofloren          #+#    #+#              #
#    Updated: 2020/08/21 18:53:22 by nofloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = srcs/main.c srcs/parcer1.c srcs/parcer2.c \
		srcs/parcer3.c srcs/parcer4.c srcs/map1.c srcs/map2.c srcs/map3.c \
		srcs/init.c srcs/ray_casting.c srcs/ray_casting2.c srcs/ray_casting3.c \
		srcs/ray_casting4.c srcs/make_sprites.c srcs/move.c srcs/move2.c

INCLUDES1 = libft

INCLUDES2 = /usr/local/include

all: $(NAME)

$(NAME): 
	@gcc -Wall -Wextra -Werror -g $(SRC) -I$(INCLUDES1) -L$(INCLUDES1) -lft \
	-I $(INCLUDES2) -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit \
	-o $(NAME)

bonus:

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re, clean, fclean, all, bonus
