/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_4.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 22:57:36 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/14 19:39:04 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	fill_data_dir_2(t_data *data, t_map *map)
{
	if (map->spawn_or == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
		return ;
	}
	else if (map->spawn_or == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

void	fill_data_dir_1(t_data *data, t_map *map)
{
	if (map->spawn_or == 'S' || map->spawn_or == 'W')
	{
		fill_data_dir_2(data, map);
		return ;
	}
	else if (map->spawn_or == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
		return ;
	}
	else if (map->spawn_or == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
}

void	fill_data(t_data *data, t_map *map)
{
	data->pos_x = (double)map->spawn_x + 0.5;
	data->pos_y = (double)map->spawn_y + 0.5;
	data->dist_wall = (double*)malloc(sizeof(double) * map->res_x);
	if (!data->dist_wall)
		error(4);
	fill_data_dir_1(data, map);
}
