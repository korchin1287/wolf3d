#include "cube3d.h"

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

void	ft_count_sprites(t_parser *pars)
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

int		ft_check_player_map(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	ft_add_player_coordinates(t_parser *pars, char c)
{
	pars->player_y = (double)pars->i + 0.5;
	pars->player_x = (double)pars->j + 0.5;
	if (c == 'N')
		pars->player_a = -M_PI_2;
	if (c == 'S')
		pars->player_a = M_PI_2;
	if (c == 'E')
		pars->player_a = 0;
	if (c == 'W')
		pars->player_a = M_PI;
	pars->is_player++;
}

void	ft_add_player(t_parser *pars)
{
	pars->is_player = 0;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (ft_check_player_map(pars->world_map[pars->i][pars->j]))
				ft_add_player_coordinates(pars,
				pars->world_map[pars->i][pars->j]);
			pars->j++;
		}
		pars->i++;
	}
	if (pars->is_player != 1)
		ft_error(2);
	ft_count_sprites(pars);
	ft_change_space(pars);
}
