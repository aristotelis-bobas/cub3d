/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_8.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 01:37:27 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/10 23:08:42 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <stdlib.h>

void	answer_aspect(t_map *map, char c)
{
	if (c == 'n')
		ft_putstr("\nAspect ratio has not been adjusted.\n");
	else
	{
		map->res_y = (map->res_x / 16) * 9;
		ft_putstr("\nAspect ratio has been adjusted to 16:9.\n");
	}
}

void	choice_aspect(t_map *map)
{
	char	c;
	char	*buf;
	int		i;

	c = '0';
	ft_putstr("The current aspect ratio is not 16:9.\n");
	ft_putstr("Would you like to adjust to an aspect ratio of 16:9?\n");
	ft_putstr("Enter 'y' for yes, enter 'n' for no.\n\n");
	while (c != 'y' && c != 'n')
	{
		buf = (char*)malloc(sizeof(char) * 1);
		if (!buf)
			error(4);
		i = read(0, buf, 1);
		if (i < 0)
			error(5);
		if (i == 1)
			c = buf[0];
		free(buf);
	}
	answer_aspect(map, c);
}

void	answer_small(t_map *map, char c)
{
	if (c == '1')
	{
		map->res_x = 1280;
		map->res_y = 720;
		ft_putstr("\nWindow resolution has been adjusted to 1280 x 720.\n");
	}
	else if (c == '2')
	{
		map->res_x = 1600;
		map->res_y = 900;
		ft_putstr("\nWindow resolution has been adjusted to 1600 x 900.\n");
	}
	else if (c == '3')
	{
		map->res_x = 1920;
		map->res_y = 1080;
		ft_putstr("\nWindow resolution has been adjusted to 1920 x 1080.\n");
	}
}

void	choice_small(t_map *map)
{
	char	c;
	char	*buf;
	int		i;

	c = 'x';
	ft_putstr("Provided window resolution is too small to display game.\n");
	ft_putstr("Please choose a suitable window resolution\n");
	ft_putstr("Enter '1' for a window resolution of 1280 x 720.\n");
	ft_putstr("Enter '2' for a window resolution of 1600 x 900.\n");
	ft_putstr("Enter '3' for a window resolution of 1920 x 1080.\n\n");
	while (c != '1' && c != '2' && c != '3')
	{
		buf = (char*)malloc(sizeof(char) * 1);
		if (!buf)
			error(4);
		i = read(0, buf, 1);
		if (i < 0)
			error(5);
		if (i == 1)
			c = buf[0];
		free(buf);
	}
	answer_small(map, c);
}
