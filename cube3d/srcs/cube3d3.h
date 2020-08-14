/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:43:27 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/14 18:18:18 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define mapWidth 24
# define mapHeight 24

int world_map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
# define buffer_size 640
# define n 3
int		width = 640;
int		height = 480;

double	buffer[buffer_size];

//int	n = 3;

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;


typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		b_p_p;
	int		l_l;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
	double	pos;
}				t_img;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	sprite_dist;
	t_img	*ptr;
}				t_sprite;

typedef struct	s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		b_p_p;
	int		l_l;
	int		endian;
	int		x;

	unsigned int		color;
	int		color_roof;
	int		color_floor;
	int		pos;
	char	*pos2;

	t_img		*tex_n;
	t_img		*tex_s;
	t_img		*tex_e;
	t_img		*tex_w;
	t_sprite	*sprite[n];
	int			i;



	double	sprite_dir;
	int		w_offset;
	int		h_offset;
	int 	sprite_screen_size;

	double	c;
	double	cx;
	double	cy;
	double	player_x;
	double	player_y;
	double	player_a;
	double	fov;
	float	angle;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	perp_wall_dist;
	int		speed;
	double	hitx;
	double	hity;
	double	delta_x;
	double	delta_y;
	int		side;
	double	delta_line_h;
}				t_data;

int	main(int ac, char **av);

# endif
