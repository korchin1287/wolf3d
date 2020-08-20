# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nofloren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 19:05:52 by nofloren          #+#    #+#              #
#    Updated: 2020/08/20 20:30:54 by nofloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = srcs/cube3d3.c srcs/parcer.c

OBJ = ${SRC:.c=.o}

INCLUDES1 = libft

INCLUDES2 = /usr/local/include

all: $(NAME)

$(NAME): 
	@gcc -Wall -Wextra -Werror -g $(SRC) -I$(INCLUDES1) -L$(INCLUDES1) -lft -I $(INCLUDES2) -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re, clean, fclean, all, bonus
