/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_7.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 23:04:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/20 19:33:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mini	init_mini(t_meta *meta)
{
	t_mini	mini;

	mini.start_x = (int)meta->data->pos_x - 7;
	mini.start_y = (int)meta->data->pos_y - 7;
	mini.end_y = mini.start_y + 14;
	mini.end_x = mini.start_x + 14;
	return (mini);
}
