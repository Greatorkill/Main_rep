/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:13 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:38 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_canvas	*parse_res(char **str)
{
	int width;
	int height;

	if (ft_lensplit(str) != 3)
		error_file("invalid resolution\n");
	width = ft_atoi(str[1]);
	height = ft_atoi(str[2]);
	if (width < 1 || height < 1)
		error_file("invalid resolution\n");
	return (new_canvas(width, height, 1));
}

t_light		*parse_light(char **str)
{
	t_vector	pos;
	float		intense;
	t_color		color;

	if (**str == 'A')
	{
		if (ft_lensplit(str) != 3)
			error_file("invalid light\n");
		pos = new_vector(0, 0, 0);
		intense = ft_atof(str[1]);
		color = parse_color(str[2]);
	}
	else
	{
		if (ft_lensplit(str) != 4)
			error_file("invalid light\n");
		pos = parse_vector(str[1]);
		intense = ft_atof(str[2]);
		color = parse_color(str[3]);
	}
	if (intense < 0 || intense > 1)
		error_file("invalid light\n");
	return (new_light(pos, color, intense));
}

t_camera	*parse_camera(char **str)
{
	t_vector	pos;
	t_vector	rot;
	int			fov;

	if (ft_lensplit(str) != 4)
		error_file("invalid camera\n");
	pos = parse_vector(str[1]);
	rot = parse_vector(str[2]);
	fov = ft_atoi(str[3]);
	if (fov > 180 || fov < 0)
		error_file("invalid camera\n");
	return (new_camera(pos, rot, fov));
}

t_color		parse_color(char *line)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(line);
	while (*line != ',' && *line)
		line++;
	if (!*line || !*(line + 1))
		error_file("invalid color\n");
	line++;
	g = ft_atoi(line);
	while (*line != ',' && *line)
		line++;
	if (!*line || !*(line + 1))
		error_file("invalid color\n");
	line++;
	b = ft_atoi(line);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_file("invalid color\n");
	return (new_color(r, g, b));
}

t_vector	parse_vector(char *line)
{
	float		x;
	float		y;
	float		z;

	x = ft_atof(line);
	while (*line != ',' && *line)
		line++;
	if (!*line || !*(line + 1))
		error_file("invalid vector\n");
	line++;
	y = ft_atof(line);
	while (*line != ',' && *line)
		line++;
	if (!*line || !*(line + 1))
		error_file("invalid vector\n");
	line++;
	z = ft_atof(line);
	return (new_vector(x, y, z));
}
