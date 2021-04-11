/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:20 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:47 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

float		ft_atof(char *line)
{
	int			i;
	float		res;
	float		sub_zero;
	int			sign;

	i = -1;
	sign = 0;
	res = ft_atoi(line);
	while (line[++i] == '-')
		sign = 1;
	while (ft_is_digit(line[i]))
		i++;
	if (line[i] == '.')
	{
		i++;
		sub_zero = (sign == 1) ? -0.1 : 0.1;
		while (line[i] && ft_is_digit(line[i]))
		{
			res += sub_zero * (line[i++] - '0');
			sub_zero *= 0.1;
		}
	}
	return (res);
}

int			ft_strncmp(const char *s1, const char *s2)
{
	int out;

	out = 0;
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void		pixel_put(t_data *mlx, int x, int y, t_color color)
{
	char	*dst;
	int		tmp_color;

	tmp_color = create_rgb(color);
	dst = mlx->data + (y * mlx->size_line + x * (mlx->bpp / 8));
	if (dst)
		*(unsigned int*)dst = tmp_color;
}

int			ft_lensplit(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}
