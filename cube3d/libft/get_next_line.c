/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:23:01 by nofloren          #+#    #+#             */
/*   Updated: 2020/06/14 22:09:27 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_check(char *ostatok, char **line)
{
	char			*p;
	int				i;

	p = NULL;
	i = -1;
	if (ostatok)
		if ((p = ft_strchr(ostatok, '\n')))
		{
			*p++ = '\0';
			*line = ft_strdup(ostatok);
			while (p[++i] != '\0')
				ostatok[i] = p[i];
			ostatok[i] = '\0';
		}
		else
		{
			*line = ft_strdup(ostatok);
			while (ostatok[++i] != '\0')
				ostatok[i] = '\0';
		}
	else
		*line = ft_strdup("");
	return (p);
}

static int			ft_get_next_line(int fd, char **line, char **ostatok)
{
	char			buf[BUFFER_SIZE + 1];
	char			*p;
	char			*tmp;
	int				ret;

	ret = 1;
	p = ft_check(*ostatok, line);
	while (!p && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p++ = '\0';
			free(*ostatok);
			*ostatok = ft_strdup(p);
		}
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (!(*line) || ret == -1)
		free(*line);
	return ((ret > 0) ? 1 : ret);
}

static t_list		*ft_lstnew(const int fd)
{
	t_list			*dst;

	if (!(dst = malloc(sizeof(t_list))))
		return (NULL);
	dst->fd = fd;
	dst->content = NULL;
	dst->next = NULL;
	return (dst);
}

static void			ft_list_clear(t_list **begin_list)
{
	t_list *dest;

	while (*begin_list)
	{
		dest = *begin_list;
		*begin_list = (*begin_list)->next;
		free(dest);
	}
}

int					get_next_line(int fd, char **line)
{
	static t_list	*dst;
	t_list			*tmp;
	int				i;

	if (fd < 0)
		return (-1);
	if (dst == NULL)
		dst = ft_lstnew(fd);
	tmp = dst;
	while (tmp->fd != fd)
	{
		if (!tmp->next)
			tmp->next = ft_lstnew(fd);
		tmp = tmp->next;
	}
	i = ft_get_next_line(fd, line, &(tmp->content));
	if (i == 0)
	{
		free(tmp->content);
		tmp->content = NULL;
		ft_list_clear(&dst);
	}
	return (i);
}
