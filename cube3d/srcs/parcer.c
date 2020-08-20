/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:29:10 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:37:39 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

int	is_flag(char c)
{
	if (c == 'R' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' || c == 'C' || c == 'O' || c == 'A')
		return (1);
	else
		return (0);
	
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1 , "\n", 1);
}

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("Error, an incorrect value for the height or width");
	if (i == 2)
		ft_putstr("Error in the player position");
	if (i == 3)
		ft_putstr("Error in the color value");
	if (i == 4)
		ft_putstr("Error, you made a mistake in your input data");
	if (i == 5)
		ft_putstr("Invalid link at the sprite or texture");
	if (i == 6)
		ft_putstr("Map is invalid");
	exit(0);
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

char	**make_map(t_list **map, int size)
{
	char	**str;
	int		i;
	t_list	*tmp;

	str = malloc(sizeof(char *) * (size + 1));
	i = 0;
	tmp = *map;
	while (tmp)
	{
		str[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	str[i] = NULL;
	return (str);

}

void		ft_r(t_parser *pars)
{
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ' && pars->str[pars->i][pars->j] != '\0')
		pars->j++;
	pars->width = ft_atoi(&pars->str[pars->i][pars->j]);
	while (ft_isdigit(pars->str[pars->i][pars->j]))
		pars->j++;
	while (pars->str[pars->i][pars->j] == ' ' && pars->str[pars->i][pars->j] != '\0')
		pars->j++;
	pars->height = ft_atoi(&pars->str[pars->i][pars->j]);
	if (pars->width > 0 &&	pars->height > 0)
		pars->r++;
	else
		ft_error(1);
	if (pars->width % 2 == 1)
		pars->width -= 1;
	if (pars->height % 2 == 1)
		pars->height -= 1;
	if (pars->width > 2500)
		pars->width = 2500;
	if (pars->height > 1300)
		pars->height = 1300;
}

void		ft_n(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_n = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_n, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->no++;
}

void		ft_s(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_s = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_s, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->so++;
}

void		ft_w(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_w = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_w, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->we++;
}

void		ft_e(t_parser *pars)
{
	int j;

	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->tex_e = malloc(sizeof(char) * (j + 1));
	if ((ft_strlcpy(pars->tex_e, &(pars->str[pars->i][pars->j]), j + 1)) > 0)
		pars->ea++;
}

void		ft_sprite(t_parser *pars)
{
	int j;

	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
		j++;
	pars->sprite = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->sprite, &(pars->str[pars->i][pars->j]), j + 1);
	if (ft_isascii(pars->sprite[0]))
		pars->s++;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void		ft_get_color(t_parser *pars, int *r, int *g, int *b)
{
	if (ft_isdigit(pars->str[pars->i][pars->j]))
	{
		*r = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		*g = ft_atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		*b = ft_atoi(&pars->str[pars->i][pars->j]);
		if ((*g > 255 || *g < 0) || (*r > 255 || *r < 0) || (*b > 255 || *b < 0))
			ft_error(3);
	}
	else
		ft_error(4);
}

void		ft_floor_or_roof(t_parser *pars, char c)
{
	int r;
	int	g;
	int	b;

	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	ft_get_color(pars, &r, &g, &b);
	if (c == 'F')
	{
		pars->color_floor = create_trgb(0, r, g, b);
		if (pars->color_floor >= 0)
			pars->f++;
	}
	else
	{
		pars->color_roof = create_trgb(0, r, g, b);
		if (pars->color_roof > 0)
			pars->c++;
	}
	
}

void		parser_2(t_parser *pars)
{
	if (pars->str[pars->i][pars->j] == 'R')
		ft_r(pars);
	else if (pars->str[pars->i][pars->j] == 'N' && pars->str[pars->i][pars->j + 1] == 'O')
		ft_n(pars);
	else if (pars->str[pars->i][pars->j] == 'S' && pars->str[pars->i][pars->j + 1] == 'O')
		ft_s(pars);
	else if (pars->str[pars->i][pars->j] == 'W' && pars->str[pars->i][pars->j + 1] == 'E')
		ft_w(pars);
	else if (pars->str[pars->i][pars->j] == 'E' && pars->str[pars->i][pars->j + 1] == 'A')
		ft_e(pars);
	else if (pars->str[pars->i][pars->j] == 'S' && pars->str[pars->i][pars->j + 1] == ' ')
		ft_sprite(pars);
	else if (pars->str[pars->i][pars->j] == 'F' || pars->str[pars->i][pars->j] == 'C')
		ft_floor_or_roof(pars, pars->str[pars->i][pars->j]);
}

int			ft_check_flag(t_parser *pars)
{
	if (pars->r == 1 && pars->no == 1 && pars->so == 1 && pars->we == 1 && pars->ea == 1 && pars->s == 1 && pars->f == 1 && pars->c == 1)
		return (1);
	else
		return (0);
}

void		parser1(t_parser *pars)
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
			else if (is_flag(pars->str[pars->i][pars->j]))
				parser_2(pars);
			break ;		
		}
		(pars->i)++;
		if (ft_check_flag(pars))
			break ;
	}
	if (!(ft_check_flag(pars)))
		ft_error(4);
}

