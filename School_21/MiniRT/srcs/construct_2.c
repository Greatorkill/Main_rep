/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:02:20 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:58:51 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_sphere	*new_sphere(t_vector pos, float diameter, t_color color)
{
	t_sphere *out;

	out = malloc(sizeof(t_sphere));
	out->position = pos;
	out->diameter = diameter;
	out->color = color;
	return (out);
}

t_plane		*new_plane(t_vector pos, t_vector rot, t_color color)
{
	t_plane *out;

	out = malloc(sizeof(t_plane));
	out->position = pos;
	out->rotation = rot;
	out->color = color;
	return (out);
}

t_square	*new_square(t_vector pos, t_vector rot, float size, t_color color)
{
	t_square *out;

	out = malloc(sizeof(t_square));
	out->position = pos;
	out->rotation = rot;
	out->size = size;
	out->color = color;
	return (out);
}

t_cylinder	*new_cylinder(t_vector pos, t_vector rot, float size[2],
			t_color color)
{
	t_cylinder *out;

	out = malloc(sizeof(t_cylinder));
	out->position = pos;
	out->rotation = rot;
	out->diameter = size[0];
	out->height = size[1];
	out->color = color;
	return (out);
}

t_triangle	*new_triangle(t_vector pos_a, t_vector pos_b, t_vector pos_c,
			t_color color)
{
	t_triangle *out;

	out = malloc(sizeof(t_triangle));
	out->pos_a = pos_a;
	out->pos_b = pos_b;
	out->pos_c = pos_c;
	out->color = color;
	return (out);
}
