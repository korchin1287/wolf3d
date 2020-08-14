/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:43:32 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/14 17:32:22 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

static void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->l_l + x * (data->b_p_p / 8));
	*(unsigned int*)dst = color;
}

void			init_data(t_data *data)
{
	data->player_x = 13;
	data->player_y = 22;
	data->player_a = -M_PI_2;
	data->fov = M_PI / 3;
	data->color_floor = 0x0000AA3A;
	data->color_roof = 0x006AAADD;
	data->speed = 1;
	data->sprite[0]->y = 12.5;
	data->sprite[0]->x = 12.5;
	data->sprite[1]->y = 12.5;
	data->sprite[1]->x = 14.5;
	data->sprite[2]->y = 13.5;
	data->sprite[2]->x = 13.5;
}

void		paint_floor(t_data *data, int i)
{
	// Рисуем пол
	while (i < height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

void		paint_roof(t_data *data, int i)
{
	// Рисуем потолок
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
	// Рисуем потолок
	paint_roof(data, i);
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_n->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			data->pos = (data->tex_n->y * data->tex_n->l_l + data->tex_n->x * (data->tex_n->b_p_p / 8));
			data->pos2 = data->tex_n->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	paint_floor(data, i);
}

static void	ver_line_s(t_data *data)
{
	int	color;
	int	i;
	
	i = data->draw_start;
	// Рисуем потолок
	paint_roof(data, i);
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_s->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			data->pos = (data->tex_s->y * data->tex_s->l_l + data->tex_s->x * (data->tex_s->b_p_p / 8));
			data->pos2 = data->tex_s->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	paint_floor(data, i);
}

static void	ver_line_e(t_data *data)
{
	int	color;
	int	i;
	
	i = data->draw_start;
	// Рисуем потолок
	paint_roof(data, i);
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_e->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			data->pos = (data->tex_e->y * data->tex_e->l_l + data->tex_e->x * (data->tex_e->b_p_p / 8));
			data->pos2 = data->tex_e->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	paint_floor(data, i);
}

static void	ver_line_w(t_data *data)
{
	int	color;
	int	i;
	
	i = data->draw_start;
	// Рисуем потолок
	paint_roof(data, i);
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_w->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			data->pos = (data->tex_w->y * data->tex_w->l_l + data->tex_w->x * (data->tex_w->b_p_p / 8));
			data->pos2 = data->tex_w->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	paint_floor(data, i);
}

void	casting1(t_data *data)
{
	data->cx = data->player_x;
	data->cy = data->player_y;
	// минимальный шаг изменения направления луча
	data->angle = data->player_a - data->fov / 2 + (data->fov * data->x) / (double)(width);
	data->c = 0;
	while (data->c < 24) //world_map[(int)data->cx][(int)data->cy] != 1)
	{
		// находим координату Х и У
		data->cx = data->player_x + data->c * cos(data->angle);
		data->cy = data->player_y + data->c * sin(data->angle);
		
		// расстояние до стены
		data->c += 0.01;
		if ((world_map[(int)data->cy][(int)data->cx]) == 1)
		{
			while (world_map[(int)data->cy][(int)data->cx] == 1)
			{
				data->c -= 0.0001;
				data->cx = data->player_x + data->c * cos(data->angle);
				data->cy = data->player_y + data->c * sin(data->angle);
			}
			break ;
		}	
	}
}
void	casting2(t_data *data)
{
	buffer[data->x] = data->c;
	// узнаем по Х или У была стена
	data->hitx = data->cx - floor(data->cx + 0.5);
	data->hity = data->cy - floor(data->cy + 0.5);
	// если по Х, то обозначаем что side = 1
	if (fabs(data->hitx) > fabs(data->hity))
		data->side = 1;
	// если по У, то аналогично но по У
	else
		data->side = 0;
}

void	casting2_n(t_data *data)
{
	// узнаем по Х или У была стена
		data->hitx = data->cx - floor(data->cx + 0.5);
		data->hity = data->cy - floor(data->cy + 0.5);
		// если по Х, то делаем смещение по текстуре на Х
		if (fabs(data->hitx) > fabs(data->hity))
			data->tex_n->x = data->tex_n->width * data->hitx;
		// если по У, то аналогично но по У
		else
			data->tex_n->x = data->tex_n->width * data->hity;
		// Проверяем на отрицательное значение
		if (data->tex_n->x < 0)
			data->tex_n->x += data->tex_n->width;
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((height - data->line_height) / 2);
		data->draw_end = (data->line_height + height) / 2;
		if (data->draw_end >= height)
			data->draw_end = height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_n->height;

		ver_line_n(data);
}

void	casting2_s(t_data *data)
{
	// узнаем по Х или У была стена
		data->hitx = data->cx - floor(data->cx + 0.5);
		data->hity = data->cy - floor(data->cy + 0.5);
		// если по Х, то делаем смещение по текстуре на Х
		if (fabs(data->hitx) > fabs(data->hity))
			data->tex_s->x = data->tex_n->width * data->hitx;
		// если по У, то аналогично но по У
		else
			data->tex_s->x = data->tex_s->width * data->hity;
		// Проверяем на отрицательное значение
		if (data->tex_s->x < 0)
			data->tex_s->x += data->tex_s->width;
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((height - data->line_height) / 2);
		data->draw_end = (data->line_height + height) / 2;
		if (data->draw_end >= height)
			data->draw_end = height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_s->height;

		ver_line_s(data);
}

void	casting2_e(t_data *data)
{
	// узнаем по Х или У была стена
		data->hitx = data->cx - floor(data->cx + 0.5);
		data->hity = data->cy - floor(data->cy + 0.5);
		// если по Х, то делаем смещение по текстуре на Х
		if (fabs(data->hitx) > fabs(data->hity))
			data->tex_e->x = data->tex_e->width * data->hitx;
		// если по У, то аналогично но по У
		else
			data->tex_e->x = data->tex_e->width * data->hity;
		// Проверяем на отрицательное значение
		if (data->tex_e->x < 0)
			data->tex_e->x += data->tex_e->width;
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((height - data->line_height) / 2);
		data->draw_end = (data->line_height + height) / 2;
		if (data->draw_end >= height)
			data->draw_end = height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_e->height;

		ver_line_e(data);
}

void	casting2_w(t_data *data)
{
	// узнаем по Х или У была стена
		data->hitx = data->cx - floor(data->cx + 0.5);
		data->hity = data->cy - floor(data->cy + 0.5);
		// если по Х, то делаем смещение по текстуре на Х
		if (fabs(data->hitx) > fabs(data->hity))
			data->tex_w->x = data->tex_w->width * data->hitx;
		// если по У, то аналогично но по У
		else
			data->tex_w->x = data->tex_w->width * data->hity;
		// Проверяем на отрицательное значение
		if (data->tex_w->x < 0)
			data->tex_w->x += data->tex_w->width;
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((height - data->line_height) / 2);
		data->draw_end = (data->line_height + height) / 2;
		if (data->draw_end >= height)
			data->draw_end = height - 1;
		// Соотношение высоты стены и высоты текстуры
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

void	paint_sprite(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->delta_line_h = data->sprite_screen_size / (double)data->sprite[data->i]->ptr->height;
	while (i < data->sprite_screen_size)
	{
		if (data->w_offset + i < 0 || data->w_offset + i >= width || (buffer[data->w_offset + i] < data->sprite[data->i]->sprite_dist))
			i++;
		else
		{
			data->sprite[data->i]->ptr->x = i / data->delta_line_h;
			j = 0;
			while (j < data->sprite_screen_size)
			{
				if (data->h_offset + j < 0 || data->h_offset + j >= height)
					j++;
				else
				{
					data->sprite[data->i]->ptr->y = j / data->delta_line_h;
					// Берем цвет в соответствии с рястягиванием
					data->pos = (data->sprite[data->i]->ptr->y * data->sprite[data->i]->ptr->l_l + data->sprite[data->i]->ptr->x * (data->sprite[data->i]->ptr->b_p_p / 8));
					data->pos2 = data->sprite[data->i]->ptr->addr + data->pos;
					data->color = *(unsigned int*)data->pos2;
					my_mlx_pixel_put(data, width + data->w_offset + i, data->h_offset + j, data->color);
					j++;
				}
			}
			i++;
		}
	}
}

void	make_sprites(t_data *data)
{
	// Абсолютное направление от игрока до спрайта
	data->sprite_dir = atan2(data->sprite[data->i]->y - data->player_y, data->sprite[data->i]->x - data->player_x);
	// Удаление лишних оборотов
	while (data->sprite_dir - data->player_a > M_PI)
		data->sprite_dir -= 2 * M_PI;
	while (data->sprite_dir - data->player_a < -M_PI)
		data->sprite_dir += 2 * M_PI;
	// Считаем размер спрайта на экране 
	data->sprite_screen_size = height / data->sprite[data->i]->sprite_dist;
	// w_offset - это координата левого верхнего угла спрайта по ширине
	data->w_offset = (data->sprite_dir - data->player_a) / data->fov * (width) + (width) / 2 - 64 / 2;
	// h_offset - это координата левого верхнего угла спрайта по высоте
	data->h_offset = height / 2 - data->sprite_screen_size / 2;
}

void	add_and_sort_sprite(t_data *data)
{
	int	i;
	t_sprite *tmp;

	data->i = 0;
	while (data->i < n)
	{
		data->sprite[data->i]->sprite_dist = sqrt((data->player_x - data->sprite[data->i]->x) * (data->player_x - data->sprite[data->i]->x) + (data->player_y - data->sprite[data->i]->y) * (data->player_y - data->sprite[data->i]->y));
		(data->i)++;
	}
	i = 0;
	while (i < n - 1)
	{
		int j = 0;
		while (j < (n - i - 1))
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
	while (data->x < width)
	{
		casting1(data);
		casting2(data);
		// Смотрим какая стена и рисуем в зависимости от направления - текстуру 
		ft_side_wall(data);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	// Считаем расстояние от игрока до спрайта
	add_and_sort_sprite(data);
	data->i = 0;
	while ((data->i) < n)
	{
		make_sprites(data);
		// Рисуем спрайт
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

static void	ft_move_front(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = cos(data->player_a) * 0.2;
	go_y = sin(data->player_a) * 0.2;
	if (world_map[(int)(data->player_y + go_y)][(int)(data->player_x)] == 0)
		data->player_y += go_y;
	if (world_map[(int)(data->player_y)][(int)(data->player_x + go_x)] == 0)
		data->player_x += go_x;
} 

static void	ft_move_back(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = cos(data->player_a) * 0.2;
	go_y = sin(data->player_a) * 0.2;
	if (world_map[(int)(data->player_y - go_y)][(int)(data->player_x)] == 0)
		data->player_y -= go_y;
	if (world_map[(int)(data->player_y)][(int)(data->player_x - go_x)] == 0)
		data->player_x -= go_x;
}

static void	ft_move_left(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = 0.2 * cos(data->player_a - M_PI_2);
	go_y = 0.2 * sin(data->player_a - M_PI_2);

	if (world_map[(int)(data->player_y + go_y)][(int)(data->player_x)] == 0)
		data->player_y += go_y;
	if (world_map[(int)(data->player_y)][(int)(data->player_x + go_x)] == 0)
		data->player_x += go_x;
}

static void	ft_move_right(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = 0.2 * cos(data->player_a + M_PI_2);
	go_y = 0.2 * sin(data->player_a + M_PI_2);

	if (world_map[(int)(data->player_y + go_y)][(int)(data->player_x)] == 0)
		data->player_y += go_y;
	if (world_map[(int)(data->player_y)][(int)(data->player_x + go_x)] == 0)
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

static void	ft_black(t_data *data, int color)
{
	int	i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

static int		ft_key(int key, t_data *data)
{
	if (key == 13 || key == 2 || key == 0 || key == 1 || key == 123 || key == 124)
	{
		ft_black(data, 0x00000000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		ft_move(data, key);
		ray_casting(data);
	}
	else if (key == 53)
		ft_close(data);
	return (0);
}

void	add_textures(t_data *data)
{
	char	*tex1 = "../textures/greystone.xpm";
	char	*tex2 = "../textures/colorstone.xpm";
	char	*tex3 = "../textures/bluestone.xpm";
	char	*tex4 = "../textures/eagle.xpm";

	data->tex_n = malloc(sizeof(t_img));
	data->tex_s = malloc(sizeof(t_img));
	data->tex_e = malloc(sizeof(t_img));
	data->tex_w = malloc(sizeof(t_img));
	
	data->tex_n->img = mlx_xpm_file_to_image(data->mlx, tex1, &data->tex_n->width, &data->tex_n->height);
	data->tex_n->addr = mlx_get_data_addr(data->tex_n->img, &data->tex_n->b_p_p, &data->tex_n->l_l, &data->tex_n->endian);
	
	data->tex_s->img = mlx_xpm_file_to_image(data->mlx, tex2, &data->tex_s->width, &data->tex_s->height);
	data->tex_s->addr = mlx_get_data_addr(data->tex_s->img, &data->tex_s->b_p_p, &data->tex_s->l_l, &data->tex_s->endian);
	
	data->tex_e->img = mlx_xpm_file_to_image(data->mlx, tex3, &data->tex_e->width, &data->tex_e->height);
	data->tex_e->addr = mlx_get_data_addr(data->tex_e->img, &data->tex_e->b_p_p, &data->tex_e->l_l, &data->tex_e->endian);
	
	data->tex_w->img = mlx_xpm_file_to_image(data->mlx, tex4, &data->tex_w->width, &data->tex_w->height);
	data->tex_w->addr = mlx_get_data_addr(data->tex_w->img, &data->tex_w->b_p_p, &data->tex_w->l_l, &data->tex_w->endian);
}

void	add_sprites(t_data *data)
{
	int i;
	char	*sprite_tree = "../textures/Tree1.xpm";
	
	i = 0;
	while (i < n)
	{
		data->sprite[i] = malloc(sizeof(t_sprite));
		data->sprite[i]->ptr = malloc(sizeof(t_img));
		data->sprite[i]->ptr->img = mlx_xpm_file_to_image(data->mlx, sprite_tree, &data->sprite[i]->ptr->width, &data->sprite[i]->ptr->height);
		data->sprite[i]->ptr->addr = mlx_get_data_addr(data->sprite[i]->ptr->img, &data->sprite[i]->ptr->b_p_p, &data->sprite[i]->ptr->l_l, &data->sprite[i]->ptr->endian);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
//	init_data(data);
	if (width > 2500)
		width = 2500;
	if (height > 1300)
		height = 1300;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "cub3d");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->b_p_p, &data->l_l, &data->endian);
	
	add_textures(data);
	add_sprites(data);	
	init_data(data);
	ray_casting(data);

	
	mlx_hook(data->win, 2, 0, &ft_key, data);
	mlx_hook(data->win, 17, 0, &ft_close, data);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_n->img, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_s->img, 0, 64);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_e->img, 0, 128);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_w->img, 0, 192);
//	mlx_put_image_to_window(data->mlx, data->win, data->sprite_1->ptr->img, 0, 0);
	mlx_loop(data->mlx);
}
