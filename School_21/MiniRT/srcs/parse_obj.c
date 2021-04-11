/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:16 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:40 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_sphere	*parse_sphere(char **str)
{
	t_vector	pos;
	float		diameter;
	t_color		color;

	if (ft_lensplit(str) != 4)
		error_file("invalid sphere\n");
	pos = parse_vector(str[1]);
	diameter = ft_atof(str[2]);
	color = parse_color(str[3]);
	return (new_sphere(pos, diameter, color));
}

t_plane		*parse_plane(char **str)
{
	t_vector	pos;
	t_vector	rot;
	t_color		color;

	if (ft_lensplit(str) != 4)
		error_file("invalid plane\n");
	pos = parse_vector(str[1]);
	rot = parse_vector(str[2]);
	color = parse_color(str[3]);
	return (new_plane(pos, rot, color));
}

t_square	*parse_square(char **str)
{
	t_vector	pos;
	t_vector	rot;
	float		size;
	t_color		color;

	if (ft_lensplit(str) != 5)
		error_file("invalid square\n");
	pos = parse_vector(str[1]);
	rot = parse_vector(str[2]);
	size = ft_atof(str[3]);
	color = parse_color(str[4]);
	return (new_square(pos, rot, size, color));
}

t_cylinder	*parse_cylinder(char **str)
{
	t_vector	pos;
	t_vector	rot;
	float		size[2];
	t_color		color;

	if (ft_lensplit(str) != 6)
		error_file("invalid cylinder\n");
	pos = parse_vector(str[1]);
	rot = parse_vector(str[2]);
	size[0] = ft_atof(str[3]);
	size[1] = ft_atof(str[4]);
	color = parse_color(str[5]);
	return (new_cylinder(pos, rot, size, color));
}

t_triangle	*parse_triangle(char **str)
{
	t_vector	a;
	t_vector	b;
	t_vector	c;
	t_color		color;

	if (ft_lensplit(str) != 5)
		error_file("invalid triangle\n");
	a = parse_vector(str[1]);
	b = parse_vector(str[2]);
	c = parse_vector(str[3]);
	color = parse_color(str[4]);
	return (new_triangle(a, b, c, color));
}
