/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_8.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 16:29:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 16:54:28 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_healthbar_background(t_meta *meta)
{
	int		y;
	int		x;

	y = 100;
	while (y < 135)
	{
		x = (meta->map->res_x / 2) - 255;
		while (x < (meta->map->res_x / 2) + 255)
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = 12632256;
			x++;
		}
		y++;
	}
}

int		find_sprite_boss(t_spr *spr)
{
	int		i;

	i = 0;
	while (i < spr->amount)
	{
		if (spr->sprite[i][2] == 4)
			return (i);
		i++;
	}
	return (0);
}

void	put_current_health_boss(t_meta *meta)
{
	int		y;
	int		x;
	int		color;
	int		i;

	i = find_sprite_boss(meta->spr);
	y = 105;
	while (y < 130)
	{
		x = (meta->map->res_x / 2) - 250;
		color = 8190976;
		if (meta->spr->sprite[i][3] < 3333)
			color = (meta->spr->sprite[i][3] > 1777) ? 16746306 : 16722964;
		while (x < (((meta->map->res_x / 2) - 250) + \
		meta->spr->sprite[i][3] / 10))
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = color;
			if (x % 10 == 0)
				color += 1;
			x++;
		}
		y++;
	}
}

void	put_healthbar_boss(t_meta *meta)
{
	put_healthbar_background(meta);
	put_current_health_boss(meta);
}
