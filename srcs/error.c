/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 04:04:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/02 02:10:50 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	error(int error)
{
	ft_putstr("Error.\n");
	if (error == 0)
		ft_putstr("Invalid argument.\n");
	if (error == 1)
		ft_putstr("Invalid map provided.\n");
	if (error == 3)
		ft_putstr("MLX functionality has failed.\n");
	if (error == 4)
		ft_putstr("Memory allocation has failed.\n");
	if (error == 5)
		ft_putstr("Reading has failed.\n");
	if (error == 6)
		ft_putstr("Opening file has failed.\n");
	if (error == 7)
		ft_putstr("Writing has failed.\n");
	ft_putstr("Terminating program.\n");
	exit(0);
}
