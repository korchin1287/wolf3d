#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (len > 0)
		{
			((unsigned char*)dest)[len - 1] = ((unsigned char*)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dest);
}
