/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:22:10 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 19:13:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		init_map(void)
{
	t_map	map;

	map.index = 0;
	map.res_x = 0;
	map.res_y = 0;
	map.n_text = 0;
	map.s_text = 0;
	map.e_text = 0;
	map.w_text = 0;
	map.spr_text = 0;
	map.floor = 0;
	map.ceiling = 0;
	map.map_x = 0;
	map.map_y = 0;
	map.spawn_x = 0;
	map.spawn_y = 0;
	map.spawn_or = '0';
	map.grid = 0;
	map.check = 0;
	map.screenshot = 0;
	return (map);
}

void		init_data_2(t_data *data)
{
	data->side = 0;
	data->x = 0;
	data->wall_x = 0;
	data->forward = 0;
	data->backward = 0;
	data->left = 0;
	data->right = 0;
	data->rotate_l = 0;
	data->rotate_r = 0;
}

t_data		init_data(void)
{
	t_data	data;

	data.pos_x = 0;
	data.pos_y = 0;
	data.dir_x = 0;
	data.dir_x_old = 0;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_x_old = 0;
	data.plane_y = 0;
	data.ray_x = 0;
	data.ray_y = 0;
	data.cam_x = 0;
	data.map_y = 0;
	data.map_x = 0;
	data.dist_y = 0;
	data.dist_x = 0;
	data.dist_wall = 0;
	data.delta_x = 0;
	data.delta_y = 0;
	data.step_x = 0;
	data.step_y = 0;
	data.hit = 0;
	init_data_2(&data);
	return (data);
}

t_mlx		init_mlx(void)
{
	t_mlx		mlx;

	mlx.mlx_ptr = 0;
	mlx.mlx_wdw = 0;
	mlx.img_new = 0;
	mlx.img_old = 0;
	mlx.addr = 0;
	mlx.bpp = 0;
	mlx.ls = 0;
	mlx.end = 0;
	mlx.render = 1;
	return (mlx);
}

t_img		init_img(void)
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
