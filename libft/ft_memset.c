/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:30:21 by nofloren          #+#    #+#             */
/*   Updated: 2020/04/30 01:24:50 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*p;

	p = (char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (b);
}
