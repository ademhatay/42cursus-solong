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
		free_exit(var, "Oyun (ESC) ile Kapatıldı\n");
	else
	{
		movements(key, var);
	}
	if (init_steps != var->game.count_steps)
	{
		ft_putstr("Steps: ");
		ft_putnbr(var->game.count_steps);
		ft_putchar('\n');
	}
	write_map(*var);
	return (0);
}
