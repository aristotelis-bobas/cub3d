/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_5.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:53:15 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/20 19:35:21 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_minimap_background(t_meta *meta)
{
	int		y;
	int		x;

	y = meta->map->res_y - 205;
	while (y <= meta->map->res_y - 45)
	{
		x = meta->map->res_x - 205;
		while (x <= meta->map->res_x - 45)
		{
			*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
			(meta->mlx->bpp / 8))) = 12632256;
			if ((y <= meta->map->res_y - 123 && y >= meta->map->res_y - 127) \
			&& (x <= meta->map->res_x - 123 && x >= meta->map->res_x - 127))
				*(int*)(meta->mlx->addr + (y * meta->mlx->ls) + (x * \
				(meta->mlx->bpp / 8))) = 0x0000FF;
			x++;
		}
		y++;
	}
}

void	put_wall(t_mini *mini, t_meta *meta, int y, int x)
{
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;

	start_y = meta->map->res_y - 200 + ((y - mini->start_y) * 10);
	end_x = meta->map->res_x - 190 + ((x - mini->start_x) * 10);
	end_y = meta->map->res_y - 190 + ((y - mini->start_y) * 10);
	while (start_y <= end_y)
	{
		start_x = meta->map->res_x - 200 + ((x - mini->start_x) * 10);
		while (start_x <= end_x)
		{
			*(int*)(meta->mlx->addr + (start_y * meta->mlx->ls) + \
			(start_x * (meta->mlx->bpp / 8))) = 0;
			start_x++;
		}
		start_y++;
	}
}

void	put_secret_wall(t_mini *mini, t_meta *meta, int y, int x)
{
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;

	start_y = meta->map->res_y - 200 + ((y - mini->start_y) * 10);
	end_x = meta->map->res_x - 190 + ((x - mini->start_x) * 10);
	end_y = meta->map->res_y - 190 + ((y - mini->start_y) * 10);
	while (start_y <= end_y)
	{
		start_x = meta->map->res_x - 200 + ((x - mini->start_x) * 10);
		while (start_x <= end_x)
		{
			*(int*)(meta->mlx->addr + (start_y * meta->mlx->ls) + \
			(start_x * (meta->mlx->bpp / 8))) = 0xFF0000;
			start_x++;
		}
		start_y++;
	}
}

void	put_minimap_walls(t_mini *mini, t_meta *meta)
{
	int		y;
	int		x;

	y = mini->start_y;
	while (y <= mini->end_y)
	{
		x = mini->start_x;
		while (x <= mini->end_x)
		{
			if (y >= 0 && y < meta->map->map_y)
			{
				if (x >= 0 && x < meta->map->map_x[y])
				{
					if (meta->map->grid[y][x] == 1)
						put_wall(mini, meta, y, x);
					if (meta->map->grid[y][x] == 2)
						put_secret_wall(mini, meta, y, x);
				}
			}
			x++;
		}
		y++;
	}
}

void	put_minimap(t_meta *meta)
{
	t_mini	mini;

	mini = init_mini(meta);
	put_minimap_background(meta);
	put_minimap_walls(&mini, meta);
}
