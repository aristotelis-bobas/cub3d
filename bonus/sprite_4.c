/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_4.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 18:43:20 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/18 23:42:56 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int		damaged_sprite(int color)
{
	int		r;
	int		g;
	int		b;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	r = (int)((0.1 * 255) + (0.9 * r));
	g = (int)((0.7 * 240) + (0.3 * g));
	b = (int)((0.1 * 255) + (0.9 * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int		explosion_sprite_color_2(t_meta *meta, int i, int d)
{
	int		color;

	if (meta->spr->sprite[i][4] >= 10 && meta->spr->sprite[i][4] < 15)
	{
		meta->spr->tex_y = (d * meta->ani->y_ex3) / meta->spr->height / 256;
		color = *(int*)(meta->ani->addr_ex3 + (meta->spr->tex_y * \
		meta->ani->ls_ex3 + meta->spr->tex_x * (meta->ani->bpp_ex3 / 8)));
	}
	else
	{
		meta->spr->tex_y = (d * meta->ani->y_ex4) / meta->spr->height / 256;
		color = *(int*)(meta->ani->addr_ex4 + (meta->spr->tex_y * \
		meta->ani->ls_ex4 + meta->spr->tex_x * (meta->ani->bpp_ex4 / 8)));
	}
	return (color);
}

int		explosion_sprite_color(t_meta *meta, int i, int d)
{
	int		color;

	if (meta->spr->sprite[i][4] < 5)
	{
		meta->spr->tex_y = (d * meta->ani->y_ex1) / meta->spr->height / 256;
		color = *(int*)(meta->ani->addr_ex1 + (meta->spr->tex_y * \
		meta->ani->ls_ex1 + meta->spr->tex_x * (meta->ani->bpp_ex1 / 8)));
	}
	else if (meta->spr->sprite[i][4] >= 5 && meta->spr->sprite[i][4] < 10)
	{
		meta->spr->tex_y = (d * meta->ani->y_ex2) / meta->spr->height / 256;
		color = *(int*)(meta->ani->addr_ex2 + (meta->spr->tex_y * \
		meta->ani->ls_ex2 + meta->spr->tex_x * (meta->ani->bpp_ex2 / 8)));
	}
	else
		color = explosion_sprite_color_2(meta, i, d);
	return (color);
}

void	explosion_sprite_x(t_meta *meta, int i)
{
	if (meta->spr->sprite[i][4] < 5)
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->ani->x_ex1 / meta->spr->width) / 256;
	else if (meta->spr->sprite[i][4] >= 5 && meta->spr->sprite[i][4] < 10)
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->ani->x_ex2 / meta->spr->width) / 256;
	else if (meta->spr->sprite[i][4] >= 10 && meta->spr->sprite[i][4] < 15)
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->ani->x_ex3 / meta->spr->width) / 256;
	else if (meta->spr->sprite[i][4] >= 15 && meta->spr->sprite[i][4] < 20)
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->ani->x_ex4 / meta->spr->width) / 256;
}

void	handle_animation_sprite(t_meta *meta, int i)
{
	if (meta->spr->sprite[i][4] > 0)
	{
		meta->spr->sprite[i][4]++;
		if (meta->spr->sprite[i][2] == 4 && meta->spr->sprite[i][4] == 11)
			meta->spr->sprite[i][4] = 0;
		if (meta->spr->sprite[i][2] == 7 && meta->spr->sprite[i][4] == 20)
		{
			meta->spr->sprite[i][0] = 0;
			meta->spr->sprite[i][1] = 0;
			meta->spr->sprite[i][2] = 0;
			system("afplay -v 2 exploded_alien.mp3 &");
		}
	}
}
