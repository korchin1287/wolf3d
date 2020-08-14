/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:43:32 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/04 15:47:59 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->l_l + x * (data->b_p_p / 8));
	*(unsigned int*)dst = color;
}

static void	init_data(t_data *data)
{
	data->color_floor = 0x0000AA3A;
	data->color_roof = 0x006AAADD;
	data->pos_x = 22;
	data->pos_y = 16;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->speed = 1;
}

static void	casting1(t_data *data)
{
	data->map_x_start = (int)data->pos_x;
	data->map_y_start = (int)data->pos_y;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->camera_x = 2 * data->x / (double)data->width - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
}

static void	casting2(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

static void	casting3(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (world_map[data->map_x][data->map_y] > 0)
			data->hit = 1;
	}
}

static void	casting4(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->map_x - data->pos_x + (1 - data->step_x)
				/ 2) / data->ray_dir_x;
	else
		data->perp_wall_dist = (data->map_y - data->pos_y + (1 - data->step_y)
				/ 2) / data->ray_dir_y;
	data->line_height = (int)(data->height / data->perp_wall_dist);
	data->draw_start = (int)(-(data->line_height) / 2 + data->height / 2);
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->height / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
}

static void	verLine_sprite(t_data *data)
{
	int color;
	int	pos;
	char	*pos2;
	int count;
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
		data->sprite->y = (int)data->sprite->pos & (data->sprite->height - 1);
		data->sprite->pos += data->step;
		pos = (data->sprite->y * data->sprite->l_l + data->sprite->x * (data->sprite->b_p_p / 8));
		pos2 = data->sprite->addr + pos;
		color = *(unsigned int*)pos2;
		my_mlx_pixel_put(data, data->x, i, color);
		i++;
	}
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	ft_tex_sprite(t_data *data)
{
		if (data->side == 0)
			data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
		else
			data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
		data->wall_x -= floor((data->wall_x));
		data->sprite->x = (int)(data->wall_x * (double)(data->sprite->width));
//		if ((data->ray_dir_x > 0))
//			data->sprite->x = data->sprite->width - data->sprite->x - 1;
//		if ((data->ray_dir_y < 0))
//			data->sprite->x = data->sprite->width - data->sprite->x - 1;
		data->step = 1.0 * data->sprite->height / data->line_height;
		data->sprite->pos = (data->draw_start - data->height / 2 + data->line_height / 2) * data->step;
		verLine_sprite(data);
}

void	ft_sprite(t_data *data)
{	
	data->perp_wall_dist = (double)sqrt((data->map_x_start - data->map_x) * (data->map_x_start - data->map_x) + (data->map_y_start - data->map_y) * (data->map_y_start - data->map_y)); 
	data->line_height = (int)(data->height / data->perp_wall_dist);
	data->draw_start = (int)(-(data->line_height) / 2 + data->height / 2);
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->height / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	ft_tex_sprite(data);
}

static void	verLine_n(t_data *data)
{
	int color;
	int	pos;
	char	*pos2;
	int count;
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
		data->tex_n->y = (int)data->tex_n->pos & (data->tex_n->height - 1);
		data->tex_n->pos += data->step;
		pos = (data->tex_n->y * data->tex_n->l_l + data->tex_n->x * (data->tex_n->b_p_p / 8));
		pos2 = data->tex_n->addr + pos;
		color = *(unsigned int*)pos2;
		my_mlx_pixel_put(data, data->x, i, color);
		i++;
	}
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	verLine_s(t_data *data)
{
	int color;
	int	pos;
	char	*pos2;
	int count;
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
		data->tex_s->y = (int)data->tex_s->pos & (data->tex_s->height - 1);
		data->tex_s->pos += data->step;
		pos = (data->tex_s->y * data->tex_s->l_l + data->tex_s->x * (data->tex_s->b_p_p / 8));
		pos2 = data->tex_s->addr + pos;
		color = *(unsigned int*)pos2;
		my_mlx_pixel_put(data, data->x, i, color);
		i++;
	}
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	verLine_e(t_data *data)
{
	int color;
	int	pos;
	char	*pos2;
	int count;
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
		data->tex_e->y = (int)data->tex_e->pos & (data->tex_e->height - 1);
		data->tex_e->pos += data->step;
		pos = (data->tex_e->y * data->tex_e->l_l + data->tex_e->x * (data->tex_e->b_p_p / 8));
		pos2 = data->tex_e->addr + pos;
		color = *(unsigned int*)pos2;
		my_mlx_pixel_put(data, data->x, i, color);
		i++;
	}
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	verLine_w(t_data *data)
{
	int color;
	int	pos;
	char	*pos2;
	int count;
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
		data->tex_w->y = (int)data->tex_w->pos & (data->tex_w->height - 1);
		data->tex_w->pos += data->step;
		pos = (data->tex_w->y * data->tex_w->l_l + data->tex_w->x * (data->tex_w->b_p_p / 8));
		pos2 = data->tex_w->addr + pos;
		color = *(unsigned int*)pos2;
		my_mlx_pixel_put(data, data->x, i, color);
		i++;
	}
	while (i < data->height)
	{
		my_mlx_pixel_put(data, data->x, i, data->color_floor);
		i++;
	}
}

