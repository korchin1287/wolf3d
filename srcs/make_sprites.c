#include "cube3d.h"

void	paint_sprite_help(t_data *data, int *i, int *j)
{
	data->sprite[data->i]->ptr->y = *j / data->delta_line_h;
	data->pos = (data->sprite[data->i]->ptr->y * data->sprite[data->i]->ptr->l_l
		+ data->sprite[data->i]->ptr->x * (data->sprite[data->i]->ptr->b_p_p
		/ 8));
	data->pos2 = data->sprite[data->i]->ptr->addr + data->pos;
	data->color = *(unsigned int*)data->pos2;
	if (!(get_t(data->color)) && data->color > 0)
		my_mlx_pixel_put(data, data->w_offset + *i,
			data->h_offset + *j, data->color);
	(*j)++;
}

void	paint_sprite(t_data *data)
{
	int			i;
	int			j;

	i = -1;
	data->delta_line_h = data->sprite_screen_size /
		(double)data->sprite[data->i]->ptr->height;
	while (++i < data->sprite_screen_size)
	{
		if (!(data->w_offset + i < 0 || data->w_offset + i >= data->width ||
			(data->buffer[data->w_offset + i] <
			data->sprite[data->i]->sprite_dist)))
		{
			data->sprite[data->i]->ptr->x = i / data->delta_line_h;
			j = 0;
			while (j < data->sprite_screen_size)
			{
				if (data->h_offset + j < 0 || data->h_offset + j >=
					data->height)
					j++;
				else
					paint_sprite_help(data, &i, &j);
			}
		}
	}
}

void	make_sprites(t_data *data)
{
	data->sprite_dir = atan2(data->sprite[data->i]->y - data->player_y,
		data->sprite[data->i]->x - data->player_x);
	while (data->sprite_dir - data->player_a > M_PI)
		data->sprite_dir -= 2 * M_PI;
	while (data->sprite_dir - data->player_a < -M_PI)
		data->sprite_dir += 2 * M_PI;
	data->sprite_screen_size = data->height /
		data->sprite[data->i]->sprite_dist;
	data->w_offset = (data->sprite_dir - data->player_a) * (data->width) /
		data->fov + (data->width) / 2 - data->sprite_screen_size / 2;
	data->h_offset = data->height / 2 - data->sprite_screen_size / 2;
}

void	add_and_sort_sprite(t_data *data)
{
	int			j;
	t_sprite	*tmp;

	data->i = -1;
	while (++(data->i) < data->buf_sprite)
		data->sprite[data->i]->sprite_dist = sqrt((data->player_x -
			data->sprite[data->i]->x) * (data->player_x -
			data->sprite[data->i]->x) + (data->player_y -
			data->sprite[data->i]->y) * (data->player_y -
			data->sprite[data->i]->y));
	data->i = -1;
	while (++data->i < data->buf_sprite - 1)
	{
		j = -1;
		while (++j < (data->buf_sprite - data->i - 1))
		{
			if (data->sprite[j]->sprite_dist <
				data->sprite[j + 1]->sprite_dist)
			{
				tmp = data->sprite[j];
				data->sprite[j] = data->sprite[j + 1];
				data->sprite[j + 1] = tmp;
			}
		}
	}
}

void	ft_make_sprites(t_data *data)
{
	add_and_sort_sprite(data);
	data->i = 0;
	while ((data->i) < data->buf_sprite)
	{
		make_sprites(data);
		paint_sprite(data);
		(data->i)++;
	}
}
