#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_d;
	size_t	l_s;

	i = 0;
	l_d = ft_strlen(dst);
	l_s = ft_strlen(src);
	if (size > l_d)
	{
		while (((l_d + i) < size - 1) && src[i] != '\0')
		{
			dst[i + l_d] = src[i];
			i++;
		}
		dst[i + l_d] = '\0';
	}
	if (size <= l_d)
		return (size + l_s);
	return (l_s + l_d);
}
