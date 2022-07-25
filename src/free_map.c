#include "solong.h"

int	free_map(t_var *var)
{
	int	row;

	row = 0;
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	while (row < var->map.size.y)
	{
		free(var->map.mtx[row]);
		row++;
	}
	free(var->map.mtx);
	return (0);
}

int	free_exit(t_var *var, char *msg)
{
	printf("%s", msg);
	free_map(var);
	exit(0);
}
