/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:29:10 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/17 18:45:07 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	is_flag(char c)
{
	if (c == 'R' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' || c == 'C' || c == 'O' || c == 'A')
		return (1);
	else
		return (0);
	
}

void	init_flag(t_parser *pars, t_flags *flag)
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
	flag->r = 0;
	flag->no = 0;
	flag->so = 0;
	flag->we = 0;
	flag->ea = 0;
	flag->s = 0;
	flag->f = 0;
	flag->c = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
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

void		ft_r(t_parser *pars, t_flags *flag)
{
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	pars->width = ft_atoi(&pars->str[pars->i][pars->j]);
	while (ft_isdigit(pars->str[pars->i][pars->j]))
		pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	pars->height = ft_atoi(&pars->str[pars->i][pars->j]);
	if (pars->width > 0 &&	pars->height > 0)
		flag->r++;
	else
		perror("Error, an incorrect value for the height or width");
	printf("%d\n", pars->width);
	printf("%d\n", pars->height);
}

void		ft_n(t_parser *pars, t_flags *flag)
{
	int j;
	char s;

	flag->no++;
	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
	{
		s = pars->str[pars->i][pars->j + j];
		j++;
	}
	pars->tex_n = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->tex_n, &(pars->str[pars->i][pars->j]), j);
	printf("%s\n", pars->tex_n);
}

void		ft_s(t_parser *pars, t_flags *flag)
{
	int j;
	char s;

	flag->so++;
	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
	{
		s = pars->str[pars->i][pars->j + j];
		j++;
	}
	pars->tex_s = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->tex_s, &(pars->str[pars->i][pars->j]), j);
	printf("%s\n", pars->tex_s);
}

void		ft_w(t_parser *pars, t_flags *flag)
{
	int j;
	char s;

	flag->we++;
	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
	{
		s = pars->str[pars->i][pars->j + j];
		j++;
	}
	pars->tex_w = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->tex_w, &(pars->str[pars->i][pars->j]), j);
	printf("%s\n", pars->tex_w);
}

void		ft_e(t_parser *pars, t_flags *flag)
{
	int j;
	char s;

	flag->ea++;
	pars->j += 2;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
	{
		s = pars->str[pars->i][pars->j + j];
		j++;
	}
	pars->tex_e = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->tex_e, &(pars->str[pars->i][pars->j]), j);
	printf("%s\n", pars->tex_e);
}

void		ft_sprite(t_parser *pars, t_flags *flag)
{
	int j;
	char s;

	flag->s++;
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	j = 0;
	while ((pars->str[pars->i][pars->j + j] != ' ') && (pars->str[pars->i][pars->j + j] != '\0'))
	{
		s = pars->str[pars->i][pars->j + j];
		j++;
	}
	pars->sprite = malloc(sizeof(char) * (j + 1));
	ft_strlcpy(pars->sprite, &(pars->str[pars->i][pars->j]), j);
	printf("%s\n", pars->sprite);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void		ft_floor(t_parser *pars, t_flags *flag)
{
	int r;
	int	g;
	int	b;

	flag->f++;
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	if (ft_isdigit(pars->str[pars->i][pars->j]))
	{
		r = atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		g = atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		b = atoi(&pars->str[pars->i][pars->j]);
	}
	pars->color_floor = create_trgb(0, r, g, b);
	printf("%d\n", pars->color_floor);
}

void		ft_roof(t_parser *pars, t_flags *flag)
{
	int r;
	int	g;
	int	b;

	flag->c++;
	pars->j++;
	while (pars->str[pars->i][pars->j] == ' ')
		pars->j++;
	if (ft_isdigit(pars->str[pars->i][pars->j]))
	{
		r = atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		g = atoi(&pars->str[pars->i][pars->j]);
		while (pars->str[pars->i][pars->j] != ',')
			pars->j++;
		pars->j++;
		b = atoi(&pars->str[pars->i][pars->j]);
	}
	pars->color_roof = create_trgb(0, r, g, b);
	printf("%d\n", pars->color_roof);
}

void		parser_2(t_parser *pars, t_flags *flag)
{
	if (pars->str[pars->i][pars->j] == 'R')
		ft_r(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'N' && pars->str[pars->i][pars->j + 1] == 'O')
		ft_n(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'S' && pars->str[pars->i][pars->j + 1] == 'O')
		ft_s(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'W' && pars->str[pars->i][pars->j + 1] == 'E')
		ft_w(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'E' && pars->str[pars->i][pars->j + 1] == 'A')
		ft_e(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'S' && pars->str[pars->i][pars->j + 1] == ' ')
		ft_sprite(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'F')
		ft_floor(pars, flag);
	else if (pars->str[pars->i][pars->j] == 'C')
		ft_roof(pars, flag);
}

int			ft_check_flag(t_flags *flag)
{
	if (flag->r == 1 && flag->no == 1 && flag->so == 1 && flag->we == 1 && flag->ea == 1 && flag->s == 1 && flag->f == 1 && flag->c == 1)
		return (1);
	else
		return (0);
}

void		parser1(t_parser *pars)
{
	t_flags *flag;

	flag = malloc(sizeof(t_flags));
	init_flag(pars, flag);
	pars->i = 0;
	while (pars->str[pars->i] && !(ft_check_flag(flag)))
	{
		pars->j = 0;
		while (pars->str[pars->i][pars->j])
		{
			if (pars->str[pars->i][pars->j] == ' ')
				(pars->j)++;
			else if (is_flag(pars->str[pars->i][pars->j]))
				parser_2(pars, flag);
			break ;		
		}
		(pars->i)++;
	}
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
	int	x;
	int j;

	i = 0;
	x = 0;
	while (pars->world_map[i])
	{
		if (ft_strlen(pars->world_map[i]) > x)
			x = ft_strlen(pars->world_map[i]);
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
				perror("Map is invalid\n");
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
		perror("You map is shit");
		exit(0);
	}
}

void		ft_check_map_side(t_parser *pars)
{
	int len_str;
	int	num_str;

	pars->i = 0;
	len_str = ft_strlen(pars->world_map[0]);
	while (pars->world_map[pars->i])
	{
		pars->i++;
	}
	num_str = pars->i;
	pars->i = 0;
	while (pars->world_map[pars->i])
	{
		pars->j = 0;
		while (pars->world_map[pars->i][pars->j] != '\0')
		{
			if (pars->world_map[pars->i][pars->j] != '1' && pars->world_map[pars->i][pars->j] != ' ')
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
		perror("Error in the player position");
}

void		ft_add_sprites(t_parser *pars)
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

int			main(int argc, char **argv)
{
	char *s;
	int		fd;
	char	*line;
	t_list	*map;
	t_parser	*pars;

	pars = malloc(sizeof(t_parser));
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	map = NULL;
		
	while (get_next_line(fd, &line))
		ft_lstadd_back(&map, ft_lstnew(line));
	ft_lstadd_back(&map, ft_lstnew(line));
	close(fd);
	pars->str = make_map(&map, ft_lstsize(map));
	parser1(pars);
	while (pars->str[pars->i][0] == '\0')
		(pars->i)++;
	int i = 0;
	i = 0;
	pars->world_map = malloc(sizeof(char*) * ((ft_lstsize(map) - pars->i) + 1));
	while (pars->str[pars->i])
	{
		pars->world_map[i] = ft_strdup(pars->str[pars->i]);
		i++;
		pars->i++;
	}
	gave_space1(pars);
	ft_check_map(pars);
	ft_check_map_side(pars);
	ft_add_player(pars);
	ft_add_sprites(pars);

		
	return (0);
}