/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:59:14 by ahatay            #+#    #+#             */
/*   Updated: 2022/07/28 13:59:15 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_expose(t_var *var)
{
	write_map(*var);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;

	check_args(ac, av);
	get_map_struct(&var, av);
	check_map(var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * 64,
			var.map.size.y * 64, "So long");
	get_init_position(&var);
	count_collec(&var);
	write_map(var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_expose_hook(var.win, ft_expose, &var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}
