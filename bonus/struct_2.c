/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 22:55:41 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 22:07:38 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex_4(t_tex *tex)
{
	tex->tex_sg = 0;
	tex->addr_sg = 0;
	tex->bpp_sg = 0;
	tex->ls_sg = 0;
	tex->end_sg = 0;
	tex->x_sg = 0;
	tex->y_sg = 0;
	tex->tex_mg = 0;
	tex->addr_mg = 0;
	tex->bpp_mg = 0;
	tex->ls_mg = 0;
	tex->end_mg = 0;
	tex->x_mg = 0;
	tex->y_mg = 0;
}

void	init_tex_3(t_tex *tex)
{
	tex->x_w = 0;
	tex->tex_f = 0;
	tex->addr_f = 0;
	tex->bpp_f = 0;
	tex->ls_f = 0;
	tex->end_f = 0;
	tex->x_f = 0;
	tex->y_f = 0;
	tex->tex_c = 0;
	tex->addr_c = 0;
	tex->bpp_c = 0;
	tex->ls_c = 0;
	tex->end_c = 0;
	tex->x_c = 0;
	tex->y_c = 0;
	tex->tex_m = 0;
	tex->addr_m = 0;
	tex->bpp_m = 0;
	tex->ls_m = 0;
	tex->end_m = 0;
	tex->x_m = 0;
	tex->y_m = 0;
}

void	init_tex_2(t_tex *tex)
{
	tex->y_w = 0;
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
	init_tex_2(&tex);
	init_tex_3(&tex);
	init_tex_4(&tex);
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
	spr.audio_timer = 0;
	spr.dir_x = 0;
	spr.dir_y = 0;
	return (spr);
}
