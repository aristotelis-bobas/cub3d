/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:14:23 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/03 23:25:21 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	add_res_2(t_map *map, char *res, int axis)
{
	int		tmp;

	tmp = ft_atoi(res);
	free(res);
	if ((tmp > 2560 || tmp < 0) && axis == 1)
	{
		tmp = 2560;
		ft_putstr("Provided window width was too large.\n");
		ft_putstr("Window width has been set to 2560.\n");
	}
	if ((tmp > 1440 || tmp < 0) && axis == 2)
	{
		tmp = 1440;
		ft_putstr("Provided window height was too large.\n");
		ft_putstr("Window height has been set to 1440.\n");
	}
	if (axis == 1)
		map->res_x = tmp;
	else if (axis == 2)
		map->res_y = tmp;
}

void	add_res_1(t_map *map, char *map_str, int axis)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = map->index;
	while (map_str[i] >= '0' && map_str[i] <= '9')
	{
		len++;
		i++;
	}
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		error(4);
	while (map_str[map->index] >= '0' && map_str[map->index] <= '9')
	{
		str[i] = map_str[map->index];
		i++;
		map->index++;
	}
	str[i] = '\0';
	add_res_2(map, str, axis);
}

void	parse_res(t_map *map, char *map_str)
{
	if (map->res_y || map->res_x)
		error(1);
	map->index++;
	while (map_str[map->index] == ' ')
		map->index++;
	if (map_str[map->index] < '1' || map_str[map->index] > '9')
		error(1);
	else
		add_res_1(map, map_str, 1);
	if (map_str[map->index] != ' ')
		error(1);
	while (map_str[map->index] == ' ')
		map->index++;
	if (map_str[map->index] < '1' || map_str[map->index] > '9')
		error(1);
	else
		add_res_1(map, map_str, 2);
	if (((map->res_x / 16) * 9) != map->res_y)
		choice_aspect(map);
	if (map->res_x < 1280 || map->res_y < 720)
		choice_small(map);
	ft_putstr("Parsed window resolution.\n");
}
