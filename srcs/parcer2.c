#include "cube3d.h"

int		ft_check_flag(t_parser *pars)
{
	if (pars->r == 1 && pars->no == 1 && pars->so == 1 && pars->we == 1 &&
		pars->ea == 1 && pars->s == 1 && pars->f == 1 && pars->c == 1)
		return (1);
	else
		return (0);
}

int		is_flag(char c)
{
	if (c == 'R' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' ||
		c == 'C' || c == 'O' || c == 'A')
		return (1);
	else
		return (0);
}

void	init_flag(t_parser *pars)
{
	pars->width = 0;
	pars->height = 0;
	pars->tex_n = NULL;
	pars->tex_s = NULL;
	pars->tex_e = NULL;
	pars->tex_w = NULL;
	pars->sprite = NULL;
	pars->color_floor = 0;
	pars->color_roof = 0;
	pars->r = 0;
	pars->no = 0;
	pars->so = 0;
	pars->we = 0;
	pars->ea = 0;
	pars->s = 0;
	pars->f = 0;
	pars->c = 0;
}

void	parser_2(t_parser *pars)
{
	if (pars->str[pars->i][pars->j] == 'R')
		ft_r(pars);
	else if (pars->str[pars->i][pars->j] == 'N' && pars->str[pars->i]
		[pars->j + 1] == 'O')
		ft_n(pars);
	else if (pars->str[pars->i][pars->j] == 'S' && pars->str[pars->i]
		[pars->j + 1] == 'O')
		ft_s(pars);
	else if (pars->str[pars->i][pars->j] == 'W' && pars->str[pars->i]
		[pars->j + 1] == 'E')
		ft_w(pars);
	else if (pars->str[pars->i][pars->j] == 'E' && pars->str[pars->i]
		[pars->j + 1] == 'A')
		ft_e(pars);
	else if (pars->str[pars->i][pars->j] == 'S' && pars->str[pars->i]
		[pars->j + 1] == ' ')
		ft_sprite(pars);
	else if ((pars->str[pars->i][pars->j] == 'F' && pars->str[pars->i]
		[pars->j + 1] == ' ') || (pars->str[pars->i][pars->j] == 'C' &&
		pars->str[pars->i][pars->j + 1] == ' '))
		ft_floor_or_roof(pars, pars->str[pars->i][pars->j]);
}

void	parser1(t_parser *pars)
{
	init_flag(pars);
	pars->i = 0;
	while (pars->str[pars->i])
	{
		pars->j = 0;
		while (pars->str[pars->i][pars->j] != '\0')
		{
			if (pars->str[pars->i][pars->j] == ' ')
				(pars->j)++;
			if (is_flag(pars->str[pars->i][pars->j]))
				parser_2(pars);
			else if (!(is_flag(pars->str[pars->i][pars->j]) &&
						!(ft_check_flag(pars))))
				ft_error(4);
			break ;
		}
		(pars->i)++;
		if (ft_check_flag(pars))
			break ;
	}
	if (!(ft_check_flag(pars)))
		ft_error(4);
}
