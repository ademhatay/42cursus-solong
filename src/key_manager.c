#include "solong.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "Oyun (X) ile Kapatıldı");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
	{
		free_exit(var, "Oyun (ESC) ile Kapatıldı\n");
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
