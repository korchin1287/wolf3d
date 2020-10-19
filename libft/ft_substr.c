#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len_s < start)
	{
		if (!(dst = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		dst[i] = '\0';
		return (dst);
	}
	if (!(dst = (char*)malloc(sizeof(char) * ((len_s - start) + 1))))
		return (NULL);
	while (i < len && s[i + start])
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
