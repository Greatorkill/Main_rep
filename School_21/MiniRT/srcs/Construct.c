/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:50:57 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:58:53 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_vector	new_vector(float x, float y, float z)
{
	t_vector out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_color		new_color(int r, int g, int b)
{
	t_color out;

	out.r = r;
	out.g = g;
	out.b = b;
	return (out);
}

t_canvas	*new_canvas(int width, int height, int dist)
{
	t_canvas *out;

	out = malloc(sizeof(t_canvas));
	out->width = width;
	out->height = height;
	out->dist = dist;
	return (out);
}

t_camera	*new_camera(t_vector pos, t_vector rot, int fov)
{
	t_camera *out;

	out = malloc(sizeof(t_camera));
	out->position = pos;
	out->rotation = rot;
	out->fov = fov;
	return (out);
}

t_light		*new_light(t_vector pos, t_color color, float intense)
{
	t_light *out;

	out = malloc(sizeof(t_light));
	out->position = pos;
	out->color = color;
	out->intense = intense;
	return (out);
}
