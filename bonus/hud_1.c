/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 20:51:25 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 16:56:06 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	put_healthbar(t_meta *meta)
{
	int		y;
	int		x;

	y = meta->map->res_y - 105;
	while (y < meta->map->res_y - 75)
	{
		x = 95;
		while (x < 405)
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = 12632256;
			x++;
		}
		y++;
	}
}

void	put_current_health(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 100;
	while (y < meta->map->res_y - 80)
	{
		x = 100;
		color = 8190976;
		if (meta->data->health < 70)
			color = (meta->data->health > 40) ? 16746306 : 16722964;
		while (x < (100 + meta->data->health * 3))
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = color;
			if (x % 10 == 0)
				color += 5;
			x++;
		}
		y++;
	}
}

int		blood_color(t_meta *meta, int y, int x)
{
	int		r;
	int		g;
	int		b;
	int		color;

	color = *(int*)(meta->mlx->addr + (y * meta->mlx->ls + \
	(x * (meta->mlx->bpp / 8))));
	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	r = (int)((0.9 * 255) + (0.1 * r));
	g = (int)((0.5 * 100) + (0.2 * g));
	b = (int)((0.5 * 100) + (0.2 * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	put_damage(t_meta *meta)
{
	int		y;
	int		x;

	y = 0;
	if (meta->data->hit_event == 1)
		meta->data->health = meta->data->health - 10;
	if (meta->data->hit_event > 0 && meta->data->hit_event <= 5)
	{
		while (y < meta->map->res_y)
		{
			x = 0;
			while (x < meta->map->res_x)
			{
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = blood_color(meta, y, x);
				x++;
			}
			y++;
		}
	}
	meta->data->hit_event++;
	if (meta->data->hit_event == 30)
		meta->data->hit_event = 0;
}

void	put_hud(t_meta *meta)
{
	if (meta->data->hit_event == 1)
		system("afplay -v 2 oof.mp3 &");
	if (meta->data->hit_event > 0)
		put_damage(meta);
	if (meta->data->health <= 0)
		game_over(meta);
	put_healthbar(meta);
	put_current_health(meta);
	put_minimap(meta);
	if (meta->data->boss_fight > 101)
		put_healthbar_boss(meta);
	if (meta->data->shotgun == 1 || meta->data->minigun == 1)
		put_crosshair(meta);
	if (meta->data->weapon_timer == 0 && meta->data->shotgun == 1)
		put_shotgun(meta);
	if (meta->data->weapon_timer > 0 && meta->data->shotgun == 1)
		put_shotgun_animation(meta);
	if (meta->data->weapon_timer == 0 && meta->data->minigun == 1)
		put_minigun(meta);
	if (meta->data->weapon_timer > 0 && meta->data->minigun == 1)
		put_minigun_animation(meta);
}
