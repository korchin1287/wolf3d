#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		i = n % 10;
		n = n / 10;
		if (n != 0)
			ft_putnbr_fd(n, fd);
		ft_putchar_fd(i + '0', fd);
	}
}
