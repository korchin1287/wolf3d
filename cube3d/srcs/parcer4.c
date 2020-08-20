/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:46:01 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:22:55 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

int			ft_check_player_map(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	ft_change_space(t_parser *pars)
{
	pars->i = 0;
	while (pars->world_map[pars->i])
	{	
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (pars->world_map[pars->i][pars->j] == ' ')
				pars->world_map[pars->i][pars->j] = '1';
			pars->j++;
		}
		pars->i++;
	}
}

void		ft_count_sprites(t_parser *pars)
{
	pars->buf_sprite = 0;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{	
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (pars->world_map[pars->i][pars->j] == '2')
				pars->buf_sprite++;
			pars->j++;
		}
		pars->i++;
	}
}