char	*ft_addchars(char *line, char c, int count)
{
	char	*tmp;
	int		len;
	
	while (count > 0)
	{
		len = ft_strlen(line);
		tmp = line;
		line = (char*)malloc(len + 2);
		ft_memcpy(line, tmp, len);
		line[len] = c;
		line[len + 1] = '\0';
		free(tmp);
		count--;
	}
	return (line);
}

int			ft_check_map_line(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2' || c == ' ' || c == '1')
		return (1);
	else
		return (0);
}

void		gave_space1(t_parser *pars)
{
	int	i;
	int j;
	int	x;

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
	while (pars->world_map[i])
	{
		pars->world_map[i] = ft_addchars(pars->world_map[i], ' ', (x - ft_strlen(pars->world_map[i])));
		i++;
	}
}

void		ft_check_map(t_parser *pars)
{
	int i;
	int j;

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

int			not_space(char c)
{
	if (c != ' ')
		return (1);
	else
	{
		ft_error(6);
		return (0);
	}
}

void		ft_check_space(t_parser *pars, int num_str, int len_str)
{
	if (pars->j > 0)
		not_space(pars->world_map[pars->i][pars->j - 1]);
	if (pars->j < len_str)
		not_space(pars->world_map[pars->i][pars->j + 1]);
	if (pars->i > 0)
		not_space(pars->world_map[pars->i - 1][pars->j]);
	if (pars->i < num_str)
		not_space(pars->world_map[pars->i + 1][pars->j]);
}

void		ft_check_map_side(t_parser *pars)
{
	int len_str;
	int	num_str;

	pars->i = 0;
	len_str = ft_strlen(pars->world_map[0]);
	while (pars->world_map[pars->i])
		pars->i++;
	num_str = pars->i;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (pars->world_map[pars->i][pars->j] != '1' && pars->world_map[pars->i][pars->j] != ' ')
				ft_check_space(pars, num_str, len_str);
			pars->j++;		
		}
		pars->i++;
	}
}

int			ft_check_player_map(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void		ft_add_player_coordinates(t_parser *pars, char c)
{
	pars->player_y = (double)pars->i + 0.5;
	pars->player_x = (double)pars->j + 0.5;
	if (c == 'N')
		pars->player_a = -M_PI_2;
	if (c == 'S')
		pars->player_a = M_PI_2;
	if (c == 'E')
		pars->player_a = M_PI;
	if (c == 'W')
		pars->player_a = 0;
	pars->is_player++;
	
}	

void		ft_add_player(t_parser *pars)
{
	pars->is_player = 0;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{	
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (ft_check_player_map(pars->world_map[pars->i][pars->j]))
				ft_add_player_coordinates(pars, pars->world_map[pars->i][pars->j]);
			pars->j++;
		}
		pars->i++;
	}
	if (pars->is_player != 1)
		ft_error(2);
}

void		ft_count_sprites(t_parser *pars)
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

void			init_data(t_data *data, t_parser *pars)
{
	data->world_map = pars->world_map;
	data->player_x = pars->player_x;
	data->player_y = pars->player_y;
	data->player_a = pars->player_a;
	data->fov = M_PI / 3;
	data->color_floor = pars->color_floor;
	data->color_roof = pars->color_roof;
	data->speed = 1;
}

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

void		ft_free(t_list **map)
{
	t_list *dst;

	while (*map)
	{
		dst = *map;
		*map = dst->next;
		free(dst);
	}
	*map = NULL;
}

static void		ft_make_world_map_2(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->str[pars->i])
	{
		pars->world_map[i] = ft_strdup(pars->str[pars->i]);
		i++;
		pars->i++;
	}
	pars->world_map[i] = 0;
}

void		ft_make_world_map(t_parser *pars, char **argv)
{
	int		fd;
	char	*line;
	t_list	*map;
	t_list	*dst;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	dst = ft_lstnew(line);
	ft_lstadd_back(&map, dst);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&map, ft_lstnew(line));
	ft_lstadd_back(&map, ft_lstnew(line));
	close(fd);
	pars->str = make_map(&map, ft_lstsize(map));
	parser1(pars);
	while (pars->str[pars->i][0] == '\0')
		(pars->i)++;
	pars->world_map = malloc(sizeof(char*) * ((ft_lstsize(map) - pars->i) + 1));
	ft_free(&dst);
	ft_make_world_map_2(pars);
}

int			main(int argc, char **argv)
{
	t_parser	*pars;
	t_data	*data;

	if (argc > 1)
	{
		data = malloc(sizeof(t_data));
		pars = malloc(sizeof(t_parser));
		ft_make_world_map(pars, argv);
		gave_space1(pars);
		ft_check_map(pars);
		ft_check_map_side(pars);
		ft_add_player(pars);
		ft_count_sprites(pars);
		ft_change_space(pars);
		data->sprite = malloc(sizeof(t_sprite) * pars->buf_sprite);
		data->width = pars->width;
		data->height = pars->height;
		ft_init_mlx(data);
		add_textures(data, pars);
		add_sprites(data, pars);	
		init_data(data, pars);
		ft_start(data, pars);
	}
	return (0);
}