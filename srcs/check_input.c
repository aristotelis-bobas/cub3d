/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 01:17:39 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/01 23:00:57 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_av_2(char *av)
{
	if (av[0] != '-' || av[1] != '-')
		return (1);
	if (av[2] != 's')
		return (1);
	if (av[3] != 'a')
		return (1);
	if (av[4] != 'v')
		return (1);
	if (av[5] != 'e')
		return (1);
	if (av[6] != '\0')
		return (1);
	return (0);
}

int		check_av_1(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (av[i - 1] != 'b')
		return (1);
	if (av[i - 2] != 'u')
		return (1);
	if (av[i - 3] != 'c')
		return (1);
	if (av[i - 4] != '.')
		return (1);
	return (0);
}

void	input_check(int ac, char **av, t_map *map)
{
	if (ac == 1)
		error(0);
	if (ac > 3)
		error(0);
	if (check_av_1(av[1]))
		error(0);
	if (ac == 3)
	{
		if (check_av_2(av[2]))
			error(0);
		else
			map->screenshot = 1;
	}
}
