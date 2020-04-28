/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 18:48:09 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/02 22:21:57 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_texel(t_meta *meta, int or)
{
	int		color;

	meta->img->tex_y = (int)meta->img->tex_pos;
	meta->img->tex_pos = meta->img->tex_pos + meta->img->step;
	if (or == 'S')
	{
		color = *(int*)(meta->tex->addr_s + (meta->img->tex_y * \
		meta->tex->ls_s + meta->img->tex_x * (meta->tex->bpp_s / 8)));
	}
	else if (or == 'N')
	{
		color = *(int*)(meta->tex->addr_n + (meta->img->tex_y * \
		meta->tex->ls_n) + (meta->img->tex_x * (meta->tex->bpp_n / 8)));
	}
	else if (or == 'W')
	{
		color = *(int*)(meta->tex->addr_w + (meta->img->tex_y * \
		meta->tex->ls_w + meta->img->tex_x * (meta->tex->bpp_w / 8)));
	}
	else
	{
		color = *(int*)(meta->tex->addr_e + (meta->img->tex_y * \
		meta->tex->ls_e + meta->img->tex_x * (meta->tex->bpp_e / 8)));
	}
	return (color);
}

void	build_image(t_meta *meta)
{
	int		y;

	y = meta->img->draw_end;
	while (meta->img->draw_start < meta->img->draw_end)
	{
		*(int*)(meta->mlx->addr + (meta->img->draw_start * meta->mlx->ls) + \
		(meta->data->x * (meta->mlx->bpp / 8))) = \
		get_texel(meta, meta->data->wall_or);
		meta->img->draw_start++;
	}
	while (y < meta->img->wall_height)
	{
		*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (meta->data->x * \
		(meta->mlx->bpp / 8))) = meta->map->floor;
		*(int*)(meta->mlx->addr + ((meta->img->wall_height - y - 1) * \
		meta->mlx->ls) + (meta->data->x * (meta->mlx->bpp / 8))) = \
		meta->map->ceiling;
		y++;
	}
}
