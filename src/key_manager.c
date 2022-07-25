#include "solong.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == 37)
	{
		free_exit(var, "\e[33m\e[1mGame closed! (ESC)\e[0m\n");
		exit(0);
	}
	else
	{
		movements(key, var);
	}
	if (init_steps != var->game.count_steps)
		printf("Steps: %d\n", var->game.count_steps);
	write_map(*var);
	return (0);
}
