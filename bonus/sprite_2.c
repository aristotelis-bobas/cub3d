/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 23:47:27 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 23:16:08 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_tex_x(t_meta *meta, int i)
{
	if (meta->spr->sprite[i][2] == 4)
	{
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->tex->x_spr / meta->spr->width) / 256;
	}
	else if (meta->spr->sprite[i][2] == 5)
	{
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->tex->x_m / meta->spr->width) / 256;
	}
	else if (meta->spr->sprite[i][2] == 6)
	{
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->tex->x_sg / meta->spr->width) / 256;
	}
	else if (meta->spr->sprite[i][2] == 7)
		explosion_sprite_x(meta, i);
	else
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->tex->x_mg / meta->spr->width) / 256;
}

int		get_color_tex(t_meta *meta, int i, int y)
{
	int		color;
	int		d;

	d = (y * 256) - meta->map->res_y * 128 + meta->spr->height * 128;
	if (meta->spr->sprite[i][2] == 4)
	{
		meta->spr->tex_y = (d * meta->tex->y_spr) / meta->spr->height / 256;
		color = *(int*)(meta->tex->addr_spr + (meta->spr->tex_y * \
		meta->tex->ls_spr + meta->spr->tex_x * (meta->tex->bpp_spr / 8)));
	}
	else if (meta->spr->sprite[i][2] == 5)
	{
		meta->spr->tex_y = (d * meta->tex->y_m) / meta->spr->height / 256;
		color = *(int*)(meta->tex->addr_m + (meta->spr->tex_y * \
		meta->tex->ls_m + meta->spr->tex_x * (meta->tex->bpp_m / 8)));
	}
	else if (meta->spr->sprite[i][2] == 6)
	{
		meta->spr->tex_y = (d * meta->tex->y_sg) / meta->spr->height / 256;
		color = *(int*)(meta->tex->addr_sg + (meta->spr->tex_y * \
		meta->tex->ls_sg + meta->spr->tex_x * (meta->tex->bpp_sg / 8)));
	}
	else
		color = get_color_tex_2(meta, i, d);
	return (color);
}

int		distance_sprite(int color, t_spr *spr, int i)
{
	int		r;
	int		g;
	int		b;
	double	multi;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	multi = 0.75 * (spr->distance[i] / 10);
	if (multi > 0.75)
		multi = 0.75;
	r = (int)(multi * 10 + ((1 - multi) * r));
	g = (int)(multi * 10 + ((1 - multi) * g));
	b = (int)(multi * 10 + ((1 - multi) * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	put_pixel_sprite(t_meta *meta, int y, int i)
{
	int		color;

	color = get_color_tex(meta, i, y);
	if (color > 0)
	{
		if (meta->spr->sprite[i][2] == 4 && meta->spr->sprite[i][4] > 0)
			color = damaged_sprite(color);
		*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + \
		(meta->spr->stripe * (meta->mlx->bpp / 8))) = distance_sprite(color, \
		meta->spr, i);
	}
}

void	sprite_to_image(t_meta *meta, int i)
{
	int		y;

	meta->spr->stripe = meta->spr->start_x;
	while (meta->spr->stripe < meta->spr->end_x)
	{
		get_tex_x(meta, i);
		y = meta->spr->start_y;
		if (meta->spr->transform_y > 0 && meta->spr->stripe > 0 && \
		meta->spr->stripe < meta->map->res_x && meta->spr->transform_y < \
		meta->data->dist_wall[meta->spr->stripe])
		{
			while (y < meta->spr->end_y)
			{
				put_pixel_sprite(meta, y, i);
				y++;
			}
		}
		meta->spr->stripe++;
	}
}
