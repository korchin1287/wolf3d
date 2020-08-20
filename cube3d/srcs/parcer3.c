/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:43:24 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:22:53 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

int			not_space(char c)
{
	if (c != ' ')
		return (1);
	else
	{
		ft_error(6);
		return (0);
	}
}

void		ft_add_player_coordinates(t_parser *pars, char c)
{
	pars->player_y = (double)pars->i + 0.5;
	pars->player_x = (double)pars->j + 0.5;
	if (c == 'N')
		pars->player_a = -M_PI_2;
	if (c == 'S')
		pars->player_a = M_PI_2;
	if (c == 'E')
		pars->player_a = M_PI;
	if (c == 'W')
		pars->player_a = 0;
	pars->is_player++;
	
}	

void		ft_add_player(t_parser *pars)
{
	pars->is_player = 0;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{	
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (ft_check_player_map(pars->world_map[pars->i][pars->j]))
				ft_add_player_coordinates(pars, pars->world_map[pars->i][pars->j]);
			pars->j++;
		}
		pars->i++;
	}
	if (pars->is_player != 1)
		ft_error(2);
}

void		ft_check_space(t_parser *pars, int num_str, int len_str)
{
	if (pars->j > 0)
		not_space(pars->world_map[pars->i][pars->j - 1]);
	if (pars->j < len_str)
		not_space(pars->world_map[pars->i][pars->j + 1]);
	if (pars->i > 0)
		not_space(pars->world_map[pars->i - 1][pars->j]);
	if (pars->i < num_str)
		not_space(pars->world_map[pars->i + 1][pars->j]);
}

void		ft_check_map_side(t_parser *pars)
{
	int len_str;
	int	num_str;

	pars->i = 0;
	len_str = ft_strlen(pars->world_map[0]);
	while (pars->world_map[pars->i])
		pars->i++;
	num_str = pars->i;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (pars->world_map[pars->i][pars->j] != '1' && pars->world_map[pars->i][pars->j] != ' ')
				ft_check_space(pars, num_str, len_str);
			pars->j++;		
		}
		pars->i++;
	}
	ft_add_player(pars);
}