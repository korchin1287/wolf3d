/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:36:18 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/21 20:11:36 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		move_help(char c)
{
	if (c == '1' || c == '2')
		return (0);
	return (1);
}

void	ft_move_front(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = cos(data->player_a) * 0.2;
	go_y = sin(data->player_a) * 0.2;
	if (move_help(data->world_map[(int)(data->player_y + go_y)]
		[(int)(data->player_x)]))
		data->player_y += go_y;
	if (move_help(data->world_map[(int)(data->player_y)]
		[(int)(data->player_x + go_x)]))
		data->player_x += go_x;
}

void	ft_move_back(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = cos(data->player_a) * 0.2;
	go_y = sin(data->player_a) * 0.2;
	if (move_help(data->world_map[(int)(data->player_y - go_y)]
		[(int)(data->player_x)]))
		data->player_y -= go_y;
	if (move_help(data->world_map[(int)(data->player_y)]
		[(int)(data->player_x - go_x)]))
		data->player_x -= go_x;
}

void	ft_move_left(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = 0.2 * cos(data->player_a - M_PI_2);
	go_y = 0.2 * sin(data->player_a - M_PI_2);
	if (move_help(data->world_map[(int)(data->player_y + go_y)]
		[(int)(data->player_x)]))
		data->player_y += go_y;
	if (move_help(data->world_map[(int)(data->player_y)]
		[(int)(data->player_x + go_x)]))
		data->player_x += go_x;
}

void	ft_move_right(t_data *data)
{
	double	go_x;
	double	go_y;

	go_x = 0.2 * cos(data->player_a + M_PI_2);
	go_y = 0.2 * sin(data->player_a + M_PI_2);
	if (move_help(data->world_map[(int)(data->player_y + go_y)]
		[(int)(data->player_x)]))
		data->player_y += go_y;
	if (move_help(data->world_map[(int)(data->player_y)]
		[(int)(data->player_x + go_x)]))
		data->player_x += go_x;
}
