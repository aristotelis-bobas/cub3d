/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_7.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 22:28:11 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 23:01:54 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_minigun_rot_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 220);
	y = y - (meta->map->res_y - 330);
	x_tex = (meta->ani->x_mg3 / 400) * x;
	y_tex = (meta->ani->y_mg3 / 300) * y;
	color = *(int*)(meta->ani->addr_mg3 + (y_tex * meta->ani->ls_mg3) + \
	(x_tex * (meta->ani->bpp_mg3 / 8)));
	return (color);
}

void	put_minigun_rot(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 330;
	while (y < (meta->map->res_y - 30))
	{
		x = (meta->map->res_x / 2) - 220;
		while (x < ((meta->map->res_x / 2) + 180))
		{
			color = get_minigun_rot_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}
