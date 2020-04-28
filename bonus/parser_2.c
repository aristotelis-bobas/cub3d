/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:13:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 19:03:38 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_filled(t_map *map)
{
	if (map->res_x == 0 || map->res_y == 0)
		error(1);
	if (!map->n_text || !map->s_text || !map->e_text)
		error(1);
	if (!map->w_text || !map->spr_text)
		error(1);
	if (map->map_x == 0 || map->map_y == 0)
		error(1);
	if (map->spawn_x == 0 || map->spawn_y == 0)
		error(1);
	if (!map->grid || map->spawn_or == 0)
		error(1);
	if (map->f_text == 0 || map->c_text == 0)
		error(1);
	if (map->sg_text == 0 || map->m_text == 0)
		error(1);
}

void	check_string(t_map *map, char *map_str)
{
	if (map_str[map->index] == 'R')
		parse_res(map, map_str);
	else if (map_str[map->index] == 'N' && map_str[map->index + 1] == 'O')
		parse_path(map, map_str, 1);
	else if (map_str[map->index] == 'S' && map_str[map->index + 1] == 'O')
		parse_path(map, map_str, 2);
	else if (map_str[map->index] == 'W' && map_str[map->index + 1] == 'E')
		parse_path(map, map_str, 3);
	else if (map_str[map->index] == 'E' && map_str[map->index + 1] == 'A')
		parse_path(map, map_str, 4);
	else if (map_str[map->index] == 'S' && map_str[map->index + 1] == ' ')
		parse_path(map, map_str, 5);
	else if (map_str[map->index] == 'F')
		parse_path(map, map_str, 7);
	else if (map_str[map->index] == 'C')
		parse_path(map, map_str, 8);
	else if (map_str[map->index] == 'M')
		parse_path(map, map_str, 9);
	else if (map_str[map->index] == 'S' && map_str[map->index + 1] == 'G')
		parse_path(map, map_str, 10);
	else if (map_str[map->index] == '1')
		parse_map(map, map_str);
}

void	parse_file(t_map *map, char *map_str)
{
	while (map_str[map->index] != '\0' && !map->grid)
	{
		check_string(map, map_str);
		if (map_str[map->index] != '\n' && map_str[map->index] != '\0')
			error(1);
		while (map_str[map->index] == '\n')
			map->index++;
	}
	check_filled(map);
}
