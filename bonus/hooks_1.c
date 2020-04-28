/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:45:20 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 17:14:57 by abobas        ########   odam.nl         */
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
#define FIRE 14
#define OPEN 12
#define MOUSE 46

int		exit_hook(t_meta *meta)
{
	ft_putstr("Terminating program...\n");
	system("killall afplay");
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
	if (keycode == OPEN)
		meta->data->use = 1;
	if (keycode == FIRE)
	{
		meta->data->fire = 1;
		meta->data->boss_fight = (meta->data->boss_fight == 101) ? 102 : \
		meta->data->boss_fight;
	}
	if (keycode == MOUSE)
		meta->data->mouse = (meta->data->mouse == 1) ? 0 : 1;
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
	if (keycode == OPEN)
		meta->data->use = 0;
	if (keycode == FIRE)
		meta->data->fire = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, t_meta *meta)
{
	if (meta->data->mouse == 1)
	{
		if (button == 1)
			meta->data->mfire = 1;
	}
	x = y;
	return (0);
}

int		mouse_register(int x, int y, t_meta *meta)
{
	if (meta->data->mouse == 1)
	{
		if (x < (meta->map->res_x / 2) - 200)
			meta->data->mrotate_l = 1;
		else if (x > (meta->map->res_x / 2) + 200)
			meta->data->mrotate_r = 1;
	}
	return (y);
}
