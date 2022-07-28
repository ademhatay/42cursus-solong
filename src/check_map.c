/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:56:54 by ahatay            #+#    #+#             */
/*   Updated: 2022/07/28 13:56:55 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_wall(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		if (row == 0 || row == (var.map.size.y - 1))
		{
			while (var.map.mtx[row][col])
			{
				if (var.map.mtx[row][col] != '1')
					free_exit(&var, "Üst veya alt duvarlar ile çevrili değil.");
				col++;
			}
		}
		if (var.map.mtx[row][0] != '1'
			|| var.map.mtx[row][var.map.size.x - 1] != '1')
			free_exit(&var, "Yanlar duvar ile  çevrili değil.");
		row++;
	}
	return (0);
}

int	check_sprites(t_var var)
{
	int		has[3];
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (col <= var.map.size.x)
		{
			if (var.map.mtx[row][col] == 'P')
				has[0] = 1;
			if (var.map.mtx[row][col] == 'E')
				has[1] = 1;
			if (var.map.mtx[row][col] == 'C')
				has[2] = 1;
			col++;
		}
		row++;
	}
	if (has[0] != 1 || has[1] != 1 || has[2] != 1)
		free_exit(&var, "HATALI HARİTA: fazla veya eksik sprite");
	return (0);
}

int	check_ret(t_var var)
{
	int		row;

	row = 0;
	while (row < var.map.size.y)
	{
		if (var.map.size.x != (int)ft_strlen(var.map.mtx[row]))
			free_exit(&var, "HATALI HARİTA: harita boyutu eşit uyumsuz");
		row++;
	}
	return (0);
}

int	check_char(t_var var)
{
	int		row;
	int		col;	

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (var.map.mtx[row][col])
		{
			if (var.map.mtx[row][col] != '0' && var.map.mtx[row][col] != '1'
					&& var.map.mtx[row][col] != 'P'
					&& var.map.mtx[row][col] != 'E'
					&& var.map.mtx[row][col] != 'C')
				free_exit(&var, "HATALI HARİTA: tanimsiz karakter");
			col++;
		}
		row++;
	}
	return (0);
}

int	check_map(t_var var)
{
	check_wall(var);
	check_sprites(var);
	check_ret(var);
	check_char(var);
	return (1);
}
