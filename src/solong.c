#include "solong.h"

int	main(int ac, char **av)
{
	t_var	var;

	if(check_args(ac, av) == 0)
		return(0);
	get_map_struct(&var, av);
	// check_map(&var);

	return (EXIT_SUCCESS);
}
