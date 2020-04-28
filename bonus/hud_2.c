/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 20:51:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 20:38:02 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	game_over(t_meta *meta)
{
	exchange_img(meta->mlx);
	new_img(meta->mlx, meta->map);
	mlx_put_image_to_window(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	meta->mlx->img_new, 0, 0);
	mlx_string_put(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	(int)(meta->map->res_x / 2.3), (meta->map->res_y / 2), 16777215, \
	"You have died. Press ESC to exit game.");
	mlx_destroy_image(meta->mlx->mlx_ptr, meta->mlx->img_old);
	mlx_loop(meta->mlx->mlx_ptr);
}

int		get_shotgun_texel(t_meta *meta, int x, int y)
{
	int		x_tex;
	int		y_tex;
	int		color;

	x = x - ((meta->map->res_x / 2) - 80);
	y = y - (meta->map->res_y - 200);
	x_tex = (meta->ani->x_sg1 / 160) * x;
	y_tex = (meta->ani->y_sg1 / 200) * y;
	color = *(int*)(meta->ani->addr_sg1 + (y_tex * meta->ani->ls_sg1) + \
	(x_tex * (meta->ani->bpp_sg1 / 8)));
	return (color);
}

void	put_shotgun(t_meta *meta)
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
			color = get_shotgun_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}

void	put_shotgun_fire(t_meta *meta)
{
	int		y;
	int		x;
	int		color;

	y = meta->map->res_y - 320;
	while (y < meta->map->res_y)
	{
		x = (meta->map->res_x / 2) - 80;
		while (x < ((meta->map->res_x / 2) + 80))
		{
			color = get_shotgun_fire_texel(meta, x, y);
			if (color > 0)
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = color;
			x++;
		}
		y++;
	}
}

void	put_shotgun_animation(t_meta *meta)
{
	if (meta->data->weapon_timer < 7)
	{
		put_shotgun_fire(meta);
		if (meta->data->weapon_audio_timer == 0)
			system("afplay fire.mp3 &");
	}
	if (meta->data->weapon_timer >= 7 && meta->data->weapon_timer < 20)
	{
		put_shotgun_shell(meta);
		if (meta->data->weapon_audio_timer == 15)
			system("afplay -v 2 reload.mp3 &");
	}
	if (meta->data->weapon_timer >= 20 && meta->data->weapon_timer < 35)
		put_shotgun_reloaded(meta);
	meta->data->weapon_timer++;
	meta->data->weapon_audio_timer++;
	if (meta->data->weapon_timer == 35)
	{
		meta->data->weapon_timer = 0;
		meta->data->weapon_audio_timer = 0;
	}
}
