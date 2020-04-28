/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_5.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:15:33 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/03 23:35:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			calculate_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		add_color(t_map *map, char *map_str, int object)
{
	int	r;
	int	g;
	int b;

	r = ft_atoi(map_str + map->index);
	map->index = (r != 0) ? map->index + ft_digitcount((unsigned long)r, 10) \
	+ 1 : map->index + 2;
	g = ft_atoi(map_str + map->index);
	map->index = (g != 0) ? map->index + ft_digitcount((unsigned long)g, 10) \
	+ 1 : map->index + 2;
	b = ft_atoi(map_str + map->index);
	map->index = (b != 0) ? map->index + ft_digitcount((unsigned long)b, 10) \
	: map->index + 1;
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error(1);
	if (object == 2)
		map->ceiling = calculate_rgb(r, g, b);
	else if (object == 1)
		map->floor = calculate_rgb(r, g, b);
}

void		check_format(t_map *map, char *map_str)
{
	int		i;
	int		count;
	int		comma;

	i = map->index;
	comma = 0;
	while (map_str[i] != '\n')
	{
		count = 0;
		while (map_str[i] >= '0' && map_str[i] <= '9')
		{
			i++;
			count++;
		}
		comma++;
		if (count > 3 || (comma < 3 && map_str[i] != ','))
			error(1);
		if (comma == 3 && map_str[i] != '\n')
			error(1);
		i++;
	}
}

void		parse_color(t_map *map, char *map_str, int object)
{
	if ((object == 1 && map->floor) || (map->ceiling && object == 2))
		error(1);
	map->index++;
	while (map_str[map->index] == ' ')
		map->index++;
	if (map_str[map->index] < '0' || map_str[map->index] > '9')
		error(1);
	check_format(map, map_str);
	add_color(map, map_str, object);
	if (map->floor && map->ceiling)
		ft_putstr("Parsed window and ceiling colors.\n");
}
