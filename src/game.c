#include "solong.h"

int	get_init_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.y)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'P')
			{
				var->img.pos.x = col;
				var->img.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	count_collec(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	var->game.count_collec = 0;
	while (row < var->map.size.y)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'C')
				var->game.count_collec++;
			col++;
		}
		row++;
	}
	return (var->game.count_collec);
}

int	check_collect(t_var *var)
{
	if (count_collec(var) == 0)
	{
		ft_putendl("\e[34m\e[1mCONGRATS\n!!!! You WON !!!!\e[0m\n");
		exit(0);
	}
	else
		printf("\e[35m\e[1mPlease, collect all diamonds!!!\e[0m\n");
	return (0);
}
