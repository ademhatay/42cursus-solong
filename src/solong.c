#include "solong.h"

int	main(int ac, char **av)
{
	int	fd;
	int	map_c;

	if (ac != 2)
	{
		ft_putendl("Haritayı Belirtin");
		return (0);
	}
	map_c = ft_av_control(av[1], "reb");
	if (map_c == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_map(fd);
	return (EXIT_SUCCESS);
}
