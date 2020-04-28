/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:24:31 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 17:42:59 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"

void	execute_hook(t_meta *meta)
{
	if (meta->data->forward)
		move_forward(meta->data, meta->map);
	if (meta->data->backward)
		move_backward(meta->data, meta->map);
	if (meta->data->left)
		move_left(meta->data, meta->map);
	if (meta->data->right)
		move_right(meta->data, meta->map);
	if (meta->data->rotate_l)
		rotate_left(meta->data);
	if (meta->data->rotate_r)
		rotate_right(meta->data);
}

void	exchange_img(t_mlx *mlx)
{
	mlx->img_old = mlx->img_new;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_wdw, mlx->img_old, 0, 0);
}

void	new_img(t_mlx *mlx, t_map *map)
{
	mlx->img_new = mlx_new_image(mlx->mlx_ptr, map->res_x, map->res_y);
	if (!mlx->img_new)
		error(3);
	mlx->addr = mlx_get_data_addr(mlx->img_new, &mlx->bpp, &mlx->ls, \
	&mlx->end);
}

void	check_render(t_meta *meta)
{
	if (meta->data->forward)
		meta->mlx->render = 1;
	if (meta->data->backward)
		meta->mlx->render = 1;
	if (meta->data->left)
		meta->mlx->render = 1;
	if (meta->data->right)
		meta->mlx->render = 1;
	if (meta->data->rotate_l)
		meta->mlx->render = 1;
	if (meta->data->rotate_r)
		meta->mlx->render = 1;
}

int		image(t_meta *meta)
{
	check_render(meta);
	if (!meta->mlx->render)
		return (0);
	execute_hook(meta);
	if (meta->mlx->img_new)
		exchange_img(meta->mlx);
	new_img(meta->mlx, meta->map);
	while (meta->data->x < meta->map->res_x)
	{
		image_calculations(meta);
		build_image(meta);
		meta->data->x++;
	}
	if (meta->spr->amount > 0)
		draw_sprite(meta);
	if (meta->map->screenshot)
		make_screenshot(meta);
	mlx_put_image_to_window(meta->mlx->mlx_ptr, meta->mlx->mlx_wdw, \
	meta->mlx->img_new, 0, 0);
	if (meta->mlx->img_old)
		mlx_destroy_image(meta->mlx->mlx_ptr, meta->mlx->img_old);
	meta->data->x = 0;
	meta->mlx->render = 0;
	return (0);
}
