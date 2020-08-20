/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:52:58 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:02:57 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

void			init_data(t_data *data, t_parser *pars)
{
	data->world_map = pars->world_map;
	data->player_x = pars->player_x;
	data->player_y = pars->player_y;
	data->player_a = pars->player_a;
	data->fov = M_PI / 3;
	data->color_floor = pars->color_floor;
	data->color_roof = pars->color_roof;
	data->speed = 1;
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

void	ft_init(t_data *data, t_parser *pars)
{
	data->sprite = malloc(sizeof(t_sprite) * pars->buf_sprite);
	data->width = pars->width;
	data->height = pars->height;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->b_p_p, &data->l_l, &data->endian);
	add_textures(data, pars);
	add_sprites(data, pars);
	init_data(data, pars);
}