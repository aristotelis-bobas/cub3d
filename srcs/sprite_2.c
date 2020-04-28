/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 23:47:27 by abobas        #+#    #+#                 */
/*   Updated: 2020/01/31 22:27:53 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_sprite(t_meta *meta, int y)
{
	int		d;
	int		color;

	d = (y * 256) - meta->map->res_y * 128 + meta->spr->height * 128;
	meta->spr->tex_y = (d * meta->tex->y_spr) / meta->spr->height / 256;
	color = *(int*)(meta->tex->addr_spr + (meta->spr->tex_y * \
	meta->tex->ls_spr + meta->spr->tex_x * (meta->tex->bpp_spr / 8)));
	if (color > 0)
	{
		*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + \
		(meta->spr->stripe * (meta->mlx->bpp / 8))) = color;
	}
}

void	sprite_to_image(t_meta *meta)
{
	int		y;

	meta->spr->stripe = meta->spr->start_x;
	while (meta->spr->stripe < meta->spr->end_x)
	{
		meta->spr->tex_x = (int)(256 * (meta->spr->stripe - \
		(-meta->spr->width / 2 + meta->spr->screen_x)) * \
		meta->tex->x_spr / meta->spr->width) / 256;
		y = meta->spr->start_y;
		if (meta->spr->transform_y > 0 && meta->spr->stripe > 0 && \
		meta->spr->stripe < meta->map->res_x && meta->spr->transform_y < \
		meta->data->dist_wall[meta->spr->stripe])
		{
			while (y < meta->spr->end_y)
			{
				put_pixel_sprite(meta, y);
				y++;
			}
		}
		meta->spr->stripe++;
	}
}
