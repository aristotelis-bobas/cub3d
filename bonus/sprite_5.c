/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_5.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 23:11:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 23:21:34 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int		get_color_tex_2(t_meta *meta, int i, int d)
{
	int		color;

	if (meta->spr->sprite[i][2] == 7)
		color = explosion_sprite_color(meta, i, d);
	else
	{
		meta->spr->tex_y = (d * meta->tex->y_mg) / meta->spr->height / 256;
		color = *(int*)(meta->tex->addr_mg + (meta->spr->tex_y * \
		meta->tex->ls_mg + meta->spr->tex_x * (meta->tex->bpp_mg / 8)));
	}
	return (color);
}

void	check_object_2(t_spr *spr, t_data *data, int i)
{
	if (spr->sprite[i][2] == 6 && spr->distance[i] < 0.3)
	{
		data->shotgun = 1;
		spr->sprite[i][0] = 0;
		spr->sprite[i][1] = 0;
		spr->sprite[i][2] = 0;
		system("afplay -v 2.0 pickup.mp3 &");
	}
	else if (spr->sprite[i][2] == 8 && spr->distance[i] < 0.3)
	{
		data->minigun = 1;
		spr->sprite[i][0] = 0;
		spr->sprite[i][1] = 0;
		spr->sprite[i][2] = 0;
		system("afplay -v 2.0 pickup.mp3 &");
	}
}
