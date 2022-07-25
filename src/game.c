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
		ft_putendl("Helal YUSUFİ!!! Kazandın!!!");
		exit(0);
	}
	else
		ft_putendl("Hala toplanmamış altın var!!!");
	return (0);
}
