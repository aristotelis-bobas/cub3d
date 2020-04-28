/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_5.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 23:04:03 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 22:08:49 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	fill_textures_2(t_tex *tex, t_meta *meta)
{
	tex->tex_f = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->f_text, &tex->x_f, &tex->y_f);
	if (!tex->tex_f)
		error(3);
	tex->tex_c = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->c_text, &tex->x_c, &tex->y_c);
	if (!tex->tex_c)
		error(3);
	tex->tex_m = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->m_text, &tex->x_m, &tex->y_m);
	if (!tex->tex_m)
		error(3);
	tex->tex_sg = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->sg_text, &tex->x_sg, &tex->y_sg);
	if (!tex->tex_sg)
		error(3);
	tex->tex_mg = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/minigun.xpm", &tex->x_mg, &tex->y_mg);
	if (!tex->tex_mg)
		error(3);
}

void	fill_textures_1(t_tex *tex, t_meta *meta)
{
	tex->tex_s = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->s_text, &tex->x_s, &tex->y_s);
	if (!tex->tex_s)
		error(3);
	tex->tex_w = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->w_text, &tex->x_w, &tex->y_w);
	if (!tex->tex_w)
		error(3);
	tex->tex_n = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->n_text, &tex->x_n, &tex->y_n);
	if (!tex->tex_n)
		error(3);
	tex->tex_e = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->e_text, &tex->x_e, &tex->y_e);
	if (!tex->tex_e)
		error(3);
	tex->tex_spr = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	meta->map->spr_text, &tex->x_spr, &tex->y_spr);
	if (!tex->tex_spr)
		error(3);
}

void	free_tex_path(t_meta *meta)
{
	free(meta->map->s_text);
	free(meta->map->n_text);
	free(meta->map->w_text);
	free(meta->map->e_text);
	free(meta->map->spr_text);
	free(meta->map->f_text);
	free(meta->map->c_text);
	free(meta->map->sg_text);
	free(meta->map->m_text);
}

void	fill_tex_addr(t_tex *tex)
{
	tex->addr_s = mlx_get_data_addr(tex->tex_s, &tex->bpp_s, \
	&tex->ls_s, &tex->end_s);
	tex->addr_n = mlx_get_data_addr(tex->tex_n, &tex->bpp_n, \
	&tex->ls_n, &tex->end_n);
	tex->addr_w = mlx_get_data_addr(tex->tex_w, &tex->bpp_w, \
	&tex->ls_w, &tex->end_w);
	tex->addr_e = mlx_get_data_addr(tex->tex_e, &tex->bpp_e, \
	&tex->ls_e, &tex->end_e);
	tex->addr_spr = mlx_get_data_addr(tex->tex_spr, &tex->bpp_spr, \
	&tex->ls_spr, &tex->end_spr);
	tex->addr_f = mlx_get_data_addr(tex->tex_f, &tex->bpp_f, \
	&tex->ls_f, &tex->end_f);
	tex->addr_c = mlx_get_data_addr(tex->tex_c, &tex->bpp_c, \
	&tex->ls_c, &tex->end_c);
	tex->addr_m = mlx_get_data_addr(tex->tex_m, &tex->bpp_m, \
	&tex->ls_m, &tex->end_m);
	tex->addr_sg = mlx_get_data_addr(tex->tex_sg, &tex->bpp_sg, \
	&tex->ls_sg, &tex->end_sg);
	tex->addr_mg = mlx_get_data_addr(tex->tex_mg, &tex->bpp_mg, \
	&tex->ls_mg, &tex->end_mg);
}

void	fill_tex(t_tex *tex, t_meta *meta)
{
	fill_textures_1(tex, meta);
	fill_textures_2(tex, meta);
	fill_tex_addr(tex);
	free_tex_path(meta);
}
