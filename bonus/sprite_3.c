/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 17:33:54 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/25 23:19:13 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int		sprite_collision(t_spr *spr, int i)
{
	int		y;
	int		counter;

	y = 0;
	while (y < spr->amount)
	{
		if (y == i)
			y++;
		if (y == spr->amount)
			break ;
		if ((spr->sprite[i][1] + (spr->dir_x * 0.2)) < (spr->sprite[y]\
		[1] + 0.2) && (spr->sprite[i][1] + (spr->dir_x * 0.2)) > \
		(spr->sprite[y][1] - 0.2))
			counter++;
		if ((spr->sprite[i][0] + (spr->dir_y * 0.2)) < (spr->sprite[y]\
		[0] + 0.2) && (spr->sprite[i][0] + (spr->dir_x * 0.2)) > \
		(spr->sprite[y][0] - 0.1))
			counter++;
		if (counter == 2)
			return (1);
		counter = 0;
		y++;
	}
	return (0);
}

void	direction_sprite(t_spr *spr, t_data *data, int i)
{
	spr->dir_x = (data->pos_x > spr->sprite[i][1]) ? 1 : -1;
	if (spr->sprite[i][1] < data->pos_x + 0.05 && spr->sprite[i][1] > \
	data->pos_x - 0.05)
		spr->dir_x = 0;
	spr->dir_y = (data->pos_y > spr->sprite[i][0]) ? 1 : -1;
	if (spr->sprite[i][0] < data->pos_y + 0.05 && spr->sprite[i][0] > \
	data->pos_y - 0.05)
		spr->dir_y = 0;
}

void	move_sprite(t_spr *spr, t_data *data, t_map *map, int i)
{
	direction_sprite(spr, data, i);
	if (spr->distance[i] > 0.2 && spr->distance[i] < 200)
	{
		if (map->grid[(int)spr->sprite[i][0]][(int)(spr->sprite[i][1] + \
		(spr->dir_x * 0.3))] == 0 && !sprite_collision(spr, i))
			spr->sprite[i][1] = spr->sprite[i][1] + (spr->dir_x * 0.04);
		if (map->grid[(int)(spr->sprite[i][0] + (spr->dir_y * 0.3))]	\
		[(int)spr->sprite[i][1]] == 0 && !sprite_collision(spr, i))
			spr->sprite[i][0] = spr->sprite[i][0] + (spr->dir_y * 0.04);
		if (spr->audio_timer == 0 && spr->distance[i] < 50)
			system("afplay -v 0.8 xeno.mp3 &");
		else if (spr->audio_timer == 0 && spr->distance[i] > 50)
			system("afplay -v 0.5 xeno.mp3 &");
		spr->audio_timer = (spr->audio_timer == 1000) ? 0 : \
		spr->audio_timer + 1;
	}
	if (spr->distance[i] < 0.5 && data->hit_event == 0)
	{
		data->hit_event = 1;
		system("afplay screech.mp3 &");
	}
}

void	check_object(t_spr *spr, t_data *data)
{
	int		i;

	i = 0;
	while (i < spr->amount)
	{
		if (spr->sprite[i][2] == 5 && spr->distance[i] < 0.3)
		{
			data->health = data->health + 50;
			if (data->health > 100)
				data->health = 100;
			spr->sprite[i][0] = 0;
			spr->sprite[i][1] = 0;
			spr->sprite[i][2] = 0;
			system("afplay -v 2.0 medkit.mp3 &");
			return ;
		}
		else
			check_object_2(spr, data, i);
		i++;
	}
}

void	substitute_sprite(t_spr *spr, int i)
{
	double		temp[6];

	temp[0] = spr->sprite[i + 1][0];
	temp[1] = spr->sprite[i + 1][1];
	temp[2] = spr->sprite[i + 1][2];
	temp[3] = spr->distance[i + 1];
	temp[4] = spr->sprite[i + 1][3];
	temp[5] = spr->sprite[i + 1][4];
	spr->distance[i + 1] = spr->distance[i];
	spr->sprite[i + 1][0] = spr->sprite[i][0];
	spr->sprite[i + 1][1] = spr->sprite[i][1];
	spr->sprite[i + 1][2] = spr->sprite[i][2];
	spr->sprite[i + 1][3] = spr->sprite[i][3];
	spr->sprite[i + 1][4] = spr->sprite[i][4];
	spr->distance[i] = temp[3];
	spr->sprite[i][0] = temp[0];
	spr->sprite[i][1] = temp[1];
	spr->sprite[i][2] = temp[2];
	spr->sprite[i][3] = temp[4];
	spr->sprite[i][4] = temp[5];
}
