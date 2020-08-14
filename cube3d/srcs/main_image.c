#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			print_sqr(t_data *img, int color, int x, int y)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 30;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void			ft_move1(int key,t_data *img, int x, int y, int color)
{
	print_sqr(img, 0x00000000, img->x, img->y);
//	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	if (key == 123 && (img->x - 5) >= 0)
		img->x -= 5;
	if (key == 124 && (img->x + 5) <= 610)
		img->x += 5;
	if (key == 125 && (img->y + 5) <= 450)
		img->y += 5;
	if (key == 126 && (img->y - 5) >= 0)
		img->y -= 5;

	print_sqr(img, color, img->x, img->y);
	//mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	
}

int				ft_close(int key, t_data *img)
{
	static int color;

	if (color == 0)
		color = 0x00FF0000;
	printf("%d\n", key);
	if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		ft_move1(key, img, img->x, img->y, color);
	}
	if (key == 49)
	{
		print_sqr(img, color, img->x, img->y);
		color += 10000;
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	if (key == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	return (0);
}

int				render_next_frame(t_data *img);

int				main(void)
{
	t_data img;
	char *path = "./sprite.xpm";
	int	img_width;
	int	img_height;

	img.x = 0;
	img.y = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 640, 480, "hello");
//	img.img = mlx_xpm_file_to_image(img.mlx, path, &img_width, &img_height);
	img.img = mlx_new_image(img.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	print_sqr(img);
	mlx_hook(img.win, 2, 1L<<1, ft_close, &img);
	mlx_hook(img.win, 2, 1L<<1, ft_close, &img);
//	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
}
