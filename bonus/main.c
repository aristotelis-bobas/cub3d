/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:17:00 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 17:39:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	game_loop(t_mlx *mlx, t_meta *meta)
{
	if (meta->map->screenshot == 0)
	{
		ft_putstr("Spawning in map now.\n");
		mlx->mlx_wdw = mlx_new_window(mlx->mlx_ptr, meta->map->res_x, \
		meta->map->res_y, "cub3D");
		if (!mlx->mlx_wdw)
			error(3);
		mlx_hook(mlx->mlx_wdw, 17, 0, &exit_hook, meta);
		mlx_hook(mlx->mlx_wdw, 2, 0, &key_press, meta);
		mlx_hook(mlx->mlx_wdw, 3, 0, &key_release, meta);
		mlx_hook(mlx->mlx_wdw, 6, 0, &mouse_register, meta);
		mlx_mouse_hook(mlx->mlx_wdw, &mouse_press, meta);
	}
	mlx_loop_hook(mlx->mlx_ptr, &image, meta);
	system("afplay soundtrack.mp3 &");
	mlx_loop(mlx->mlx_ptr);
}

void	run(t_meta *meta)
{
	t_mlx	mlx;
	t_tex	tex;
	t_img	img;
	t_ani	ani;

	mlx = init_mlx();
	img = init_img();
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		error(3);
	tex = init_tex();
	meta->mlx = &mlx;
	meta->img = &img;
	meta->tex = &tex;
	ani = init_ani(meta);
	meta->ani = &ani;
	fill_tex(&tex, meta);
	mlx_mouse_hide();
	game_loop(meta->mlx, meta);
}

int		main(int ac, char **av)
{
	t_meta		meta;
	t_map		map;
	t_data		data;
	t_spr		spr;

	map = init_map();
	data = init_data();
	spr = init_spr();
	input_check(ac, av, &map);
	parse(av[1], &map, &data, &spr);
	meta.map = &map;
	meta.data = &data;
	meta.spr = &spr;
	run(&meta);
}
