/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:19:51 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/21 20:11:54 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	casting2_n(t_data *data)
{
	if (fabs(data->hitx) > fabs(data->hity))
		data->tex_n->x = data->tex_n->width * data->hitx;
	else
		data->tex_n->x = data->tex_n->width * data->hity;
	if (data->tex_n->x < 0)
		data->tex_n->x += data->tex_n->width;
	data->line_height = (int)(data->height / (data->c * cos(data->angle -
		data->player_a)));
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
	data->line_height = (int)(data->height / (data->c * cos(data->angle -
		data->player_a)));
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
	data->line_height = (int)(data->height / (data->c * cos(data->angle -
		data->player_a)));
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
	data->line_height = (int)(data->height / (data->c * cos(data->angle -
		data->player_a)));
	data->draw_start = (int)((data->height - data->line_height) / 2);
	data->draw_end = (data->line_height + data->height) / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	data->delta_line_h = data->line_height / (double)data->tex_w->height;
	ver_line_w(data);
}

void	ft_side_wall(t_data *data)
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
