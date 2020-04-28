/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_4.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 21:44:26 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/18 22:01:35 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_top(t_meta *meta)
{
	int		y;
	int		x;

	y = (meta->map->res_y / 2) - 15;
	while (y <= (meta->map->res_y / 2) - 1)
	{
		x = (meta->map->res_x / 2) - 1;
		while (x < ((meta->map->res_x / 2) + 1))
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = 0xFF0000;
			x++;
		}
		y++;
	}
}

void	put_mid(t_meta *meta)
{
	int		y;
	int		x;

	y = meta->map->res_y / 2;
	while (y <= (meta->map->res_y / 2) + 1)
	{
		x = (meta->map->res_x / 2) - 15;
		while (x < ((meta->map->res_x / 2) + 15))
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = 0xFF0000;
			x++;
		}
		y++;
	}
}

void	put_bottom(t_meta *meta)
{
	int		y;
	int		x;

	y = (meta->map->res_y / 2) + 1;
	while (y <= (meta->map->res_y / 2) + 15)
	{
		x = (meta->map->res_x / 2) - 1;
		while (x < ((meta->map->res_x / 2) + 1))
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = 0xFF0000;
			x++;
		}
		y++;
	}
}

void	put_crosshair(t_meta *meta)
{
	put_top(meta);
	put_mid(meta);
	put_bottom(meta);
}
