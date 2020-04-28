/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 06:41:35 by abobas        #+#    #+#                 */
/*   Updated: 2020/01/19 02:08:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_longcheck(unsigned long a, int b)
{
	int	c;

	if (a > 2147483647 && a < 9223372036854775807)
	{
		c = -2147483648 - (2147483647 - a + 1);
		return (c);
	}
	if (a > 9223372036854775807)
	{
		c = (b == -1) ? 0 : -1;
		return (c);
	}
	c = (b == -1) ? a * -1 : a;
	return (c);
}

int			ft_atoi(char *str)
{
	unsigned long	a;
	int				b;
	int				c;

	a = 0;
	b = 1;
	c = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		b = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	c = ft_longcheck(a, b);
	return (c);
}

int			ft_digitcount(unsigned long a, int base)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / base;
		i++;
	}
	return (i);
}
