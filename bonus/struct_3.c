/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 20:08:30 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 21:55:00 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	size_array(t_map *map, t_spr *spr)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < map->map_y)
	{
		while (x < map->map_x[y])
		{
			if (map->grid[y][x] > 3 && map->grid[y][x] < 9)
				spr->amount++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	make_array(t_spr *spr)
{
	int			i;

	i = 0;
	spr->sprite = (double**)malloc(sizeof(double*) * spr->amount);
	if (!spr->sprite)
		error(4);
	while (i < spr->amount)
	{
		spr->sprite[i] = (double*)malloc(sizeof(double) * 5);
		if (!spr->sprite[i])
			error(4);
		i++;
	}
	spr->distance = (double*)malloc(sizeof(double) * spr->amount);
	if (!spr->distance)
		error(4);
}

void	fill_array(t_spr *spr, t_map *map)
{
	int		y;
	int		x;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (y < map->map_y)
	{
		while (x < map->map_x[y])
		{
			if (map->grid[y][x] > 3 && map->grid[y][x] < 9)
			{
				spr->sprite[i][0] = y + 0.5;
				spr->sprite[i][1] = x + 0.5;
				spr->sprite[i][2] = map->grid[y][x];
				spr->sprite[i][3] = (map->grid[y][x] == 4) ? 100 : 0;
				map->grid[y][x] = 0;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_array_2(t_spr *spr)
{
	int		i;

	i = 0;
	while (i < spr->amount)
	{
		spr->sprite[i][4] = 0;
		i++;
	}
}

void	fill_spr(t_spr *spr, t_map *map)
{
	size_array(map, spr);
	if (spr->amount == 0)
		return ;
	make_array(spr);
	fill_array(spr, map);
	fill_array_2(spr);
}
