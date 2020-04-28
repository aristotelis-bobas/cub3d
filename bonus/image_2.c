/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:24:18 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/19 22:42:17 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_position(t_map *map, t_data *data, t_img *img)
{
	img->wall_height = map->res_y;
	img->line_height = 1.5 * (int)(img->wall_height / data->dist_wall\
	[data->x]);
	img->draw_start = -(img->line_height / 2) + (img->wall_height / 2);
	if (img->draw_start < 0)
		img->draw_start = 0;
	img->draw_end = (img->line_height / 2) + (img->wall_height / 2);
	if (img->draw_end >= img->wall_height)
		img->draw_end = img->wall_height - 1;
}

void	texture_position_x(t_img *img, t_tex *tex, t_data *data)
{
	if (data->wall_or == 'S')
		img->tex_x = (int)(data->wall_x * (double)tex->x_s);
	else if (data->wall_or == 'N')
		img->tex_x = (int)(data->wall_x * (double)tex->x_n);
	else if (data->wall_or == 'W')
		img->tex_x = (int)(data->wall_x * (double)tex->x_w);
	else if (data->wall_or == 'E')
		img->tex_x = (int)(data->wall_x * (double)tex->x_e);
}

void	texture_position_y(t_img *img, t_tex *tex, t_data *data)
{
	if (data->wall_or == 'S')
		img->step = 1.0 * tex->y_s / img->line_height;
	else if (data->wall_or == 'N')
		img->step = 1.0 * tex->y_n / img->line_height;
	else if (data->wall_or == 'W')
		img->step = 1.0 * tex->y_w / img->line_height;
	else if (data->wall_or == 'E')
		img->step = 1.0 * tex->y_e / img->line_height;
	img->tex_pos = (img->draw_start - (img->wall_height / 2) + \
	(img->line_height / 2)) * img->step;
}

void	floor_position(t_data *data)
{
	if (data->side == 0 && data->ray_x > 0)
	{
		data->floor_x = data->map_x;
		data->floor_y = data->map_y + data->wall_x;
	}
	else if (data->side == 0 && data->ray_x < 0)
	{
		data->floor_x = data->map_x + 1.0;
		data->floor_y = data->map_y + data->wall_x;
	}
	else if (data->side == 1 && data->ray_y > 0)
	{
		data->floor_x = data->map_x + data->wall_x;
		data->floor_y = data->map_y;
	}
	else
	{
		data->floor_x = data->map_x + data->wall_x;
		data->floor_y = data->map_y + 1.0;
	}
}

void	image_calculations(t_meta *meta)
{
	differential_analysis(meta->map, meta->data);
	image_position(meta->map, meta->data, meta->img);
	texture_position_x(meta->img, meta->tex, meta->data);
	texture_position_y(meta->img, meta->tex, meta->data);
	floor_position(meta->data);
}
