/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_5.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 23:04:03 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/01 23:08:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	fill_tex_mlx_2(t_tex *tex, t_meta *meta, char c)
{
	if (c == 'S')
	{
		if (meta->map->s_text[ft_strlen(meta->map->s_text) - 1] == 'm')
			tex->tex_s = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->s_text, &tex->x_s, &tex->y_s);
		else
			tex->tex_s = mlx_png_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->s_text, &tex->x_s, &tex->y_s);
	}
	else if (c == 'W')
	{
		if (meta->map->w_text[ft_strlen(meta->map->w_text) - 1] == 'm')
			tex->tex_w = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->w_text, &tex->x_w, &tex->y_w);
		else
			tex->tex_w = mlx_png_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->w_text, &tex->x_w, &tex->y_w);
	}
}

void	fill_tex_mlx_1(t_tex *tex, t_meta *meta, char c)
{
	if (c == 'N')
	{
		if (meta->map->n_text[ft_strlen(meta->map->n_text) - 1] == 'm')
			tex->tex_n = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->n_text, &tex->x_n, &tex->y_n);
		else
			tex->tex_n = mlx_png_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->n_text, &tex->x_n, &tex->y_n);
	}
	else if (c == 'E')
	{
		if (meta->map->e_text[ft_strlen(meta->map->e_text) - 1] == 'm')
			tex->tex_e = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->e_text, &tex->x_e, &tex->y_e);
		else
			tex->tex_e = mlx_png_file_to_image(meta->mlx->mlx_ptr, \
			meta->map->e_text, &tex->x_e, &tex->y_e);
	}
}

void	fill_tex_walls(t_tex *tex, t_meta *meta)
{
	fill_tex_mlx_1(tex, meta, 'N');
	free(meta->map->n_text);
	if (!tex->tex_n)
		error(3);
	fill_tex_mlx_2(tex, meta, 'W');
	free(meta->map->w_text);
	if (!tex->tex_w)
		error(3);
	fill_tex_mlx_2(tex, meta, 'S');
	free(meta->map->s_text);
	if (!tex->tex_s)
		error(3);
	fill_tex_mlx_1(tex, meta, 'E');
	free(meta->map->e_text);
	if (!tex->tex_e)
		error(3);
}

void	fill_tex_sprite(t_tex *tex, t_meta *meta)
{
	if (meta->map->spr_text[ft_strlen(meta->map->spr_text) - 1] == 'm')
	{
		tex->tex_spr = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
		meta->map->spr_text, &tex->x_spr, &tex->y_spr);
	}
	else
	{
		tex->tex_spr = mlx_png_file_to_image(meta->mlx->mlx_ptr, \
		meta->map->spr_text, &tex->x_spr, &tex->y_spr);
	}
	if (!tex->tex_spr)
		error(3);
	free(meta->map->spr_text);
}

void	fill_tex(t_tex *tex, t_meta *meta)
{
	fill_tex_walls(tex, meta);
	fill_tex_sprite(tex, meta);
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
}
