/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:19:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/03 18:31:53 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *data, t_map *map)
{
	if (data->forward || data->backward)
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x + \
		(data->plane_x * 0.07))] == 0)
			data->pos_x = data->pos_x + (data->plane_x * 0.05);
		if (map->grid[(int)(data->pos_y + (data->plane_y * \
		0.07))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y + (data->plane_y * 0.05);
	}
	else
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x + \
		(data->plane_x * 0.15))] == 0)
			data->pos_x = data->pos_x + (data->plane_x * 0.1);
		if (map->grid[(int)(data->pos_y + (data->plane_y * \
		0.15))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y + (data->plane_y * 0.1);
	}
}

void	move_left(t_data *data, t_map *map)
{
	if (data->forward || data->backward)
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x - \
		(data->plane_x * 0.07))] == 0)
			data->pos_x = data->pos_x - (data->plane_x * 0.05);
		if (map->grid[(int)(data->pos_y - (data->plane_y * \
		0.07))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y - (data->plane_y * 0.05);
	}
	else
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x - \
		(data->plane_x * 0.15))] == 0)
			data->pos_x = data->pos_x - (data->plane_x * 0.1);
		if (map->grid[(int)(data->pos_y - (data->plane_y * \
		0.15))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y - (data->plane_y * 0.1);
	}
}
