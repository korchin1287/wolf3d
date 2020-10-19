#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	j = 0;
	i = 0;
	if (!dst)
		return (NULL);
	while (s1[j] != '\0')
	{
		dst[i + j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		dst[i + j] = s2[i];
		i++;
	}
	dst[i + j] = '\0';
	return (dst);
}
