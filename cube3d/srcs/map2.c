/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:04:09 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/26 17:05:44 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		not_space(char c)
{
	if (c != ' ')
		return (1);
	else
	{
		ft_error(6);
		return (0);
	}
}

void	ft_check_space(t_parser *pars, int num_str, int len_str)
{
	if (pars->j == 0)
		ft_error(6);
	if (pars->j == len_str)
		ft_error(6);
	if (pars->i == 0)
		ft_error(6);
	if (pars->i == num_str)
		ft_error(6);
	if (pars->j > 0)
		not_space(pars->world_map[pars->i][pars->j - 1]);
	if (pars->j < len_str)
		not_space(pars->world_map[pars->i][pars->j + 1]);
	if (pars->i > 0)
		not_space(pars->world_map[pars->i - 1][pars->j]);
	if (pars->i < num_str)
		not_space(pars->world_map[pars->i + 1][pars->j]);
}

void	ft_check_map_side(t_parser *pars)
{
	int len_str;
	int	num_str;

	pars->i = 0;
	len_str = ft_strlen(pars->world_map[0]);
	while (pars->world_map[pars->i])
		pars->i++;
	num_str = pars->i - 1;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (pars->world_map[pars->i][pars->j] != '1' &&
				pars->world_map[pars->i][pars->j] != ' ')
				ft_check_space(pars, num_str, len_str);
			pars->j++;
		}
		pars->i++;
	}
	ft_add_player(pars);
}
