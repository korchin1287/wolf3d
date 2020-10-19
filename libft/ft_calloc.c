#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	x;
	size_t	i;
	char	*tmp;

	x = num * size;
	tmp = (char*)malloc(x);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < x)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void*)tmp);
}
