#include "solong.h"

int	main(int ac, char **av)
{
	t_var	var;

	check_args(ac, av);
	get_map_struct(&var, av);
	check_map(var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * 64, var.map.size.y * 64, "So long");
	write_map(var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}
