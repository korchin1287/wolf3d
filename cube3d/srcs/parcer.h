/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:38:18 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/17 18:50:44 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_H
# define PARCER_H
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_parcer
{
	int		i;
	int		j;
	char 	**str;
	int		width;
	int		height;
	char	*tex_n;
	char	*tex_s;
	char	*tex_e;
	char	*tex_w;
	char	*sprite;
	int		color_floor;
	int		color_roof;
	double	player_y;
	double	player_x;
	double	player_a;
	int		is_player;
	int		buf_sprite;
	char	**world_map;
	int	r;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	s;
	int	f;
	int	c;
}				t_parser;

int	main(int argc, char **argv);

# endif