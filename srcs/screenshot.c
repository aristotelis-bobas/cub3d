/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 17:48:08 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 17:43:13 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>

void	set_int(unsigned char *header, int value)
{
	header[0] = (unsigned char)(value);
	header[1] = (unsigned char)(value >> 8);
	header[2] = (unsigned char)(value >> 16);
	header[3] = (unsigned char)(value >> 24);
}

void	write_header(int fd, t_meta *meta)
{
	unsigned int		temp;
	static const int	zero[24];
	int					n;

	n = 0;
	n = write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	if (n < 0)
		error(7);
	n = write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	if (n < 0)
		error(7);
	temp = (unsigned int)meta->map->res_x;
	n = write(fd, &temp, 4);
	if (n < 0)
		error(7);
	temp = (unsigned int)meta->map->res_y;
	n = write(fd, &temp, 4);
	if (n < 0)
		error(7);
	n = write(fd, "\x01\x00\x18\x00", 4);
	if (n < 0)
		error(7);
	n = write(fd, zero, 24);
	if (n < 0)
		error(7);
}

void	put_color(t_meta *meta, int y, int x, int fd)
{
	int					color;
	unsigned int		rgb;
	int					n;

	n = 0;
	color = *(int*)(meta->mlx->addr + (y * meta->mlx->ls) + \
	(x * (meta->mlx->bpp / 8)));
	rgb = (color & 0x000000FF);
	n = write(fd, &rgb, 1);
	if (n < 0)
		error(7);
	rgb = ((color & 0x0000FF00) >> 8);
	n = write(fd, &rgb, 1);
	if (n < 0)
		error(7);
	rgb = ((color & 0x00FF0000) >> 16);
	n = write(fd, &rgb, 1);
	if (n < 0)
		error(7);
}

void	write_pixels(int fd, t_meta *meta, int y, int x)
{
	int				pad_size;
	int				n;
	unsigned int	pad;

	pad = 0;
	pad_size = (4 - (meta->map->res_x * 3) % 4) % 4;
	while (y >= 0)
	{
		x = 0;
		while (x < meta->map->res_x)
		{
			put_color(meta, y, x, fd);
			x++;
		}
		if (pad_size > 0)
		{
			n = write(fd, "\x00\x00\x00", pad_size);
			if (n < 0)
				error(7);
		}
		y--;
	}
}

void	make_screenshot(t_meta *meta)
{
	int		fd;
	int		y;
	int		x;

	x = 0;
	y = meta->map->res_y - 1;
	fd = open("screenshot.bmp", (O_WRONLY | O_CREAT | O_TRUNC | \
	O_APPEND), 0666);
	if (fd == -1)
		error(6);
	write_header(fd, meta);
	write_pixels(fd, meta, y, x);
	meta->map->screenshot = 0;
	ft_putstr("Saved screenshot as 'screenshot.bmp' in root directory.\n");
	exit_hook(meta);
}
