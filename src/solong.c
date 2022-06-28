#include "solong.h"

int check_args(int ac, char **av)
{
	int	map_c;

	if (ac != 2)
	{
		ft_putendl("Haritayı Belirtin");
		return (0);
	}
	map_c = ft_av_control(av[1], "reb");
	if (map_c == 0)
		return (0);
	return(1);
}

int	main(int ac, char **av)
{
	if(check_args(ac, av) == 0)
		return(0);
	
	return (EXIT_SUCCESS);
}
