/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer1_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:13:31 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:21:53 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void		ft_get_color(t_parser *pars, int *r, int *g, int *b)
{
	if (ft_isdigit(pars->str[pars->i][pars->j]))
	{
		*r = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		*g = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		*b = ft_atoi(&pars->str[pars->i][pars->j]);
		if ((*g > 255 || *g < 0) || (*r > 255 || *r < 0) || (*b > 255 || *b < 0))
			ft_error(3);
	}
	else
		ft_error(4);
}

void		ft_floor_or_roof(t_parser *pars, char c)
{
	int r;
	int	g;
	int	b;

	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	ft_get_color(pars, &r, &g, &b);
	if (c == 'F')
	{
		pars->color_floor = create_trgb(0, r, g, b);
		if (pars->color_floor >= 0)
			pars->f++;
	}
	else
	{
		pars->color_roof = create_trgb(0, r, g, b);
		if (pars->color_roof > 0)
			pars->c++;
	}
}

void		ft_sprite(t_parser *pars)
{
	int j;

	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->sprite = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->sprite, &(pars->str[pars->i][pars->j]), j + 1);
	if (ft_isascii(pars->sprite[0]))
		pars->s++;
}