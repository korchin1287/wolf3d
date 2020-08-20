/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:43:32 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:31:12 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

static void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->l_l + x * (data->b_p_p / 8));
	*(unsigned int*)dst = color;
}

void		paint_floor(t_data *data, int i)
{
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

void		paint_roof(t_data *data, int i)
{
	int	r;

	r = 0;
	while (r < i)
	{
		my_mlx_pixel_put(data, data->x, r, data->color_roof);
		r++;
	}
}

static void	ver_line_n(t_data *data)
{
	int color;
	int	i;

	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_n->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_n->y * data->tex_n->l_l + data->tex_n->x * (data->tex_n->b_p_p / 8));
			data->pos2 = data->tex_n->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

static void	ver_line_s(t_data *data)
{
	int	color;
	int	i;
	
	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_s->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_s->y * data->tex_s->l_l + data->tex_s->x * (data->tex_s->b_p_p / 8));
			data->pos2 = data->tex_s->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

static void	ver_line_e(t_data *data)
{
	int	color;
	int	i;
	
	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_e->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_e->y * data->tex_e->l_l + data->tex_e->x * (data->tex_e->b_p_p / 8));
			data->pos2 = data->tex_e->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

static void	ver_line_w(t_data *data)
{
	int	color;
	int	i;
	
	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_w->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_w->y * data->tex_w->l_l + data->tex_w->x * (data->tex_w->b_p_p / 8));
			data->pos2 = data->tex_w->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

void	casting1(t_data *data)
{
	data->cx = data->player_x;
	data->cy = data->player_y;
	data->angle = data->player_a - data->fov / 2 + (data->fov * data->x) / (double)(data->width);
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
				data->c -= 0.0005;
				data->cx = data->player_x + data->c * cos(data->angle);
				data->cy = data->player_y + data->c * sin(data->angle);
			}
			break ;
		}	
	}
}
void	casting2(t_data *data)
{
	data->buffer[data->x] = data->c;
	data->hitx = data->cx - floor(data->cx + 0.5);
	data->hity = data->cy - floor(data->cy + 0.5);
	if (fabs(data->hitx) > fabs(data->hity))
		data->side = 1;
	else
		data->side = 0;
}

void	casting2_n(t_data *data)
{
	if (fabs(data->hitx) > fabs(data->hity))
		data->tex_n->x = data->tex_n->width * data->hitx;
	else
		data->tex_n->x = data->tex_n->width * data->hity;
	if (data->tex_n->x < 0)
		data->tex_n->x += data->tex_n->width;
	data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
	data->draw_start = (int)((data->height - data->line_height) / 2);
	data->draw_end = (data->line_height + data->height) / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	data->delta_line_h = data->line_height / (double)data->tex_n->height;
	ver_line_n(data);
}

void	casting2_s(t_data *data)
{
	if (fabs(data->hitx) > fabs(data->hity))
		data->tex_s->x = data->tex_n->width * data->hitx;
	else
		data->tex_s->x = data->tex_s->width * data->hity;
	if (data->tex_s->x < 0)
		data->tex_s->x += data->tex_s->width;
	data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
	data->draw_start = (int)((data->height - data->line_height) / 2);
	data->draw_end = (data->line_height + data->height) / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	data->delta_line_h = data->line_height / (double)data->tex_s->height;
	ver_line_s(data);
}

void	casting2_e(t_data *data)
{
	if (fabs(data->hitx) > fabs(data->hity))
		data->tex_e->x = data->tex_e->width * data->hitx;
	else
		data->tex_e->x = data->tex_e->width * data->hity;
	if (data->tex_e->x < 0)
		data->tex_e->x += data->tex_e->width;
	data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
	data->draw_start = (int)((data->height - data->line_height) / 2);
	data->draw_end = (data->line_height + data->height) / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	data->delta_line_h = data->line_height / (double)data->tex_e->height;
	ver_line_e(data);
}

void	casting2_w(t_data *data)
{
	if (fabs(data->hitx) > fabs(data->hity))
		data->tex_w->x = data->tex_w->width * data->hitx;
	else
		data->tex_w->x = data->tex_w->width * data->hity;
	if (data->tex_w->x < 0)
		data->tex_w->x += data->tex_w->width;
	data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
	data->draw_start = (int)((data->height - data->line_height) / 2);
	data->draw_end = (data->line_height + data->height) / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	data->delta_line_h = data->line_height / (double)data->tex_w->height;
	ver_line_w(data);
}
static void		ft_side_wall(t_data *data)
{
	if (data->cy < data->player_y && (data->side == 1))
		casting2_n(data);
	else if (data->cy > data->player_y && (data->side == 1))
		casting2_s(data);
	else if (data->cx < data->player_x && (data->side == 0))
		casting2_e(data);
	else
		casting2_w(data);
}

