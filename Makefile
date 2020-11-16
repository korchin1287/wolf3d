NAME = wolf3D

SRC = srcs/main.c srcs/parcer1.c srcs/parcer2.c \
		srcs/parcer3.c srcs/parcer4.c srcs/map1.c srcs/map2.c srcs/map3.c \
		srcs/init.c srcs/ray_casting.c srcs/ray_casting2.c \
		srcs/ray_casting3.c srcs/ray_casting4.c srcs/make_sprites.c \
	   	srcs/move.c srcs/move2.c srcs/bmp.c

INCLUDES = libft

BUILD = libft/libft.a mlx/libmlx.dylib

all: $(NAME)

$(NAME): $(SRC) $(BUILD)
	gcc -Wall -Wextra -Werror -g $(SRC) -L$(INCLUDES) -lft -L. -lmlx -framework \
	OpenGL -framework AppKit -o $(NAME)

$(BUILD):
	$(MAKE) -C libft
	$(MAKE) -C mlx
	cp ./mlx/libmlx.dylib .

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f screenshot.bmp
	rm -f libmlx.dylib

re: fclean all

.PHONY: re, clean, fclean, all
