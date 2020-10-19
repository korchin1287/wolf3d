#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int rez;
	int k;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	k = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -k;
		i++;
	}
	rez = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		rez = rez * 10 + (str[i] - '0');
		i++;
	}
	return (rez * k);
}
