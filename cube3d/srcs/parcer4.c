/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:40:12 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/26 14:23:05 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_get_color(t_parser *pars, int *r, int *g, int *b)
{
	if (ft_isdigit(pars->str[pars->i][pars->j]))
	{
		*r = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',' && pars->str[pars->i]
			[pars->j] != '\0')
			pars->j++;
		pars->j++;
		*g = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',' && pars->str[pars->i]
			[pars->j] != '\0')
			pars->j++;
		pars->j++;
		*b = ft_atoi(&pars->str[pars->i][pars->j]);
		if ((*g > 255 || *g < 0) || (*r > 255 || *r < 0) || (*b > 255 ||
			*b < 0))
			ft_error(3);
	}
	else
		ft_error(4);
}

void	ft_floor_or_roof(t_parser *pars, char c)
{
	int r;
	int	g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	ft_get_color(pars, &r, &g, &b);
	if (c == 'F')
	{
		pars->color_floor = create_trgb(0, r, g, b);
		pars->f++;
	}
	if (c == 'C')
	{
		pars->color_roof = create_trgb(0, r, g, b);
		pars->c++;
	}
	if (r < 0 || g < 0 || b < 0)
		ft_error(4);
}

void	ft_sprite(t_parser *pars)
{
	int j;

	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i]
		[pars->j + j] != '\0'))
		j++;
	if (!(pars->sprite = malloc(sizeof(char) * (j + 1))))
		ft_error(7);
	ft_strlcpy(pars->sprite, &(pars->str[pars->i][pars->j]), j + 1);
	if (ft_isascii(pars->sprite[0]))
		pars->s++;
}
