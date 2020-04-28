/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   boss_fight_3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 18:47:15 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 23:06:33 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	new_sprite_3(t_spr *spr)
{
	spr->sprite[0][0] = 12.5;
	spr->sprite[0][1] = 5.5;
	spr->sprite[0][2] = 5;
	spr->sprite[1][0] = 2.5;
	spr->sprite[1][1] = 7.5;
	spr->sprite[1][2] = 4;
	spr->sprite[1][3] = 5000;
	spr->sprite[2][0] = 11.5;
	spr->sprite[2][1] = 5.5;
	spr->sprite[2][2] = 8;
}

void	new_sprite_2(t_spr *spr)
{
	int		i;

	i = 0;
	spr->amount = 3;
	spr->sprite = (double**)malloc(sizeof(double*) * spr->amount);
	if (!spr->sprite)
		error(4);
	while (i < spr->amount)
	{
		spr->sprite[i] = (double*)malloc(sizeof(double) * 5);
		if (!spr->sprite[i])
			error(4);
		i++;
	}
	spr->distance = (double*)malloc(sizeof(double) * spr->amount);
	if (!spr->distance)
		error(4);
	new_sprite_3(spr);
}

void	new_textures(t_tex *tex, t_meta *meta)
{
	tex->tex_spr = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/haedexebus.xpm", &tex->x_spr, &tex->y_spr);
	if (!tex->tex_spr)
		error(3);
	tex->addr_spr = mlx_get_data_addr(tex->tex_spr, &tex->bpp_spr, \
	&tex->ls_spr, &tex->end_spr);
}

void	new_sprite_1(t_spr *spr, t_tex *tex, t_meta *meta)
{
	new_textures(tex, meta);
	new_sprite_2(spr);
}
