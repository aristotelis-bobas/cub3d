/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_4.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:15:05 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/19 22:45:43 by abobas        ########   odam.nl         */
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
	if (file == 7 && map->f_text)
		error(1);
	if (file == 8 && map->c_text)
		error(1);
	if (file == 9 && map->m_text)
		error(1);
	if (file == 10 && map->sg_text)
		error(1);
}

void	add_path(t_map *map, int file, char *dst)
{
	int		ret;

	ret = open(dst, O_RDONLY);
	if (ret == -1)
		error(1);
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
	if (file == 7)
		map->f_text = dst;
	if (file == 8)
		map->c_text = dst;
	if (file == 9)
		map->m_text = dst;
	if (file == 10)
		map->sg_text = dst;
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
	if (map->f_text)
		check++;
	if (map->c_text)
		check++;
	if (map->m_text)
		check++;
	if (map->sg_text)
		check++;
	if (check == 9)
		ft_putstr("Parsed textures.\n");
}

char	*copy_path(t_map *map, char *map_str)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = map->index;
	while (map_str[i] != ' ' && !(map_str[i] >= 9 && map_str[i] <= 13))
	{
		len++;
		i++;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		error(4);
	i = 0;
	while (map_str[map->index] != ' ' && !(map_str[map->index] >= 9 && \
	map_str[map->index] <= 13))
	{
		str[i] = map_str[map->index];
		map->index++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	parse_path(t_map *map, char *map_str, int file)
{
	char	*str;

	check_path(map, file);
	map->index = (file < 5 || file == 10) ? map->index + 2 : map->index + 1;
	while (map_str[map->index] == ' ')
		map->index++;
	str = copy_path(map, map_str);
	add_path(map, file, str);
	filled_textures(map);
}
