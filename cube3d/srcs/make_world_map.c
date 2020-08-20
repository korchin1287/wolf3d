/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_world_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:59:34 by nofloren          #+#    #+#             */
/*   Updated: 2020/08/20 20:08:48 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d3.h"

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