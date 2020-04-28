/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 22:16:39 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 20:37:16 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void		check_hit(t_data *data, t_spr *spr)
{
	int		i;

	i = 0;
	while (i < spr->amount)
	{
		if (spr->sprite[i][2] == 4)
		{
			if (spr->sprite[i][0] < data->current_y + 0.2 && spr->sprite[i][0] \
			> data->current_y - 0.2 && spr->sprite[i][1] < data->current_x \
			+ 0.2 && spr->sprite[i][1] > data->current_x - 0.2)
			{
				spr->sprite[i][3] = spr->sprite[i][3] - 25;
				spr->sprite[i][4] = 1;
				system("afplay -v 2 pain.mp3 &");
				if (spr->sprite[i][3] <= 0)
					spr->sprite[i][2] = 7;
				data->hit = 1;
			}
		}
		i++;
	}
}

void		step_map_fire(t_data *data, t_map *map, t_spr *spr)
{
	data->current_y += 0.1 * data->dir_y;
	data->current_x += 0.1 * data->dir_x;
	if (map->grid[(int)data->current_y][(int)data->current_x] > 0)
		data->hit = 1;
	check_hit(data, spr);
}

void		fire_weapon(t_meta *meta)
{
	meta->data->current_x = meta->data->pos_x;
	meta->data->current_y = meta->data->pos_y;
	meta->data->hit = 0;
	while (meta->data->hit != 1)
		step_map_fire(meta->data, meta->map, meta->spr);
}
