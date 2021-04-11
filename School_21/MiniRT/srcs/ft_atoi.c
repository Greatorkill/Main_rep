/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:05:15 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:58:55 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int			ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_space_num(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
	{
		i++;
	}
	return (i);
}

static int	ft_znak(const char *str, int *znak, int i)
{
	int j;

	j = i;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			*znak *= -1;
		j++;
	}
	return (j);
}

int			ft_atoi(char *line)
{
	unsigned long long	out;
	int					znak;
	int					i;

	znak = 1;
	out = 0;
	i = ft_space_num(line);
	i = ft_znak(line, &znak, i);
	while (line[i] >= '0' && line[i] <= '9')
	{
		out *= 10;
		out += line[i] - '0';
		i++;
	}
	if (out > 9223372036854775807)
	{
		if (znak > 0)
			return (-1);
		return (0);
	}
	return (out * znak);
}
