/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:12:58 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/02 22:22:48 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(int fd, char *dst)
{
	char	*buf;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		buf = (char*)malloc(sizeof(char) * 1001);
		if (!buf)
			error(4);
		ret = read(fd, buf, 1000);
		if (ret < 0)
			error(5);
		buf[ret] = '\0';
		dst = ft_strcat(dst, buf);
		if (!dst)
			error(4);
	}
	return (dst);
}

void	parse(char *av, t_map *map, t_data *data, t_spr *spr)
{
	int		fd;
	char	*map_str;

	ft_putstr("Parsing file...\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error(1);
	map_str = ft_strdup("");
	if (!map_str)
		error(4);
	map_str = read_file(fd, map_str);
	parse_file(map, map_str);
	free(map_str);
	fill_data(data, map);
	fill_spr(spr, map);
	ft_putstr("Succesfully parsed file.\n");
}
