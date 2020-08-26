/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:29:10 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/26 19:09:20 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("Error\nAn incorrect value for the height or width");
	if (i == 2)
		ft_putstr("Error\nIn the player position");
	if (i == 3)
		ft_putstr("Error\nIn the color value");
	if (i == 4)
		ft_putstr("Error\nYou made a mistake in your input data");
	if (i == 5)
		ft_putstr("Error\nInvalid link at the sprite or texture");
	if (i == 6)
		ft_putstr("Error\nMap is invalid");
	if (i == 7)
		ft_putstr("Error\nMalloc error!");
	if (i == 8)
		ft_putstr("Error\nCannot open file\n");
	if (i == 9)
		ft_putstr("Error\nNot identificate argum\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_parser	*pars;
	t_data		*data;

	if (argc > 1)
	{
		if (!(ft_strncmp(".cub", ft_strchr(argv[1], '\0') - 4, 5)))
		{	
			if (!(data = malloc(sizeof(t_data))))
				ft_error(7);
			if (!(pars = malloc(sizeof(t_parser))))
				ft_error(7);
			ft_make_world_map(pars, argv);
			gave_space1(pars);
			ft_check_map_side(pars);
			ft_init_mlx(data, pars);
			ft_start(data, pars, argc, argv);
		}
		else
			ft_error(9);		
	}
	else
		ft_error(9);	
	return (0);
}
