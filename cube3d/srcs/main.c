#include <mlx.h>
#include <stdio.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	paint_square(t_data img)
{
	int	i;
	int j;
	int n;

	n = 100;
	i = 0;
	j = 0;
	while (j < n || i < n)
	{
		my_mlx_pixel_put(&img, 50 + i, (50 + j), 0x00ff0000);
		my_mlx_pixel_put(&img, 50 + j, 50 + i, 0x00ff0000);
		if (j < n)
			j++;
		else
			i++;
	}
}

void	paint_circle(t_data img)
{
	int	x;
	int y;
	int delta;
	int error;
	int radius;

	radius = 30;
	x = 0;
	y = radius;
	delta = 1 - 2 * radius;
	error = 0;
	while (y >= 0)
	{
		my_mlx_pixel_put(&img, 50 + x, 50 + y, 0x00ff0000);
		my_mlx_pixel_put(&img, 50 + x, 50 - y, 0x00ff0000);
		my_mlx_pixel_put(&img, 50 - x, 50 + y, 0x00ff0000);
		my_mlx_pixel_put(&img, 50 - x, 50 - y, 0x00ff0000);
		error = 2 * (delta + y) - 1;
		if (delta < 0 && error <= 0)
		{
			x++;
			delta += 2 * x + 1;
		}
		else
		{
			error = 2 * (delta - x) - 1;
			if (delta > 0 && error > 0)
			{
				y--;
				delta += 1- 2 * y;
			}
			else
			{
				x++;
				delta += 2 * (x - y);
				y--;
			}
		}
	}
}

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

int		get_r(int rgb)
{
	return (rgb & (0xFF << 16));
}

int		get_g(int rgb)
{
	return (rgb & (0xFF << 8));
}

int		get_b(int rgb)
{
	return (rgb & (0xFF));
}

void	print_square2(t_data img)
{
	int	i;
	int	j;
	int size;
	int color;
	int x = 0;
	int r = 255;
	int g = 0;
	int b = 0;


	i = 0;
	size = 400;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (x >=0 && x <= 32000 && ((x % 125) == 0) && g < 255)
				g++;
			if (x > 32000 && x <= 64000 && ((x % 125) == 0) && r > 0)
				r--;
			if (x > 64000 && x <= 96000 && ((x % 125) == 0) && b < 255)
				b++;
			if (x > 96000 && x <= 128000 && ((x % 125) == 0) && g > 0)
				g--;
			if (x > 128000 && x <= 160000 && ((x % 125) == 0) && r < 255)
				r++;
			color = create_rgb(r, g, b);
			x++;
			my_mlx_pixel_put(&img, 10+i, 10+j, color);
			j++;
		}
		i++;
	}
//	printf("%d\n%d\n%d\n", get_r(160000), get_g(160000), get_b(160000));
//	printf("%d\n", create_rgb(255,0,0));
}

void	paint_trangle(t_data img)
{
	int i;
	int j;
	int size;

	i = 1;
	j = 1;
	size = 100;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size + i)
		{
			if (j <= (size - i + 1))
			{
				my_mlx_pixel_put(&img, 150+j, 150+i, 0x00ff0000);
			}
			j++;
		}
		i++;
	}
}

int	render_next_fr(t_data img)
{
	int	i;
	int	j;
	int size;

	i = 0;
	size = 400;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&img, 10+i, 10+j, 0x00ff0000);
			j++;
		}
		i++;
	}
	return(0);
}

int	ft_privet(int key, t_data img)
{
	int i;
	int j;
	int size;

	i = 0;
	size = 400;

	if (key == 0)
	{
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				my_mlx_pixel_put(&img, 10+i, 10+j, 0x00ff0000);
				j++;
			}
			i++;
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
	}
	return (0);
}

int				main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	my_mlx_pixel_put(&img, 50, 50, 0x00ff0000);
//	paint_square(img);
//	paint_circle(img);
	print_square2(img);
	mlx_key_hook(mlx_win, ft_privet, &img);
//	paint_trangle(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
	mlx_loop(mlx);
}