void	paint_sprite_help(t_data *data, int *i, int *j)
{
	data->sprite[data->i]->ptr->y = *j / data->delta_line_h;
	data->pos = (data->sprite[data->i]->ptr->y * data->sprite[data->i]->ptr->l_l + data->sprite[data->i]->ptr->x * (data->sprite[data->i]->ptr->b_p_p / 8));
	data->pos2 = data->sprite[data->i]->ptr->addr + data->pos;
	data->color = *(unsigned int*)data->pos2;
	my_mlx_pixel_put(data, data->width + data->w_offset + *i, data->h_offset + *j, data->color);
	(*j)++;
}

void	paint_sprite(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->delta_line_h = data->sprite_screen_size / (double)data->sprite[data->i]->ptr->height;
	while (++i < data->sprite_screen_size)
	{
		if (!(data->w_offset + i < 0 || data->w_offset + i >= data->width || (data->buffer[data->w_offset + i] < data->sprite[data->i]->sprite_dist)))
		{
			data->sprite[data->i]->ptr->x = i / data->delta_line_h;
			j = 0;
			while (j < data->sprite_screen_size)
			{
				if (data->h_offset + j < 0 || data->h_offset + j >= data->height)
					j++;
				else
					paint_sprite_help(data, &i, &j);
			}
		}
	}
}

void	make_sprites(t_data *data)
{
	data->sprite_dir = atan2(data->sprite[data->i]->y - data->player_y, data->sprite[data->i]->x - data->player_x);
	while (data->sprite_dir - data->player_a > M_PI)
		data->sprite_dir -= 2 * M_PI;
	while (data->sprite_dir - data->player_a < -M_PI)
		data->sprite_dir += 2 * M_PI;
	data->sprite_screen_size = 2 * data->height / data->sprite[data->i]->sprite_dist;
	data->w_offset = (data->sprite_dir - data->player_a) * (data->width) / data->fov + (data->width) / 2 - data->sprite_screen_size / 2;
	data->h_offset = data->height / 2 - data->sprite_screen_size / 2;
}

