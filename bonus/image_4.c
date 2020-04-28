/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 20:47:18 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/14 21:37:13 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_distance_floor(int color, int y)
{
	int		r;
	int		g;
	int		b;
	double	multi;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	multi = y * 0.00099;
	if (multi > 0.85)
		multi = 0.85;
	r = (int)(1 - multi * 10 + (multi * r));
	g = (int)(1 - multi * 10 + (multi * g));
	b = (int)(1 - multi * 10 + (multi * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	calculations_floor_ceiling(t_meta *meta, int y)
{
	meta->data->current_dist = 1.5 * meta->map->res_y / \
	(2.0 * y - meta->map->res_y);
	meta->data->weight = meta->data->current_dist / \
	meta->data->dist_wall[meta->data->x];
	meta->data->current_x = meta->data->weight * meta->data->floor_x + (1.0 - \
	meta->data->weight) * meta->data->pos_x;
	meta->data->current_y = meta->data->weight * meta->data->floor_y + (1.0 - \
	meta->data->weight) * meta->data->pos_y;
	meta->img->tex_x_floor = (int)(meta->data->current_x * meta->tex->x_f) \
	% meta->tex->x_f;
	meta->img->tex_y_floor = (int)(meta->data->current_y * meta->tex->y_f) \
	% meta->tex->y_f;
	meta->img->tex_x_ceiling = (int)(meta->data->current_x * meta->tex->x_c) \
	% meta->tex->x_c;
	meta->img->tex_y_ceiling = (int)(meta->data->current_y * meta->tex->y_c) \
	% meta->tex->y_c;
}

void	build_floor_ceiling(t_meta *meta)
{
	int		y;
	int		color;

	y = meta->img->draw_end;
	while (y < meta->map->res_y)
	{
		calculations_floor_ceiling(meta, y);
		color = *(int*)(meta->tex->addr_f + (meta->img->tex_y_floor * \
		meta->tex->ls_f + meta->img->tex_x_floor * (meta->tex->bpp_f / 8)));
		*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (meta->data->x * \
		(meta->mlx->bpp / 8))) = color_distance_floor(color, y);
		color = *(int*)(meta->tex->addr_c + (meta->img->tex_y_ceiling * \
		meta->tex->ls_c + meta->img->tex_x_ceiling * \
		(meta->tex->bpp_c / 8)));
		*(int*)(meta->mlx->addr + ((meta->map->res_y - y - 1) * \
		meta->mlx->ls) + (meta->data->x * (meta->mlx->bpp / 8))) = \
		color_distance_floor(color, y);
		y++;
	}
}
