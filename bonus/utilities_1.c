/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 03:01:38 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/01 23:21:39 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	int		i;

	i = ft_strlen(s);
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_fill(char *origin, char *append, char *dest)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (origin[i] != '\0')
	{
		dest[i] = origin[i];
		i++;
	}
	while (append[y] != '\0')
	{
		dest[i] = append[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *origin, char *append)
{
	int		x;
	char	*dest;

	x = ft_strlen(origin) + ft_strlen(append);
	dest = (char*)malloc(sizeof(char) * (x + 1));
	if (!dest)
	{
		free(append);
		free(origin);
		return (0);
	}
	dest = ft_fill(origin, append, dest);
	free(append);
	free(origin);
	return (dest);
}

void	ft_putstr(char *str)
{
	int		n;

	n = 0;
	n = write(1, str, ft_strlen(str));
	if (n < 0)
		error(7);
}
