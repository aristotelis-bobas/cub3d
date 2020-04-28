/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   boss_fight_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 18:09:02 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 16:25:15 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <fcntl.h>

void	free_struct_sprite(t_spr *spr)
{
	int		i;

	i = 0;
	while (i < spr->amount)
	{
		free(spr->sprite[i]);
		i++;
	}
	free(spr->sprite);
	free(spr->distance);
	spr->amount = 0;
}

void	free_struct_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->map_y)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->map_x);
	free(map->grid);
}

void	new_map_3(t_map *map, char *map_str)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x[y])
		{
			map->grid[y][x] = (int)map_str[i] - 48;
			x++;
			i++;
		}
		if (map_str[i] == '\n')
			i++;
		y++;
	}
}

void	new_map_2(t_map *map)
{
	int		fd;
	char	*map_str;
	int		y;

	y = 0;
	fd = open("boss_fight.cub", O_RDONLY);
	map_str = ft_strdup("");
	if (!map_str)
		error(4);
	map_str = read_file(fd, map_str);
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
	new_map_3(map, map_str);
	free(map_str);
}

void	new_map_1(t_map *map)
{
	int		i;

	i = 0;
	map->map_y = 15;
	map->map_x = (int*)malloc(sizeof(int) * map->map_y);
	if (!map->map_x)
		error(4);
	while (i < map->map_y)
	{
		map->map_x[i] = 15;
		i++;
	}
	new_map_2(map);
}
