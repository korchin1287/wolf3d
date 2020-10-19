#include "cube3d.h"

void	ft_get_color_help(t_parser *pars, int **r, int **g, int **b)
{
	if ((pars->str[pars->i][pars->j] >= '0') && (pars->str[pars->i][pars->j]
			<= '9'))
		**b = ft_atoi(&pars->str[pars->i][pars->j]);
	while (pars->str[pars->i][pars->j] != ' ' && pars->str[pars->i][pars->j]
			!= '\0')
		pars->j++;
	ft_check_end(pars);
	if ((**g > 255 || **g < 0) || (**r > 255 || **r < 0) || (**b > 255 ||
		**b < 0))
		ft_error(3);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_get_color(t_parser *pars, int *r, int *g, int *b)
{
	if (ft_isdigit(pars->str[pars->i][pars->j]))
	{
		if ((pars->str[pars->i][pars->j] >= '0') && (pars->str[pars->i][pars->j]
			<= '9'))
			*r = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',' && pars->str[pars->i][pars->j]
			!= '\0')
			pars->j++;
		pars->j++;
		if ((pars->str[pars->i][pars->j] >= '0') && (pars->str[pars->i][pars->j]
			<= '9'))
			*g = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',' && pars->str[pars->i][pars->j]
			!= '\0')
			pars->j++;
		pars->j++;
		ft_get_color_help(pars, &r, &g, &b);
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
	while (j > 0)
	{
		j--;
		pars->j++;
	}
	ft_check_end(pars);
}
