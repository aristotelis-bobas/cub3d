/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:46:25 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/14 20:54:32 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_forward(t_data *data, t_map *map)
{
	if (data->left || data->right)
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x + \
		(data->dir_x * 0.1))] == 0)
			data->pos_x = data->pos_x + (data->dir_x * 0.07);
		if (map->grid[(int)(data->pos_y + (data->dir_y * \
		0.1))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y + (data->dir_y * 0.07);
	}
	else
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x + \
		(data->dir_x * 0.15))] == 0)
			data->pos_x = data->pos_x + (data->dir_x * 0.1);
		if (map->grid[(int)(data->pos_y + (data->dir_y * \
		0.15))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y + (data->dir_y * 0.1);
	}
}

void	move_backward(t_data *data, t_map *map)
{
	if (data->left || data->right)
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x - \
		(data->dir_x * 0.1))] == 0)
			data->pos_x = data->pos_x - (data->dir_x * 0.07);
		if (map->grid[(int)(data->pos_y - (data->dir_y * \
		0.1))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y - (data->dir_y * 0.07);
	}
	else
	{
		if (map->grid[(int)data->pos_y][(int)(data->pos_x - \
		(data->dir_x * 0.15))] == 0)
			data->pos_x = data->pos_x - (data->dir_x * 0.1);
		if (map->grid[(int)(data->pos_y - (data->dir_y * \
		0.15))][(int)data->pos_x] == 0)
			data->pos_y = data->pos_y - (data->dir_y * 0.1);
	}
}

void	rotate_left(t_data *data)
{
	data->dir_x_old = data->dir_x;
	data->plane_x_old = data->plane_x;
	data->dir_x = data->dir_x * cos(-0.04) - data->dir_y * sin(-0.04);
	data->plane_x = data->plane_x * cos(-0.04) - data->plane_y * sin(-0.04);
	data->dir_y = data->dir_x_old * sin(-0.04) + data->dir_y * cos(-0.04);
	data->plane_y = data->plane_x_old * sin(-0.04) + data->plane_y * \
	cos(-0.04);
}

void	rotate_right(t_data *data)
{
	data->dir_x_old = data->dir_x;
	data->plane_x_old = data->plane_x;
	data->dir_x = data->dir_x * cos(0.04) - data->dir_y * sin(0.04);
	data->dir_y = data->dir_x_old * sin(0.04) + data->dir_y * cos(0.04);
	data->plane_x = data->plane_x * cos(0.04) - data->plane_y * sin(0.04);
	data->plane_y = data->plane_x_old * sin(0.04) + data->plane_y * cos(0.04);
}
