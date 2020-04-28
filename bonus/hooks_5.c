/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_5.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 20:30:34 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/19 20:52:36 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_forward(t_data *data, t_spr *spr)
{
	int		i;
	int		counter;

	i = 0;
	while (i < spr->amount)
	{
		counter = 0;
		if (spr->sprite[i][2] == 4)
		{
			if ((data->pos_x + (data->dir_x * 0.1) < spr->sprite[i][1] + \
			0.1) && (data->pos_x + (data->dir_x * 0.1) > spr->sprite[i][1] \
			- 0.1))
				counter++;
			if ((data->pos_y + (data->dir_y * 0.1) < spr->sprite[i][0] + \
			0.1) && (data->pos_y + (data->dir_y * 0.1) > spr->sprite[i][0] \
			- 0.1))
				counter++;
			if (counter == 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_backward(t_data *data, t_spr *spr)
{
	int		i;
	int		counter;

	i = 0;
	while (i < spr->amount)
	{
		counter = 0;
		if (spr->sprite[i][2] == 4)
		{
			if ((data->pos_x - (data->dir_x * 0.1) < spr->sprite[i][1] + \
			0.1) && (data->pos_x - (data->dir_x * 0.1) > spr->sprite[i][1] \
			- 0.1))
				counter++;
			if ((data->pos_y - (data->dir_y * 0.1) < spr->sprite[i][0] + \
			0.1) && (data->pos_y - (data->dir_y * 0.1) > spr->sprite[i][0] - \
			0.1))
				counter++;
			if (counter == 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_right(t_data *data, t_spr *spr)
{
	int		i;
	int		counter;

	i = 0;
	while (i < spr->amount)
	{
		counter = 0;
		if (spr->sprite[i][2] == 4)
		{
			if ((data->pos_x + (data->plane_x * 0.1) < spr->sprite[i][1] + \
			0.1) && (data->pos_x + (data->plane_x * 0.1) > spr->sprite[i][1] \
			- 0.1))
				counter++;
			if ((data->pos_y + (data->plane_y * 0.1) < spr->sprite[i][0] + \
			0.1) && (data->pos_y + (data->plane_y * 0.1) > spr->sprite[i][0] - \
			0.1))
				counter++;
			if (counter == 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_left(t_data *data, t_spr *spr)
{
	int		i;
	int		counter;

	i = 0;
	while (i < spr->amount)
	{
		counter = 0;
		if (spr->sprite[i][2] == 4)
		{
			if ((data->pos_x - (data->plane_x * 0.1) < spr->sprite[i][1] + \
			0.1) && (data->pos_x - (data->plane_x * 0.1) > spr->sprite[i][1] - \
			0.1))
				counter++;
			if ((data->pos_y - (data->plane_y * 0.1) < spr->sprite[i][0] + \
			0.1) && (data->pos_y - (data->plane_y * 0.1) > spr->sprite[i][0] \
			- 0.1))
				counter++;
			if (counter == 2)
				return (0);
		}
		i++;
	}
	return (1);
}
