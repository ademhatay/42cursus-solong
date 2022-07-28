/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:57:10 by ahatay            #+#    #+#             */
/*   Updated: 2022/07/28 13:57:16 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	free_map(t_var *var)
{
	int	row;

	row = 0;
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	while (row < var->map.size.y)
	{
		free(var->map.mtx[row]);
		row++;
	}
	free(var->map.mtx);
	return (0);
}

int	free_exit(t_var *var, char *msg)
{
	ft_putendl(msg);
	exit(0);
	free_map(var);
}
