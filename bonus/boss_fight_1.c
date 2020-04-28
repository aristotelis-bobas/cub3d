/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   boss_fight_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 19:47:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 16:50:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"

void	game_win(t_meta *meta)
{
	exchange_img(meta->mlx);
	new_img(meta->mlx, meta->map);
	mlx_put_image_to_window(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	meta->mlx->img_new, 0, 0);
	mlx_string_put(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	(int)(meta->map->res_x / 2.3), (meta->map->res_y / 2), 16777215, \
	"You have killed the final boss. Press ESC to exit.");
	mlx_destroy_image(meta->mlx->mlx_ptr, meta->mlx->img_old);
}

void	check_population(t_meta *meta)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < meta->spr->amount)
	{
		if (meta->spr->sprite[i][2] == 4)
			return ;
		i++;
	}
	if (meta->data->boss_fight < 100 || meta->data->boss_fight >= 102)
		meta->data->boss_fight++;
}

void	new_data(t_data *data)
{
	data->x = 0;
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_x = 0.66;
	data->plane_y = 0;
	data->pos_x = 9.5;
	data->pos_y = 12.5;
	data->shotgun = 0;
	data->minigun = 0;
}

void	fill_struct_boss(t_meta *meta)
{
	free_struct_sprite(meta->spr);
	free_struct_map(meta->map);
	new_map_1(meta->map);
	new_data(meta->data);
	new_sprite_1(meta->spr, meta->tex, meta);
}

void	boss_fight(t_meta *meta)
{
	if (meta->data->boss_fight == 100)
		fill_struct_boss(meta);
	meta->data->boss_fight = 101;
	exchange_img(meta->mlx);
	new_img(meta->mlx, meta->map);
	mlx_put_image_to_window(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	meta->mlx->img_new, 0, 0);
	mlx_string_put(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	(int)(meta->map->res_x / 2.3), (meta->map->res_y / 2), 16777215, \
	"You have killed all enemies. Press E to face the final boss.");
	mlx_destroy_image(meta->mlx->mlx_ptr, meta->mlx->img_old);
}
