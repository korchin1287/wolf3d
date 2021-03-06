#include "cube3d.h"

int			ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void		ft_move(t_data *data, int key)
{
	if (key == 13)
		ft_move_front(data);
	if (key == 1)
		ft_move_back(data);
	if (key == 0)
		ft_move_left(data);
	if (key == 2)
		ft_move_right(data);
	if (key == 123)
		data->player_a -= 4 * M_PI / 90;
	if (key == 124)
		data->player_a += 4 * M_PI / 90;
}

int			ft_key(int key, t_data *data)
{
	if (key == 13 || key == 2 || key == 0 || key == 1 || key == 123 ||
		key == 124)
	{
		ft_move(data, key);
		ray_casting(data);
	}
	else if (key == 53)
		ft_close(data);
	return (0);
}
