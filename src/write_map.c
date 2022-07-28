/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:59:31 by ahatay            #+#    #+#             */
/*   Updated: 2022/07/28 13:59:32 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	load_map(t_var var, int row, int col)
{
	if (var.map.mtx[row][col] == '1')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/tree.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == '0')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'E')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'C')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/collec.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'P')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/sprite.xpm",
				&var.img.size.x, &var.img.size.y);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img_ptr, 64 * col,
		64 * row);
	mlx_destroy_image(var.mlx, var.img.img_ptr);
	return (0);
}

int	write_map(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (col < var.map.size.x)
		{
			load_map(var, row, col);
			col++;
		}
		row++;
	}
	return (0);
}
