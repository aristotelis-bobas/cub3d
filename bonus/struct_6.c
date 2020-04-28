/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_6.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 21:33:37 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 22:00:08 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"

void	get_addr_ani(t_ani *ani)
{
	ani->addr_sg1 = mlx_get_data_addr(ani->sg_1, &ani->bpp_sg1, \
	&ani->ls_sg1, &ani->end_sg1);
	ani->addr_sg2 = mlx_get_data_addr(ani->sg_2, &ani->bpp_sg2, \
	&ani->ls_sg2, &ani->end_sg2);
	ani->addr_sg3 = mlx_get_data_addr(ani->sg_3, &ani->bpp_sg3, \
	&ani->ls_sg3, &ani->end_sg3);
	ani->addr_sg4 = mlx_get_data_addr(ani->sg_4, &ani->bpp_sg4, \
	&ani->ls_sg4, &ani->end_sg4);
	ani->addr_ex1 = mlx_get_data_addr(ani->ex_1, &ani->bpp_ex1, \
	&ani->ls_ex1, &ani->end_ex1);
	ani->addr_ex2 = mlx_get_data_addr(ani->ex_2, &ani->bpp_ex2, \
	&ani->ls_ex2, &ani->end_ex2);
	ani->addr_ex3 = mlx_get_data_addr(ani->ex_3, &ani->bpp_ex3, \
	&ani->ls_ex3, &ani->end_ex3);
	ani->addr_ex4 = mlx_get_data_addr(ani->ex_4, &ani->bpp_ex4, \
	&ani->ls_ex4, &ani->end_ex4);
	ani->addr_mg1 = mlx_get_data_addr(ani->mg_1, &ani->bpp_mg1, \
	&ani->ls_mg1, &ani->end_mg1);
	ani->addr_mg2 = mlx_get_data_addr(ani->mg_2, &ani->bpp_mg2, \
	&ani->ls_mg2, &ani->end_mg2);
	ani->addr_mg3 = mlx_get_data_addr(ani->mg_3, &ani->bpp_mg3, \
	&ani->ls_mg3, &ani->end_mg3);
}

void	get_image_ani_1(t_ani *ani, t_meta *meta)
{
	ani->sg_1 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_shotgun_1.xpm", &ani->x_sg1, &ani->y_sg1);
	if (!ani->sg_1)
		error(3);
	ani->sg_2 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_shotgun_2.xpm", &ani->x_sg2, &ani->y_sg2);
	if (!ani->sg_2)
		error(3);
	ani->sg_3 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_shotgun_3.xpm", &ani->x_sg3, &ani->y_sg3);
	if (!ani->sg_3)
		error(3);
	ani->sg_4 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_shotgun_4.xpm", &ani->x_sg4, &ani->y_sg4);
	if (!ani->sg_4)
		error(3);
	ani->mg_1 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_minigun_1.xpm", &ani->x_mg1, &ani->y_mg1);
	if (!ani->mg_1)
		error(3);
}

void	get_image_ani_2(t_ani *ani, t_meta *meta)
{
	ani->mg_2 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_minigun_2.xpm", &ani->x_mg2, &ani->y_mg2);
	if (!ani->mg_2)
		error(3);
	ani->mg_3 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_minigun_3.xpm", &ani->x_mg3, &ani->y_mg3);
	if (!ani->mg_3)
		error(3);
	ani->ex_1 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_explosion_1.xpm", &ani->x_ex1, &ani->y_ex1);
	if (!ani->ex_1)
		error(3);
	ani->ex_2 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_explosion_2.xpm", &ani->x_ex2, &ani->y_ex2);
	if (!ani->ex_2)
		error(3);
	ani->ex_3 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_explosion_3.xpm", &ani->x_ex3, &ani->y_ex3);
	if (!ani->ex_3)
		error(3);
	ani->ex_4 = mlx_xpm_file_to_image(meta->mlx->mlx_ptr, \
	"./textures/animation_explosion_4.xpm", &ani->x_ex4, &ani->y_ex4);
	if (!ani->ex_4)
		error(3);
}

t_ani	init_ani(t_meta *meta)
{
	t_ani	ani;

	get_image_ani_1(&ani, meta);
	get_image_ani_2(&ani, meta);
	get_addr_ani(&ani);
	return (ani);
}

t_img	init_img(void)
{
	t_img		img;

	img.line_height = 0;
	img.draw_start = 0;
	img.draw_end = 0;
	img.wall_height = 0;
	img.tex_x = 0;
	img.tex_y = 0;
	img.step = 0;
	img.tex_pos = 0;
	return (img);
}
