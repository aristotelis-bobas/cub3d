/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 23:44:18 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/02 22:27:20 by abobas        ########   odam.nl         */
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

void	sort_sprites(t_spr *spr)
{
	double		y_tmp;
	double		x_tmp;
	double		distance_tmp;
	int			i;
	int			counter;

	i = 0;
	while (i < (spr->amount - 1))
	{
		counter = 0;
		if (spr->distance[i] < spr->distance[i + 1])
		{
			y_tmp = spr->sprite[i + 1][0];
			x_tmp = spr->sprite[i + 1][1];
			distance_tmp = spr->distance[i + 1];
			spr->distance[i + 1] = spr->distance[i];
			spr->sprite[i + 1][0] = spr->sprite[i][0];
			spr->sprite[i + 1][1] = spr->sprite[i][1];
			spr->distance[i] = distance_tmp;
			spr->sprite[i][0] = y_tmp;
			spr->sprite[i][1] = x_tmp;
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

	i = 0;
	while (i < meta->spr->amount)
	{
		calculate_distance(meta->spr, meta->data, i);
		i++;
	}
	sort_sprites(meta->spr);
	i = 0;
	while (i < meta->spr->amount)
	{
		calculate_sprite(meta->spr, meta->data, meta->map, i);
		sprite_to_image(meta);
		i++;
	}
}
