/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   differential_analysis.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 21:34:05 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/19 22:41:18 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	set_step(t_data *data)
{
	if (data->ray_x < 0)
	{
		data->step_x = -1;
		data->dist_x = (data->pos_x - data->map_x) * data->delta_x;
	}
	else
	{
		data->step_x = 1;
		data->dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_x;
	}
	if (data->ray_y < 0)
	{
		data->step_y = -1;
		data->dist_y = (data->pos_y - data->map_y) * data->delta_y;
	}
	else
	{
		data->step_y = 1;
		data->dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_y;
	}
}

void	step_map(t_data *data, t_map *map)
{
	if (map->grid[data->map_y][data->map_x] == 1)
		data->hit = 1;
	if (data->dist_x < data->dist_y)
	{
		data->dist_x = data->dist_x + data->delta_x;
		data->map_x += data->step_x;
		data->side = 0;
	}
	else
	{
		data->dist_y = data->dist_y + data->delta_y;
		data->map_y += data->step_y;
		data->side = 1;
	}
	if (map->grid[data->map_y][data->map_x] == 1 \
	|| map->grid[data->map_y][data->map_x] == 2)
		data->hit = 1;
}

void	wall(t_data *data)
{
	if (data->side == 0)
	{
		data->dist_wall[data->x] = (data->map_x - data->pos_x + \
		(1.0 - data->step_x) / 2) / data->ray_x;
		data->wall_x = data->pos_y + data->dist_wall[data->x] * data->ray_y;
		data->wall_or = (data->ray_x < 0) ? 'E' : 'W';
	}
	else
	{
		data->dist_wall[data->x] = (data->map_y - data->pos_y + \
		(1.0 - data->step_y) / 2) / data->ray_y;
		data->wall_x = data->pos_x + data->dist_wall[data->x] * data->ray_x;
		data->wall_or = (data->ray_y < 0) ? 'S' : 'N';
	}
	data->wall_x = data->wall_x - floor(data->wall_x);
}

void	differential_analysis(t_map *map, t_data *data)
{
	data->cam_x = 2 * data->x / (double)map->res_x - 1;
	data->ray_x = data->dir_x + (data->plane_x * data->cam_x);
	data->ray_y = data->dir_y + (data->plane_y * data->cam_x);
	data->delta_x = fabs(1 / data->ray_x);
	data->delta_y = fabs(1 / data->ray_y);
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	set_step(data);
	data->hit = 0;
	while (!data->hit)
		step_map(data, map);
	if (data->hit == 1)
		wall(data);
}
