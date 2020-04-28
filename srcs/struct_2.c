/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 22:55:41 by abobas        #+#    #+#                 */
/*   Updated: 2020/01/31 22:56:33 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex_2(t_tex *tex)
{
	tex->tex_e = 0;
	tex->addr_e = 0;
	tex->bpp_e = 0;
	tex->ls_e = 0;
	tex->end_e = 0;
	tex->x_e = 0;
	tex->y_e = 0;
	tex->tex_spr = 0;
	tex->addr_spr = 0;
	tex->bpp_spr = 0;
	tex->ls_spr = 0;
	tex->end_spr = 0;
	tex->x_spr = 0;
	tex->y_spr = 0;
}

t_tex	init_tex(void)
{
	t_tex		tex;

	tex.tex_n = 0;
	tex.addr_n = 0;
	tex.bpp_n = 0;
	tex.ls_n = 0;
	tex.end_n = 0;
	tex.x_n = 0;
	tex.y_n = 0;
	tex.tex_s = 0;
	tex.addr_s = 0;
	tex.bpp_s = 0;
	tex.ls_s = 0;
	tex.end_s = 0;
	tex.x_s = 0;
	tex.y_s = 0;
	tex.tex_w = 0;
	tex.addr_w = 0;
	tex.bpp_w = 0;
	tex.ls_w = 0;
	tex.end_w = 0;
	tex.x_w = 0;
	tex.y_w = 0;
	init_tex_2(&tex);
	return (tex);
}

t_spr	init_spr(void)
{
	t_spr	spr;

	spr.sprite = 0;
	spr.amount = 0;
	spr.distance = 0;
	spr.sprite_x = 0;
	spr.sprite_y = 0;
	spr.inv = 0;
	spr.transform_x = 0;
	spr.transform_y = 0;
	spr.screen_x = 0;
	spr.height = 0;
	spr.start_y = 0;
	spr.end_y = 0;
	spr.start_x = 0;
	spr.end_x = 0;
	spr.stripe = 0;
	spr.tex_x = 0;
	spr.tex_y = 0;
	return (spr);
}
