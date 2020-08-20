/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:43:27 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:31:42 by nofloren         ###   ########.fr       */
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
# include "libft.h"

typedef struct	s_parcer
{
	int		i;
	int		j;
	int		size_map;
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
	int		buf_sprite;
	double	*buffer;
	int		size_map;
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

	char	**world_map;
	int		width;
	int		height;
	t_img		*tex_n;
	t_img		*tex_s;
	t_img		*tex_e;
	t_img		*tex_w;
	t_sprite	**sprite;
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
	double	angle;
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

int		main(int ac, char **av);
int		ft_start(t_data *data, t_parser *pars);
void	add_textures(t_data *data, t_parser *pars);
void	add_sprites(t_data *data, t_parser *pars);
void	ft_init_mlx(t_data *data);
void	ft_error(int i);
void		ft_make_world_map(t_parser *pars, char **argv);
void		parser1(t_parser *pars);
void		ft_free(t_list **map);
char	**make_map(t_list **map, int size);
void	ft_change_space(t_parser *pars);
void			init_data(t_data *data, t_parser *pars);
void		ft_count_sprites(t_parser *pars);
void		ft_add_player(t_parser *pars);
void		ft_add_player_coordinates(t_parser *pars, char c);
int			ft_check_player_map(char c);
void		ft_check_map_side(t_parser *pars);
void		ft_check_space(t_parser *pars, int num_str, int len_str);
int			not_space(char c);
void		ft_check_map(t_parser *pars);
void		gave_space1(t_parser *pars);
int			ft_check_map_line(char c);
char	*ft_addchars(char *line, char c, int count);
int			ft_check_flag(t_parser *pars);
void		parser_2(t_parser *pars);
void		ft_floor_or_roof(t_parser *pars, char c);
void		ft_get_color(t_parser *pars, int *r, int *g, int *b);
int		create_trgb(int t, int r, int g, int b);
void		ft_sprite(t_parser *pars);
void		ft_e(t_parser *pars);
void		ft_w(t_parser *pars);
void		ft_s(t_parser *pars);
void		ft_n(t_parser *pars);
void		ft_r(t_parser *pars);
void	init_flag(t_parser *pars);
void	ft_error(int i);
void	ft_putstr(char *str);
int	is_flag(char c);


# endif