/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:43:32 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/12 16:59:02 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d4.h"

static void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->l_l + x * (data->b_p_p / 8));
	*(unsigned int*)dst = color;
}

void			init_data(t_data *data)
{
	data->width = 640;
	data->height = 480;
	data->player_x = 9;
	data->player_y = 17;
	data->player_a = M_PI_4;
	data->fov = M_PI / 3;
	data->color_floor = 0x0000AA3A;
	data->color_roof = 0x006AAADD;
	data->speed = 1;
}



static void	ver_line_n(t_data *data)
{
	int color;
	int pos;
	char *pos2;
	int	i;
	int r;

	r = 0;
	i = data->draw_start;
	// Рисуем потолок
	while (r < i)
	{
		my_mlx_pixel_put(data, data->x, r, data->color_roof);
		r++;
	}
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_n->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			pos = (data->tex_n->y * data->tex_n->l_l + data->tex_n->x * (data->tex_n->b_p_p / 8));
			pos2 = data->tex_n->addr + pos;
			color = *(unsigned int*)pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	ver_line_s(t_data *data)
{
	int	color;
	int pos;
	char *pos2;
	int	i;
	int r;

	r = 0;
	i = data->draw_start;
	// Рисуем потолок
	while (r < i)
	{
		my_mlx_pixel_put(data, data->x, r, data->color_roof);
		r++;
	}
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_s->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			pos = (data->tex_s->y * data->tex_s->l_l + data->tex_s->x * (data->tex_s->b_p_p / 8));
			pos2 = data->tex_s->addr + pos;
			color = *(unsigned int*)pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	ver_line_e(t_data *data)
{
	int	color;
	int pos;
	char *pos2;
	int	i;
	int r;

	r = 0;
	i = data->draw_start;
	// Рисуем потолок
	while (r < i)
	{
		my_mlx_pixel_put(data, data->x, r, data->color_roof);
		r++;
	}
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_e->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			pos = (data->tex_e->y * data->tex_e->l_l + data->tex_e->x * (data->tex_e->b_p_p / 8));
			pos2 = data->tex_e->addr + pos;
			color = *(unsigned int*)pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	ver_line_w(t_data *data)
{
	int	color;
	int pos;
	char *pos2;
	int	i;
	int r;

	r = 0;
	i = data->draw_start;
	// Рисуем потолок
	while (r < i)
	{
		my_mlx_pixel_put(data, data->x, r, data->color_roof);
		r++;
	}
	//Рисуем стену	
	while (i < data->draw_end)
	{
		// Этот ИФ нужен чтоб сместиться по текстуре в начале экрана, когда очень близко
		if (i > 0)
		{
			// Берем по вертикальной полосе пиксель в зависимости от соотношения стены к текстуре
			data->tex_w->y = (i - data->draw_start) / data->delta_line_h;
			// Берем цвет в соответствии с рястягиванием
			pos = (data->tex_w->y * data->tex_w->l_l + data->tex_w->x * (data->tex_w->b_p_p / 8));
			pos2 = data->tex_w->addr + pos;
			color = *(unsigned int*)pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	// Рисуем пол
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	ver_line1(t_data *data, int color)
{
	int	i;
	int r;

	r = 0;
	i = data->draw_start;
	while (r < i)
	{
		my_mlx_pixel_put(data, data->x, r, data->color_roof);
		r++;
	}
	while (i < data->draw_end)
	{
		my_mlx_pixel_put(data, data->x, i, color);
		i++;
	}
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

void	casting1(t_data *data)
{
	int	x;
	data->cx1 = data->player_x;
	data->cy1 = data->player_y;
	data->cx2 = data->player_x;
	data->cy2 = data->player_y;
	data->cx1_1 = data->player_x;
	data->cy1_1 = data->player_y;
		// минимальный шаг изменения направления луча
		data->angle = data->player_a - data->fov / 2 + (data->fov * data->x) / (double)(data->width);
		data->lenx = 1;
		data->leny = 1;
		x = 0;
		while ((x < 24) && (((world_map[(int)data->cy1][(int)data->cx1]) != 1) || ((world_map[(int)data->cy2][(int)data->cx2]) != 1)))
		{
			if (world_map[(int)data->cy1][(int)data->cx1] == 0)
			{
				data->cy1 += data->leny;
				data->cx1 += data->leny / tan(data->angle);
			//	data->cy1_1 += data->leny - (data->player_y - floor(data->player_y));
			//	data->cx1_1 += (data->leny - (data->player_y - floor(data->player_y))) / tan(data->angle);
				data->c1 = sqrt(((data->player_y - data->cy1) * (data->player_y - data->cy1)) + ((data->player_x - data->cx1) * (data->player_x - data->cx1)));	
			}
			if (world_map[(int)data->cy2][(int)data->cx2] == 0)
			{
			//	data->cx2 += data->lenx;
			//	data->cy2 += data->lenx * tan(data->angle);
				data->cx2 += data->lenx - (data->player_x - floor(data->player_x));
				data->cy2 += (data->lenx - (data->player_x - floor(data->player_x))) * tan(data->angle);
				data->c2 = sqrt(((data->player_y - data->cy2) * (data->player_y - data->cy2)) + ((data->player_x - data->cx2) * (data->player_x - data->cx2)));
			}
			x++;
		}
		if (data->c1 <= data->c2)
		{
			data->side = 1;
			data->c = data->c1;
		}
		else
		{
			data->side = 0;
			data->c = data->c2;
		}
		
}
void	casting2(t_data *data)
{
	// узнаем по Х или У была стена
	//		data->hitx = data->cx - floor(data->cx + 0.5);
	//	data->hity = data->cy - floor(data->cy + 0.5);
		// если по Х, то делаем смещение по текстуре на Х
	//	if (fabs(data->hitx) > fabs(data->hity))
	//	{
		//	data->side = 1;
		//	data->tex_n->x = data->tex_n->width * data->hitx;
	//	}
		// если по У, то аналогично но по У
	//	else
	//	{
		//	data->side = 0;
		//	data->tex_n->x = data->tex_n->width * data->hity;
	//	}
		// Проверяем на отрицательное значение
		//if (data->tex_n->x < 0)
		//	data->tex_n->x += data->tex_n->width;
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((data->height - data->line_height) / 2);
		data->draw_end = (data->line_height + data->height) / 2;
		if (data->draw_end >= data->height)
			data->draw_end = data->height - 1;
		// Соотношение высоты стены и высоты текстуры
		//data->delta_line_h = data->line_height / (double)data->tex_n->height;

}

void	casting2_n(t_data *data)
{
	
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((data->height - data->line_height) / 2);
		data->draw_end = (data->line_height + data->height) / 2;
		if (data->draw_end >= data->height)
			data->draw_end = data->height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_n->height;

		ver_line_n(data);
}

void	casting2_s(t_data *data)
{

		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((data->height - data->line_height) / 2);                                                                                                                                                                                                                                                                                                                                                                                                                                          
		data->draw_end = (data->line_height + data->height) / 2;
		if (data->draw_end >= data->height)
			data->draw_end = data->height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_s->height;

		ver_line_s(data);
}

void	casting2_e(t_data *data)
{
	
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((data->height - data->line_height) / 2);
		data->draw_end = (data->line_height + data->height) / 2;
		if (data->draw_end >= data->height)
			data->draw_end = data->height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_e->height;

		ver_line_e(data);
}

void	casting2_w(t_data *data)
{
	
		// Наxодим высоту стены, ее начало и ее конец
		data->line_height = (int)(data->height / (data->c * cos(data->angle - data->player_a)));
		data->draw_start = (int)((data->height - data->line_height) / 2);
		data->draw_end = (data->line_height + data->height) / 2;
		if (data->draw_end >= data->height)
			data->draw_end = data->height - 1;
		// Соотношение высоты стены и высоты текстуры
		data->delta_line_h = data->line_height / (double)data->tex_w->height;
		
		ver_line_w(data);
}
static void		ft_side_wall(t_data *data)
{
	if (data->cy1 < data->player_y && data->side == 1)
		ver_line1(data, 0x00ff0000);
	if (data->cy1 > data->player_y && data->side == 1)
		ver_line1(data, 0x0000ff00);
	if (data->cx2 < data->player_x && data->side == 0)
		ver_line1(data, 0x000000ff);
	if (data->cx2 > data->player_x && data->side == 0)
		ver_line1(data, 0x00ff00ff);
}

void	ray_casting(t_data *data)
{
	int	color = 0x00a7a7a7;
	data->x = 0;
//	data->tex_n->x = 0;
	while (data->x < data->width)
	{
		casting1(data);
		casting2(data);
		
		// Смотрим какая стена и рисуем в зависимости от направления - текстуру 
		ft_side_wall(data);

		// Рисуем стену из текстуры
		//ver_line(data, color);
		
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
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
	else
		ray_casting(data);
	return (1);
}
/*
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
*/
int		main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data(data);
	if (data->width > 2500)
		data->width = 2500;
	if (data->height > 1300)
		data->height = 1300;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->b_p_p, &data->l_l, &data->endian);
	
//	add_textures(data);
	ray_casting(data);

	
	mlx_hook(data->win, 2, 0, &ft_key, data);
	mlx_hook(data->win, 17, 0, &ft_close, data);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_n->img, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_s->img, 0, 64);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_e->img, 0, 128);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_w->img, 0, 192);
//	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}
