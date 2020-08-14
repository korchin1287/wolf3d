#include <mlx.h>
#include <stdio.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int             ft_close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);	
	if (keycode == 53)	
	   	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_key_hook(vars.win, ft_close, &vars);
    mlx_loop(vars.mlx);
} 
