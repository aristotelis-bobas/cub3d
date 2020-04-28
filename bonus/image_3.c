/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 18:48:09 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/19 22:42:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_distance(int color, t_data *data)
{
	int		r;
	int		g;
	int		b;
	double	multi;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	multi = 0.85 * (data->dist_wall[data->x] / 10);
	if (multi > 0.85)
		multi = 0.85;
	r = (int)(multi * 10 + ((1 - multi) * r));
	g = (int)(multi * 10 + ((1 - multi) * g));
	b = (int)(multi * 10 + ((1 - multi) * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int		get_texel(t_meta *meta, int or)
{
	int		color;

	meta->img->tex_y = (int)meta->img->tex_pos;
	meta->img->tex_pos = meta->img->tex_pos + meta->img->step;
	if (or == 'S')
		color = *(int*)(meta->tex->addr_s + (meta->img->tex_y * \
		meta->tex->ls_s + meta->img->tex_x * (meta->tex->bpp_s / 8)));
	else if (or == 'N')
		color = *(int*)(meta->tex->addr_n + (meta->img->tex_y * \
		meta->tex->ls_n) + (meta->img->tex_x * (meta->tex->bpp_n / 8)));
	else if (or == 'W')
		color = *(int*)(meta->tex->addr_w + (meta->img->tex_y * \
		meta->tex->ls_w + meta->img->tex_x * (meta->tex->bpp_w / 8)));
	else
		color = *(int*)(meta->tex->addr_e + (meta->img->tex_y * \
		meta->tex->ls_e + meta->img->tex_x * (meta->tex->bpp_e / 8)));
	return (color_distance(color, meta->data));
}

void	build_image(t_meta *meta)
{
	while (meta->img->draw_start < meta->img->draw_end)
	{
		*(int*)(meta->mlx->addr + (meta->img->draw_start * meta->mlx->ls) + \
		(meta->data->x * (meta->mlx->bpp / 8))) = \
		get_texel(meta, meta->data->wall_or);
		meta->img->draw_start++;
	}
	build_floor_ceiling(meta);
}
