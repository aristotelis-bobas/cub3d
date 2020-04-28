/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 23:44:18 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 19:29:23 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	calculate_distance(t_spr *spr, t_data *data, int i)
{
	spr->distance[i] = ((data->pos_x - spr->sprite[i][1]) * \
	(data->pos_x - spr->sprite[i][1])) + ((data->pos_y - \
	spr->sprite[i][0]) * (data->pos_y - spr->sprite[i][0]));
}

void	sprite_calculations(t_meta *meta)
{
	int		i;

	i = 0;
	while (i < meta->spr->amount)
	{
		calculate_distance(meta->spr, meta->data, i);
		i++;
	}
	i = 0;
	while (i < meta->spr->amount)
	{
		if (meta->spr->sprite[i][2] == 4)
			move_sprite(meta->spr, meta->data, meta->map, i);
		i++;
	}
	i = 0;
	while (i < meta->spr->amount)
	{
		calculate_distance(meta->spr, meta->data, i);
		i++;
	}
}

void	sort_sprites(t_spr *spr, int i)
{
	int			counter;

	while (i < (spr->amount - 1))
	{
		counter = 0;
		if (spr->distance[i] < spr->distance[i + 1])
		{
			substitute_sprite(spr, i);
			counter++;
		}
		i = (counter != 0) ? 0 : i + 1;
	}
}

void	calculate_sprite(t_spr *spr, t_data *data, t_map *map, int i)
{
	spr->sprite_x = spr->sprite[i][1] - data->pos_x;
	spr->sprite_y = spr->sprite[i][0] - data->pos_y;
	spr->inv = 1.0 / ((data->plane_x * data->dir_y) - (data->dir_x \
	* data->plane_y));
	spr->transform_x = spr->inv * ((data->dir_y * spr->sprite_x) \
	- (data->dir_x * spr->sprite_y));
	spr->transform_y = spr->inv * ((-data->plane_y * spr->sprite_x)	\
	+ (data->plane_x * spr->sprite_y));
	spr->screen_x = (int)((map->res_x / 2) * (1 + spr->transform_x \
	/ spr->transform_y));
	spr->height = abs((int)(1 * (map->res_y / spr->transform_y)));
	spr->width = abs((int)(1 * (map->res_y / spr->transform_y)));
	spr->start_y = -spr->height / 2 + map->res_y / 2;
	spr->start_y = (spr->start_y < 0) ? 0 : spr->start_y;
	spr->end_y = spr->height / 2 + map->res_y / 2;
	spr->end_y = (spr->end_y >= map->res_y) ? map->res_y - 1 : spr->end_y;
	spr->start_x = -spr->width / 2 + spr->screen_x;
	spr->start_x = (spr->start_x < 0) ? 0 : spr->start_x;
	spr->end_x = spr->width / 2 + spr->screen_x;
	spr->end_x = (spr->end_x >= map->res_x) ? map->res_x - 1 : spr->end_x;
}

void	draw_sprite(t_meta *meta)
{
	int		i;

	sprite_calculations(meta);
	check_object(meta->spr, meta->data);
	i = 0;
	sort_sprites(meta->spr, i);
	while (i < meta->spr->amount)
	{
		if (meta->spr->sprite[i][2] > 3 && meta->spr->sprite[i][2] <= 8)
		{
			calculate_sprite(meta->spr, meta->data, meta->map, i);
			sprite_to_image(meta, i);
			handle_animation_sprite(meta, i);
		}
		i++;
	}
}
