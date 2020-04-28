/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_7.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:15:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 19:12:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	malloc_check(t_map *map)
{
	int		y;

	y = 0;
	map->check = (int**)malloc(sizeof(int*) * map->map_y);
	if (!map->check)
		error(4);
	while (y < map->map_y)
	{
		map->check[y] = (int*)malloc(sizeof(int) * map->map_x[y]);
		if (!map->check[y])
			error(4);
		y++;
	}
}

void	fill_check(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x[y])
		{
			map->check[y][x] = map->grid[y][x];
			if (map->check[y][x] == 2 || (map->check[y][x] \
			>= 4 && map->check[y][x] <= 8))
				map->check[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	floodfill_check(int y, int x, t_map *map)
{
	if (y == map->map_y - 1 || x == (map->map_x[y] - 1) || x == 0 || y == 0)
		error(1);
	if (map->check[y][x] == 0)
	{
		map->check[y][x] = 7;
		if (map->check[y + 1][x] != 1)
			floodfill_check(y + 1, x, map);
		if (map->check[y + 1][x + 1] != 1)
			floodfill_check(y + 1, x + 1, map);
		if (map->check[y + 1][x - 1] != 1)
			floodfill_check(y + 1, x - 1, map);
		if (map->check[y - 1][x] != 1)
			floodfill_check(y - 1, x, map);
		if (map->check[y - 1][x + 1] != 1)
			floodfill_check(y - 1, x + 1, map);
		if (map->check[y - 1][x - 1] != 1)
			floodfill_check(y - 1, x - 1, map);
		if (map->check[y][x + 1] != 1)
			floodfill_check(y, x + 1, map);
		if (map->check[y][x - 1] != 1)
			floodfill_check(y, x - 1, map);
	}
}

void	free_check(t_map *map)
{
	int		y;

	y = 0;
	while (y < map->map_y)
	{
		free(map->check[y]);
		y++;
	}
	free(map->check);
}

void	check_walls(t_map *map)
{
	malloc_check(map);
	fill_check(map);
	floodfill_check(map->spawn_y, map->spawn_x, map);
	free_check(map);
}
