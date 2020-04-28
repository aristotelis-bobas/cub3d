/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_4.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:15:05 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/03 22:54:06 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <fcntl.h>

void	check_path(t_map *map, int file)
{
	if (file == 1 && map->n_text)
		error(1);
	if (file == 2 && map->s_text)
		error(1);
	if (file == 3 && map->w_text)
		error(1);
	if (file == 4 && map->e_text)
		error(1);
	if (file == 5 && map->spr_text)
		error(1);
}

void	check_fd(char *path)
{
	int		ret;

	ret = open(path, O_RDONLY);
	if (ret == -1)
		error(1);
}

void	add_path(t_map *map, char *map_str, int file, char *dst)
{
	int		i;

	i = 0;
	while (map_str[map->index] != ' ' && !(map_str[map->index] >= 9 && \
	map_str[map->index] <= 13))
	{
		dst[i] = map_str[map->index];
		map->index++;
		i++;
	}
	dst[i] = '\0';
	check_fd(dst);
	if (file == 1)
		map->n_text = dst;
	if (file == 2)
		map->s_text = dst;
	if (file == 3)
		map->w_text = dst;
	if (file == 4)
		map->e_text = dst;
	if (file == 5)
		map->spr_text = dst;
}

void	filled_textures(t_map *map)
{
	int		check;

	check = 0;
	if (map->n_text)
		check++;
	if (map->s_text)
		check++;
	if (map->w_text)
		check++;
	if (map->e_text)
		check++;
	if (map->spr_text)
		check++;
	if (check == 5)
		ft_putstr("Parsed textures.\n");
}

void	parse_path(t_map *map, char *map_str, int file)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	check_path(map, file);
	map->index = (file < 5) ? map->index + 2 : map->index + 1;
	while (map_str[map->index] == ' ')
		map->index++;
	i = map->index;
	while (map_str[i] != ' ' && !(map_str[i] >= 9 && map_str[i] <= 13))
	{
		len++;
		i++;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		error(4);
	add_path(map, map_str, file, str);
	filled_textures(map);
}
