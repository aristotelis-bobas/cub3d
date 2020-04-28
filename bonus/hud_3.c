/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 23:14:25 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/17 00:11:35 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_shotgun_fire_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 80);
	y = y - (meta->map->res_y - 320);
	x_tex = (meta->ani->x_sg2 / 160) * x;
	y_tex = (meta->ani->y_sg2 / 200) * y;
	color = *(int*)(meta->ani->addr_sg2 + (y_tex * meta->ani->ls_sg2) + \
	(x_tex * (meta->ani->bpp_sg2 / 8)));
	return (color);
}

int		get_shotgun_shell_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 80);
	y = y - (meta->map->res_y - 200);
	x_tex = (meta->ani->x_sg3 / 160) * x;
	y_tex = (meta->ani->y_sg3 / 200) * y;
	color = *(int*)(meta->ani->addr_sg3 + (y_tex * meta->ani->ls_sg3) + \
	(x_tex * (meta->ani->bpp_sg3 / 8)));
	return (color);
}

void	put_shotgun_shell(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 200;
	while (y < meta->map->res_y)
	{
		x = (meta->map->res_x / 2) - 80;
		while (x < ((meta->map->res_x / 2) + 80))
		{
			color = get_shotgun_shell_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}

int		get_shotgun_reloaded_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 80);
	y = y - (meta->map->res_y - 200);
	x_tex = (meta->ani->x_sg4 / 160) * x;
	y_tex = (meta->ani->y_sg4 / 200) * y;
	color = *(int*)(meta->ani->addr_sg4 + (y_tex * meta->ani->ls_sg4) + \
	(x_tex * (meta->ani->bpp_sg4 / 8)));
	return (color);
}

void	put_shotgun_reloaded(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 200;
	while (y < meta->map->res_y)
	{
		x = (meta->map->res_x / 2) - 80;
		while (x < ((meta->map->res_x / 2) + 80))
		{
			color = get_shotgun_reloaded_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}
