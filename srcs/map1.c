/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:45:29 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/26 16:59:32 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_check_map_line(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2' ||
		c == ' ' || c == '1')
		return (1);
	else
		return (0);
}

void	ft_check_map(t_parser *pars)
{
	int			i;
	int			j;

	i = 0;
	while (pars->world_map[i])
	{
		j = 0;
		while (pars->world_map[i][j] != '\0')
		{
			if (!(ft_check_map_line(pars->world_map[i][j])))
				ft_error(6);
			j++;
		}
		i++;
	}
}

char	*ft_addchars(char *line, char c, int count)
{
	char		*tmp;
	int			len;

	while (count > 0)
	{
		len = ft_strlen(line);
		tmp = line;
		if (!(line = (char*)malloc(len + 2)))
			ft_error(7);
		ft_memcpy(line, tmp, len);
		line[len] = c;
		line[len + 1] = '\0';
		free(tmp);
		count--;
	}
	return (line);
}

void	gave_space1(t_parser *pars)
{
	int			i;
	int			j;
	int			x;

	i = 0;
	x = 0;
	while (pars->world_map[i])
	{
		j = 0;
		while (pars->world_map[i][j] != '\0')
			j++;
		if (j > x)
			x = j;
		i++;
	}
	i = 0;
	x++;
	while (pars->world_map[i])
	{
		pars->world_map[i] = ft_addchars(pars->world_map[i], ' ',
			(x - ft_strlen(pars->world_map[i])));
		i++;
	}
	ft_check_map(pars);
}
