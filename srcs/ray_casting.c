#include "cube3d.h"

void	casting2(t_data *data)
{
	data->buffer[data->x] = data->c;
	data->hitx = data->cx - floor(data->cx + 0.5);
	data->hity = data->cy - floor(data->cy + 0.5);
	if ((data->world_map[(int)(data->cy - 0.005 * sin(data->angle))]
		[(int)data->cx]) != '1')
		data->side = 1;
	else
		data->side = 0;
}

void	casting1(t_data *data)
{
	data->cx = data->player_x;
	data->cy = data->player_y;
	data->angle = data->player_a - data->fov / 2 + (data->fov * data->x) /
		(double)(data->width);
	data->c = 0;
	while (1)
	{
		data->cx = data->player_x + data->c * cos(data->angle);
		data->cy = data->player_y + data->c * sin(data->angle);
		data->c += 0.01;
		if ((data->world_map[(int)data->cy][(int)data->cx]) == '1')
		{
			while (data->world_map[(int)data->cy][(int)data->cx] == '1')
			{
				data->c -= 0.001;
				data->cx = data->player_x + data->c * cos(data->angle);
				data->cy = data->player_y + data->c * sin(data->angle);
			}
			data->c += 0.001;
			data->cx = data->player_x + data->c * cos(data->angle);
			data->cy = data->player_y + data->c * sin(data->angle);
			break ;
		}
	}
}

void	ray_casting(t_data *data)
{
	data->x = 0;
	while (data->x < data->width)
	{
		casting1(data);
		casting2(data);
		ft_side_wall(data);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_make_sprites(data);
}

void	ft_count_coordinate_sprites(t_data *data)
{
	int x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	while (data->world_map[i] || (x < data->buf_sprite))
	{
		j = 0;
		while (data->world_map[i][j] != '\0')
		{
			if (data->world_map[i][j] == '2')
			{
				data->sprite[x]->x = j + 0.5;
				data->sprite[x]->y = i + 0.5;
				x++;
			}
			j++;
		}
		i++;
	}
}

void	ft_start(t_data *data, t_parser *pars, int argc, char **argv)
{
	data->buffer = malloc(sizeof(double) * data->width);
	data->buf_sprite = pars->buf_sprite;
	ft_count_coordinate_sprites(data);
	ray_casting(data);
	if (argc == 3 && !(ft_strncmp("--save", argv[2], 7)))
		create_bmp(data);
	mlx_hook(data->win, 2, 0, &ft_key, data);
	mlx_hook(data->win, 17, 0, &ft_close, data);
	mlx_loop(data->mlx);
}
