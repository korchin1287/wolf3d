#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_parcer
{
	int		i;
	int		j;
	int		size_map;
	int		width;
	int		height;
	int		color_floor;
	int		color_roof;
	int		is_player;
	int		buf_sprite;
	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	char	**str;
	char	**world_map;
	char	*tex_n;
	char	*tex_s;
	char	*tex_e;
	char	*tex_w;
	char	*sprite;
	double	player_y;
	double	player_x;
	double	player_a;
}				t_parser;

typedef struct	s_img
{
	int		b_p_p;
	int		l_l;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
	void	*img;
	char	*addr;
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
	int				buf_sprite;
	int				size_map;
	int				b_p_p;
	int				l_l;
	int				endian;
	int				x;
	int				color_roof;
	int				color_floor;
	int				pos;
	int				width;
	int				height;
	int				i;
	int				w_offset;
	int				h_offset;
	int				sprite_screen_size;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				speed;
	int				side;
	unsigned int	color;
	void			*img;
	void			*mlx;
	void			*win;
	char			*addr;
	char			*pos2;
	char			**world_map;
	double			*buffer;
	double			sprite_dir;
	double			c;
	double			cx;
	double			cy;
	double			player_x;
	double			player_y;
	double			player_a;
	double			fov;
	double			angle;
	double			perp_wall_dist;
	double			hitx;
	double			hity;
	double			delta_x;
	double			delta_y;
	double			delta_line_h;
	t_img			*tex_n;
	t_img			*tex_s;
	t_img			*tex_e;
	t_img			*tex_w;
	t_sprite		**sprite;
}				t_data;

void			create_bmp(t_data *data);
int				main(int ac, char **av);
int				get_t(int trgb);
int				ft_key(int key, t_data *data);
int				ft_check_player_map(char c);
int				not_space(char c);
int				is_flag(char c);
int				ft_check_map_line(char c);
int				ft_check_flag(t_parser *pars);
int				create_trgb(int t, int r, int g, int b);
int				ft_close(t_data	*data);
int				move_help(char c);
int				ft_check_argum(char *s1);
int				get_t(int trgb);
char			*ft_addchars(char *line, char c, int count);
char			**make_map(t_list **map, int size);
void			ft_check_size(t_data *data);
void			ft_check_end(t_parser *pars);
void			ft_start(t_data *data, t_parser *pars, int argc, char **argv);
void			add_textures(t_data *data, t_parser *pars);
void			add_sprites(t_data *data, t_parser *pars);
void			ft_init_mlx(t_data *data, t_parser *pars);
void			ft_error(int i);
void			ft_make_world_map(t_parser *pars, char **argv);
void			parser1(t_parser *pars);
void			ft_free(t_list **map);
void			ft_change_space(t_parser *pars);
void			init_data(t_data *data, t_parser *pars);
void			ft_count_sprites(t_parser *pars);
void			ft_add_player(t_parser *pars);
void			ft_add_player_coordinates(t_parser *pars, char c);
void			ft_check_map_side(t_parser *pars);
void			ft_check_space(t_parser *pars, int num_str, int len_str);
void			ft_check_map(t_parser *pars);
void			gave_space1(t_parser *pars);
void			parser_2(t_parser *pars);
void			ft_floor_or_roof(t_parser *pars, char c);
void			ft_get_color(t_parser *pars, int *r, int *g, int *b);
void			ft_sprite(t_parser *pars);
void			ft_e(t_parser *pars);
void			ft_w(t_parser *pars);
void			ft_s(t_parser *pars);
void			ft_n(t_parser *pars);
void			ft_r(t_parser *pars);
void			init_flag(t_parser *pars);
void			ft_error(int i);
void			ft_putstr(char *str);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			paint_floor(t_data *data, int i);
void			paint_roof(t_data *data, int i);
void			ver_line_n(t_data *data);
void			ver_line_s(t_data *data);
void			ver_line_e(t_data *data);
void			ver_line_w(t_data *data);
void			casting1(t_data *data);
void			casting2(t_data *data);
void			casting2_n(t_data *data);
void			casting2_s(t_data *data);
void			casting2_e(t_data *data);
void			casting2_w(t_data *data);
void			ft_side_wall(t_data *data);
void			paint_sprite_help(t_data *data, int *i, int *j);
void			paint_sprite(t_data *data);
void			make_sprites(t_data *data);
void			add_and_sort_sprite(t_data *data);
void			ray_casting(t_data *data);
void			ft_move_front(t_data *data);
void			ft_move_back(t_data *data);
void			ft_move_left(t_data *data);
void			ft_move_right(t_data *data);
void			ft_move(t_data *data, int key);
void			ft_count_coordinate_sprites(t_data *data);
void			ft_make_sprites(t_data *data);

#endif
