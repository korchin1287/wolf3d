/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer1_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:11:36 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:13:21 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

void		ft_e(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_e = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_e, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->ea++;
}

void		ft_w(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_w = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_w, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->we++;
}

void		ft_s(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_s = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_s, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->so++;
}

void		ft_n(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_n = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_n, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->no++;
}

void		ft_r(t_parser *pars)
{
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ' && pars->str[pars->i][pars->j] != '\0')
		pars->j++;
	pars->width = ft_atoi(&pars->str[pars->i][pars->j]);
	while (ft_isdigit(pars->str[pars->i][pars->j]))
		pars->j++;
	while (pars->str[pars->i][pars->j] == ' ' && pars->str[pars->i][pars->j] != '\0')
		pars->j++;
	pars->height = ft_atoi(&pars->str[pars->i][pars->j]);
	if (pars->width > 0 &&	pars->height > 0)
		pars->r++;
	else
		ft_error(1);
	if (pars->width % 2 == 1)
		pars->width -= 1;
	if (pars->height % 2 == 1)
		pars->height -= 1;
	if (pars->width > 2500)
		pars->width = 2500;
	if (pars->height > 1300)
		pars->height = 1300;
}