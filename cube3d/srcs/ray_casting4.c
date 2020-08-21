/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:25:57 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/21 20:12:00 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