static void	ft_tex_n(t_data *data)
{
		if (data->side == 0)
			data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
		else
			data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
		data->wall_x -= floor((data->wall_x));
		data->tex_n->x = (int)(data->wall_x * (double)(data->tex_n->width));
		if (data->side == 0 && (data->ray_dir_x > 0))
			data->tex_n->x = data->tex_n->width - data->tex_n->x - 1;
		if (data->side == 1 && (data->ray_dir_y < 0))
			data->tex_n->x = data->tex_n->width - data->tex_n->x - 1;
		data->step = 1.0 * data->tex_n->height / data->line_height;
		data->tex_n->pos = (data->draw_start - data->height / 2 + data->line_height / 2) * data->step;
		verLine_n(data);
}

static void	ft_tex_s(t_data *data)
{
		if (data->side == 0)
			data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
		else
			data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
		data->wall_x -= floor((data->wall_x));
		data->tex_s->x = (int)(data->wall_x * (double)(data->tex_s->width));
		if (data->side == 0 && (data->ray_dir_x > 0))
			data->tex_s->x = data->tex_s->width - data->tex_s->x - 1;
		if (data->side == 1 && (data->ray_dir_y < 0))
			data->tex_s->x = data->tex_s->width - data->tex_s->x - 1;
		data->step = 1.0 * data->tex_s->height / data->line_height;
		data->tex_s->pos = (data->draw_start - data->height / 2 + data->line_height / 2) * data->step;
		verLine_s(data);
}

static void	ft_tex_e(t_data *data)
{
		if (data->side == 0)
			data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
		else
			data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
		data->wall_x -= floor((data->wall_x));
		data->tex_e->x = (int)(data->wall_x * (double)(data->tex_e->width));
		if (data->side == 0 && (data->ray_dir_x > 0))
			data->tex_e->x = data->tex_e->width - data->tex_e->x - 1;
		if (data->side == 1 && (data->ray_dir_y < 0))
			data->tex_e->x = data->tex_e->width - data->tex_e->x - 1;
		data->step = 1.0 * data->tex_e->height / data->line_height;
		data->tex_e->pos = (data->draw_start - data->height / 2 + data->line_height / 2) * data->step;
		verLine_e(data);
}


static void	ft_tex_w(t_data *data)
{
		if (data->side == 0)
			data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
		else
			data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
		data->wall_x -= floor((data->wall_x));
		data->tex_w->x = (int)(data->wall_x * (double)(data->tex_w->width));
		if (data->side == 0 && (data->ray_dir_x > 0))
			data->tex_w->x = data->tex_w->width - data->tex_w->x - 1;
		if (data->side == 1 && (data->ray_dir_y < 0))
			data->tex_w->x = data->tex_w->width - data->tex_w->x - 1;
		data->step = 1.0 * data->tex_w->height / data->line_height;
		data->tex_w->pos = (data->draw_start - data->height / 2 + data->line_height / 2) * data->step;
		verLine_w(data);
}

static void		ft_side_wall(t_data *data)
{
	if (data->map_x < data->map_x_start && data->side == 0)
		ft_tex_n(data);
	if (data->map_x > data->map_x_start && data->side == 0)
		ft_tex_s(data);
	if (data->map_y < data->map_y_start && data->side == 1)
		ft_tex_e(data);
	if (data->map_y > data->map_y_start && data->side == 1)
		ft_tex_w(data);
//	if (world_map[data->map_x][data->map_y] == 2)
//		ft_sprite(data);	
}

static void	ray_casting(t_data *data)
{
	while (data->x < data->width)
	{
		casting1(data);
		data->hit = 0;
		casting2(data);
		casting3(data);
		casting4(data);
		ft_side_wall(data);
	//	ft_sprite(data);	
		(data->x)++;
		Zbuffer[data->x] = data->perp_wall_dist;
	}

	
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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

static void	ft_move_front(t_data *data)
{
	if (!(world_map[(int)(data->pos_x + data->dir_x * (0.2 * data->speed))][(int)(data->pos_y)]))
		data->pos_x += (data->dir_x * (0.2 * data->speed));
	if (!(world_map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * (0.2 * data->speed))]))
		data->pos_y += (data->dir_y * (0.2 * data->speed));
}

static void	ft_move_back(t_data *data)
{
	if (!(world_map[(int)(data->pos_x - data->dir_x * (0.2 * data->speed))][(int)(data->pos_y)]))
		data->pos_x -= (data->dir_x * (0.2 * data->speed));
	if (!(world_map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y * (0.2 * data->speed))]))
		data->pos_y -= (data->dir_y * (0.2 * data->speed));
}