void	add_and_sort_sprite(t_data *data)
{
	int	i;
	t_sprite *tmp;

	data->i = -1;
	while (++(data->i) < data->buf_sprite)
		data->sprite[data->i]->sprite_dist = sqrt((data->player_x - data->sprite[data->i]->x) * (data->player_x - data->sprite[data->i]->x) + (data->player_y - data->sprite[data->i]->y) * (data->player_y - data->sprite[data->i]->y));
	i = 0;
	while (i < data->buf_sprite - 1)
	{
		int j = 0;
		while (j < (data->buf_sprite - i - 1))
		{
			if (data->sprite[j]->sprite_dist < data->sprite[j+1]->sprite_dist)
			{
				tmp = data->sprite[j];
				data->sprite[j] = data->sprite[j + 1];
				data->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
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
	add_and_sort_sprite(data);
	data->i = 0;
	while ((data->i) < data->buf_sprite)
	{
		make_sprites(data);
		paint_sprite(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		(data->i)++;
	}
}

static int			ft_close(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
	return (0);
}

int		move_help(char c)
{
	if (c == '1' || c == '2')
	 return (0);
	return (1);
}

static void	ft_move_front(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = cos(data->player_a) * 0.2;
	go_y = sin(data->player_a) * 0.2;
	if (move_help(data->world_map[(int)(data->player_y + go_y)][(int)(data->player_x)]))
		data->player_y += go_y;
	if (move_help(data->world_map[(int)(data->player_y)][(int)(data->player_x + go_x)]))
		data->player_x += go_x;
} 

static void	ft_move_back(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = cos(data->player_a) * 0.2;
	go_y = sin(data->player_a) * 0.2;
	if (move_help(data->world_map[(int)(data->player_y - go_y)][(int)(data->player_x)]))
		data->player_y -= go_y;
	if (move_help(data->world_map[(int)(data->player_y)][(int)(data->player_x - go_x)]))
		data->player_x -= go_x;
}

static void	ft_move_left(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = 0.2 * cos(data->player_a - M_PI_2);
	go_y = 0.2 * sin(data->player_a - M_PI_2);
	if (move_help(data->world_map[(int)(data->player_y + go_y)][(int)(data->player_x)]))
		data->player_y += go_y;
	if (move_help(data->world_map[(int)(data->player_y)][(int)(data->player_x + go_x)]))
		data->player_x += go_x;
}

static void	ft_move_right(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = 0.2 * cos(data->player_a + M_PI_2);
	go_y = 0.2 * sin(data->player_a + M_PI_2);
	if (move_help(data->world_map[(int)(data->player_y + go_y)][(int)(data->player_x)]))
		data->player_y += go_y;
	if (move_help(data->world_map[(int)(data->player_y)][(int)(data->player_x + go_x)]))
		data->player_x += go_x;
}

static void	ft_move(t_data *data, int key)
{
	if (key == 13)
		ft_move_front(data);
	if (key == 1)
		ft_move_back(data);
	if (key == 0)
		ft_move_left(data);
	if (key == 2)
		ft_move_right(data);
	if (key == 123)
		data->player_a -= 4*M_PI/90;
	if (key == 124)
		data->player_a += 4*M_PI/90;
}

static int		ft_key(int key, t_data *data)
{
	if (key == 13 || key == 2 || key == 0 || key == 1 || key == 123 || key == 124)
	{
		ft_move(data, key);
		ray_casting(data);
	}
	else if (key == 53)
		ft_close(data);
	return (0);
}

void	add_textures(t_data *data, t_parser *pars)
{
	data->tex_n = malloc(sizeof(t_img));
	data->tex_s = malloc(sizeof(t_img));
	data->tex_e = malloc(sizeof(t_img));
	data->tex_w = malloc(sizeof(t_img));
	
	data->tex_n->img = mlx_xpm_file_to_image(data->mlx, pars->tex_n, &data->tex_n->width, &data->tex_n->height);
	if (!(data->tex_n->img))
		ft_error(5);
	data->tex_n->addr = mlx_get_data_addr(data->tex_n->img, &data->tex_n->b_p_p, &data->tex_n->l_l, &data->tex_n->endian);
 	data->tex_s->img = mlx_xpm_file_to_image(data->mlx, pars->tex_s, &data->tex_s->width, &data->tex_s->height);
	 if (!(data->tex_s->img))
		ft_error(5);
 	data->tex_s->addr = mlx_get_data_addr(data->tex_s->img, &data->tex_s->b_p_p, &data->tex_s->l_l, &data->tex_s->endian);
 	data->tex_e->img = mlx_xpm_file_to_image(data->mlx, pars->tex_e, &data->tex_e->width, &data->tex_e->height);
	 if (!(data->tex_e->img))
		ft_error(5);
 	data->tex_e->addr = mlx_get_data_addr(data->tex_e->img, &data->tex_e->b_p_p, &data->tex_e->l_l, &data->tex_e->endian);
	data->tex_w->img = mlx_xpm_file_to_image(data->mlx, pars->tex_w, &data->tex_w->width, &data->tex_w->height);
	if (!(data->tex_w->img))
		ft_error(5);
	data->tex_w->addr = mlx_get_data_addr(data->tex_w->img, &data->tex_w->b_p_p, &data->tex_w->l_l, &data->tex_w->endian);
}

void	add_sprites(t_data *data, t_parser *pars)
{
	int i;
	
	i = 0;
	while (i < pars->buf_sprite)
	{
		data->sprite[i] = malloc(sizeof(t_sprite));
		data->sprite[i]->ptr = malloc(sizeof(t_img));
		data->sprite[i]->ptr->img = mlx_xpm_file_to_image(data->mlx, pars->sprite, &data->sprite[i]->ptr->width, &data->sprite[i]->ptr->height);
		if (!(data->sprite[i]->ptr->img))
			ft_error(5);
		data->sprite[i]->ptr->addr = mlx_get_data_addr(data->sprite[i]->ptr->img, &data->sprite[i]->ptr->b_p_p, &data->sprite[i]->ptr->l_l, &data->sprite[i]->ptr->endian);
		i++;
	}
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->b_p_p, &data->l_l, &data->endian);
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

int		ft_start(t_data *data, t_parser *pars)
{
	if (data->width > 2500)
		data->width = 2500;
	if (data->height > 1300)
		data->height = 1300;
	data->buffer = malloc(sizeof(double) * data->width);
	data->buf_sprite = pars->buf_sprite;
	ft_count_coordinate_sprites(data);
	ray_casting(data);
	mlx_hook(data->win, 2, 0, &ft_key, data);
	mlx_hook(data->win, 17, 0, &ft_close, data);
	mlx_loop(data->mlx);
	return (0);
}