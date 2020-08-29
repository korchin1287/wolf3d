/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:35:22 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/29 17:06:42 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_e(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i]
		[pars->j + j] != '\0'))
		j++;
	if (!(pars->tex_e = malloc(sizeof(char) * (j + 1))))
		ft_error(7);
	if ((ft_strlcpy(pars->tex_e, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->ea++;
	while (j > 0)
	{
		j--;
		pars->j++;
	}
	ft_check_end(pars);
}

void		ft_w(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i]
		[pars->j + j] != '\0'))
		j++;
	if (!(pars->tex_w = malloc(sizeof(char) * (j + 1))))
		ft_error(7);
	if ((ft_strlcpy(pars->tex_w, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->we++;
	while (j > 0)
	{
		j--;
		pars->j++;
	}
	ft_check_end(pars);
}

void		ft_s(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i]
		[pars->j + j] != '\0'))
		j++;
	if (!(pars->tex_s = malloc(sizeof(char) * (j + 1))))
		ft_error(7);
	if ((ft_strlcpy(pars->tex_s, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->so++;
	while (j > 0)
	{
		j--;
		pars->j++;
	}
	ft_check_end(pars);
}

void		ft_n(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i]
		[pars->j + j] != '\0'))
		j++;
	if (!(pars->tex_n = malloc(sizeof(char) * (j + 1))))
		ft_error(7);
	if ((ft_strlcpy(pars->tex_n, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->no++;
	while (j > 0)
	{
		j--;
		pars->j++;
	}
	ft_check_end(pars);
}

void		ft_r(t_parser *pars)
{
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ' && pars->str[pars->i]
		[pars->j] != '\0')
		pars->j++;
	pars->width = ft_atoi(&pars->str[pars->i][pars->j]);
	while (ft_isdigit(pars->str[pars->i][pars->j]))
		pars->j++;
	while (pars->str[pars->i][pars->j] == ' ' && pars->str[pars->i]
		[pars->j] != '\0')
		pars->j++;
	pars->height = ft_atoi(&pars->str[pars->i][pars->j]);
	while (ft_isdigit(pars->str[pars->i][pars->j]))
		pars->j++;
	ft_check_end(pars);
	if (pars->width > 0 && pars->height > 0)
		pars->r++;
	else
		ft_error(1);
}
