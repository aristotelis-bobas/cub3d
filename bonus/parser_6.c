/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_6.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:16:11 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 21:55:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	dimension_y(t_map *map, char *map_str)
{
	int		i;

	i = map->index;
	map->map_y++;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n')
			map->map_y++;
		i++;
	}
}

void	dimension_x(t_map *map, char *map_str)
{
	int		i;
	int		y;

	i = map->index;
	y = 0;
	map->map_x = (int*)malloc(sizeof(int) * map->map_y);
	if (!map->map_x)
		error(4);
	while (y < map->map_y)
	{
		map->map_x[y] = 0;
		while (map_str[i] != '\n' && map_str[i] != '\0')
		{
			if ((map_str[i] >= '0' && map_str[i] <= '8') || map_str[i] == 'N' \
			|| map_str[i] == 'S' || map_str[i] == 'W' || map_str[i] == 'E')
			{
				map->map_x[y]++;
			}
			i++;
		}
		y++;
		i++;
	}
}

void	fill_row(t_map *map, char *map_str, int y)
{
	int		x;

	x = 0;
	while (x < map->map_x[y])
	{
		if (map_str[map->index] >= '0' && map_str[map->index] <= '8')
		{
			map->grid[y][x] = (int)map_str[map->index] - 48;
			x++;
		}
		else if ((map_str[map->index] == 'N' || map_str[map->index] == \
		'E' || map_str[map->index] == 'W' || map_str[map->index] == 'S') \
		&& map->spawn_or == '0')
		{
			map->spawn_x = x;
			map->spawn_y = y;
			map->spawn_or = map_str[map->index];
			map->grid[y][x] = 0;
			x++;
		}
		else if (map_str[map->index] != ' ')
			error(1);
		map->index++;
	}
}

void	fill_grid(t_map *map, char *map_str)
{
	int		y;

	y = 0;
	while (y < map->map_y)
	{
		fill_row(map, map_str, y);
		if (map_str[map->index] == '\n')
			map->index++;
		y++;
	}
}

void	parse_map(t_map *map, char *map_str)
{
	int		y;
	int		i;

	y = 0;
	i = map->index + 1;
	while (map_str[i] == ' ')
		i++;
	if (map_str[i] < '0' || map_str[i] > '8')
		error(1);
	dimension_y(map, map_str);
	dimension_x(map, map_str);
	map->grid = (int**)malloc(sizeof(int*) * map->map_y);
	if (!map->grid)
		error(4);
	while (y < map->map_y)
	{
		map->grid[y] = (int*)malloc(sizeof(int) * map->map_x[y]);
		if (!map->grid[y])
			error(4);
		y++;
	}
	fill_grid(map, map_str);
	check_walls(map);
	ft_putstr("Parsed map.\n");
}
