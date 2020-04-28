/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_6.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 20:39:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 16:26:49 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int		get_minigun_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 150);
	y = y - (meta->map->res_y - 498);
	x_tex = (meta->ani->x_mg1 / 500) * x;
	y_tex = (meta->ani->y_mg1 / 498) * y;
	color = *(int*)(meta->ani->addr_mg1 + (y_tex * meta->ani->ls_mg1) + \
	(x_tex * (meta->ani->bpp_mg1 / 8)));
	return (color);
}

void	put_minigun(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 498;
	while (y < meta->map->res_y)
	{
		x = (meta->map->res_x / 2) - 150;
		while (x < ((meta->map->res_x / 2) + 350))
		{
			color = get_minigun_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}

int		get_minigun_fire_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 210);
	y = y - (meta->map->res_y - 250);
	x_tex = (meta->ani->x_mg2 / 250) * x;
	y_tex = (meta->ani->y_mg2 / 200) * y;
	color = *(int*)(meta->ani->addr_mg2 + (y_tex * meta->ani->ls_mg2) + \
	(x_tex * (meta->ani->bpp_mg2 / 8)));
	return (color);
}

void	put_minigun_fire(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 250;
	while (y < (meta->map->res_y - 50))
	{
		x = (meta->map->res_x / 2) - 210;
		while (x < ((meta->map->res_x / 2) + 40))
		{
			color = get_minigun_fire_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}

void	put_minigun_animation(t_meta *meta)
{
	if (meta->data->weapon_audio_timer == 0)
		system("afplay -v 2.0 minigun_fire.mp3 &");
	if (meta->data->weapon_timer % 2 == 0)
		put_minigun_fire(meta);
	put_minigun(meta);
	if (meta->data->weapon_timer % 2 == 1)
		put_minigun_rot(meta);
	meta->data->weapon_timer++;
	meta->data->weapon_audio_timer++;
	if (meta->data->weapon_timer == 15)
	{
		meta->data->weapon_timer = 0;
		meta->data->weapon_audio_timer = 0;
	}
}
