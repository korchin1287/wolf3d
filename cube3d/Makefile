# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nofloren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 19:05:52 by nofloren          #+#    #+#              #
#    Updated: 2020/07/25 15:05:36 by nofloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = srcs/main.c

OBJ = ${SRC:.c=.o}

INCLUDES = minilibx

all: $(NAME)

$(NAME): ${OBJ}
	@gcc -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ${OBJ}

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: re, clean, fclean, all, bonus
