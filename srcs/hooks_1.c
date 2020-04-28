/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:45:20 by abobas        #+#    #+#                 */
/*   Updated: 2020/01/30 22:16:16 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#define ESC 53
#define FWD 13
#define BWD 1
#define STR_L 0
#define STR_R 2
#define ROT_L 123
#define ROT_R 124

int		exit_hook(t_meta *meta)
{
	ft_putstr("Terminating program...\n");
	exit(0);
	meta->map->res_y = 1;
	return (0);
}

int		key_press(int keycode, t_meta *meta)
{
	if (keycode == ESC)
		exit_hook(meta);
	if (keycode == FWD && meta->data->backward != 1)
		meta->data->forward = 1;
	if (keycode == BWD && meta->data->forward != 1)
		meta->data->backward = 1;
	if (keycode == STR_L && meta->data->right != 1)
		meta->data->left = 1;
	if (keycode == STR_R && meta->data->left != 1)
		meta->data->right = 1;
	if (keycode == ROT_L && meta->data->rotate_r != 1)
		meta->data->rotate_l = 1;
	if (keycode == ROT_R && meta->data->rotate_l != 1)
		meta->data->rotate_r = 1;
	return (0);
}

int		key_release(int keycode, t_meta *meta)
{
	if (keycode == FWD)
		meta->data->forward = 0;
	if (keycode == BWD)
		meta->data->backward = 0;
	if (keycode == STR_L)
		meta->data->left = 0;
	if (keycode == STR_R)
		meta->data->right = 0;
	if (keycode == ROT_L)
		meta->data->rotate_l = 0;
	if (keycode == ROT_R)
		meta->data->rotate_r = 0;
	return (0);
}