static void	ft_move_left(t_data *data)
{
	if (!(world_map[(int)(data->pos_x + data->dir_x * (0.2 * data->speed))][(int)(data->pos_y)]))
		data->pos_x -= (data->dir_y * (0.2 * data->speed));
	if (!(world_map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * (0.2 * data->speed))]))
		data->pos_y += (data->dir_x * (0.2 * data->speed));
}

static void	ft_move_right(t_data *data)
{
	if (!(world_map[(int)(data->pos_x - data->dir_x * (0.2 * data->speed))][(int)(data->pos_y)]))
		data->pos_x += (data->dir_y * (0.2 * data->speed));
	if (!(world_map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y * (0.2 * data->speed))]))
		data->pos_y -= (data->dir_x * (0.2 * data->speed));
}

static void	ft_move_turn_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(0.0875 * 2) - data->dir_y * sin(0.0875 * 2);
	data->dir_y = old_dir_x * sin(0.0875 * 2) + data->dir_y * cos(0.0875 * 2);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(0.175) - data->plane_y * sin(0.175);
	data->plane_y = old_plane_x * sin(0.175) + data->plane_y * cos(0.175);
}

static void	ft_move_turn_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-0.175) - data->dir_y * sin(-0.175);
	data->dir_y = old_dir_x * sin(-0.175) + data->dir_y * cos(-0.175);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-0.175) - data->plane_y * sin(-0.175);
	data->plane_y = old_plane_x * sin(-0.175) + data->plane_y * cos(-0.175);
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
		ft_move_turn_left(data);
	if (key == 124)
		ft_move_turn_right(data);
}

static int			ft_close(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
	return (0);
}

static int		ft_key(int key, t_data *data)
{
	data->x = 0;
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

void	get_textures(t_data *data, char *tex1, char *tex2, char *tex3, char *tex4)
{
	data->tex_n->img = mlx_xpm_file_to_image(data->mlx, tex1, &data->tex_n->width, &data->tex_n->height);
	data->tex_n->addr = mlx_get_data_addr(data->tex_n->img, &data->tex_n->b_p_p, &data->tex_n->l_l, &data->tex_n->endian);

	data->tex_s->img = mlx_xpm_file_to_image(data->mlx, tex2, &data->tex_s->width, &data->tex_s->height);
	data->tex_s->addr = mlx_get_data_addr(data->tex_s->img, &data->tex_s->b_p_p, &data->tex_s->l_l, &data->tex_s->endian);
	
	data->tex_e->img = mlx_xpm_file_to_image(data->mlx, tex3, &data->tex_e->width, &data->tex_e->height);
	data->tex_e->addr = mlx_get_data_addr(data->tex_e->img, &data->tex_e->b_p_p, &data->tex_e->l_l, &data->tex_e->endian);
	
	data->tex_w->img = mlx_xpm_file_to_image(data->mlx, tex4, &data->tex_w->width, &data->tex_w->height);
	data->tex_w->addr = mlx_get_data_addr(data->tex_w->img, &data->tex_w->b_p_p, &data->tex_w->l_l, &data->tex_w->endian);
}

void	get_sprite(t_data *data, char *sprite)
{

	data->sprite->img = mlx_xpm_file_to_image(data->mlx, sprite, &data->sprite->width, &data->sprite->height);
	data->sprite->addr = mlx_get_data_addr(data->sprite->img, &data->sprite->b_p_p, &data->sprite->l_l, &data->sprite->endian);
}
int		main(int ac, char **av)
{
	t_data	*data;
	char	*tex1 = "../textures/greystone.xpm";
	char	*tex2 = "../textures/colorstone.xpm";
	char	*tex3 = "../textures/bluestone.xpm";
	char	*tex4 = "../textures/eagle.xpm";
	char	*sprite = "../textures/Tree1.xpm";

	data = malloc(sizeof(t_data));
	data->tex_n = malloc(sizeof(t_img));
	data->tex_s = malloc(sizeof(t_img));
	data->tex_e = malloc(sizeof(t_img));
	data->tex_w = malloc(sizeof(t_img));
	data->sprite = malloc(sizeof(t_img));
	data->width = 640;
	data->height = 480;
	init_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->b_p_p, &data->l_l, &data->endian);
	get_textures(data, tex1, tex2, tex3, tex4);
	get_sprite(data, sprite);
	ray_casting(data);


	
	mlx_hook(data->win, 2, 0, &ft_key, data);
	mlx_hook(data->win, 17, 0, &ft_close, data);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_n->img, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_s->img, 0+64, 0);
//	mlx_put_image_to_window(data->mlx, data->win, data->tex_e->img, 0+64+64, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->sprite->img, 0, 0);
	mlx_loop(data->mlx);
}
