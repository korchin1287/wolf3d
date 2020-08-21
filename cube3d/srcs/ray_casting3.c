/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:22:53 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/21 20:11:57 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_l + x * (data->b_p_p / 8));
	*(unsigned int*)dst = color;
}

void	ver_line_n(t_data *data)
{
	int		color;
	int		i;

	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_n->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_n->y * data->tex_n->l_l + data->tex_n->x *
				(data->tex_n->b_p_p / 8));
			data->pos2 = data->tex_n->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

void	ver_line_s(t_data *data)
{
	int		color;
	int		i;

	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_s->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_s->y * data->tex_s->l_l + data->tex_s->x *
				(data->tex_s->b_p_p / 8));
			data->pos2 = data->tex_s->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

void	ver_line_e(t_data *data)
{
	int		color;
	int		i;

	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_e->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_e->y * data->tex_e->l_l + data->tex_e->x *
				(data->tex_e->b_p_p / 8));
			data->pos2 = data->tex_e->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}

void	ver_line_w(t_data *data)
{
	int		color;
	int		i;

	i = data->draw_start;
	paint_roof(data, i);
	while (i < data->draw_end)
	{
		if (i > 0)
		{
			data->tex_w->y = (i - data->draw_start) / data->delta_line_h;
			data->pos = (data->tex_w->y * data->tex_w->l_l + data->tex_w->x *
				(data->tex_w->b_p_p / 8));
			data->pos2 = data->tex_w->addr + data->pos;
			color = *(unsigned int*)data->pos2;
			my_mlx_pixel_put(data, data->x, i, color);
		}
		i++;
	}
	paint_floor(data, i);
}
