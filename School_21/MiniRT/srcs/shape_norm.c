/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:05:09 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/28 18:43:10 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_vector	get_sphere_norm(t_vector surf_point, t_lstobj *shape,
			t_color *color, t_vector pos)
{
	t_sphere *sp;

	sp = (t_sphere *)shape->object;
	*color = sp->color;
	(void)pos;
	return (normalize_vect(sub_vect(surf_point, sp->position)));
}

t_vector	get_plane_norm(t_vector surf_point, t_lstobj *shape,
			t_color *color, t_vector pos)
{
	t_plane		*pl;
	t_vector	norm;

	pl = (t_plane *)shape->object;
	(void)surf_point;
	*color = pl->color;
	norm = normalize_vect(pl->rotation);
	if (dot_vect(norm, normalize_vect(sub_vect(surf_point, pos))) < 0)
		return (normalize_vect(pl->rotation));
	return (normalize_vect(mult_vect(pl->rotation, -1)));
}

t_vector	get_square_norm(t_vector surf_point, t_lstobj *shape,
			t_color *color, t_vector pos)
{
	t_square *sq;
	t_vector norm;

	sq = (t_square *)shape->object;
	*color = sq->color;
	(void)surf_point;
	norm = normalize_vect(sq->rotation);
	if (dot_vect(norm, normalize_vect(sub_vect(surf_point, pos))) < 0)
		return (normalize_vect(sq->rotation));
	return (normalize_vect(mult_vect(sq->rotation, -1)));
}

t_vector	get_cylinder_norm(t_vector surf_point, t_lstobj *shape,
			t_color *color, t_vector pos)
{
	float		m;
	float		len_ray;
	t_cylinder	*cy;
	t_vector	ray;
	t_vector	norm;

	len_ray = length_vect(sub_vect(pos, surf_point));
	ray = normalize_vect(sub_vect(surf_point, pos));
	cy = (t_cylinder *)shape->object;
	*color = cy->color;
	m = (dot_vect(ray, normalize_vect(cy->rotation)) * len_ray) +
	dot_vect(sub_vect(pos, cy->position), normalize_vect(cy->rotation));
	norm = normalize_vect(sub_vect(sub_vect(surf_point, cy->position),
	mult_vect(normalize_vect(cy->rotation), m)));
	if (dot_vect(ray, norm) < 0)
		return (norm);
	return (mult_vect(norm, -1));
}

t_vector	get_triangle_norm(t_vector surf_point, t_lstobj *shape,
			t_color *color, t_vector pos)
{
	t_triangle	*tr;
	t_vector	ab_vec;
	t_vector	bc_vec;
	t_vector	norm;

	tr = (t_triangle *)shape->object;
	*color = tr->color;
	(void)surf_point;
	ab_vec = sub_vect(tr->pos_a, tr->pos_b);
	bc_vec = sub_vect(tr->pos_b, tr->pos_c);
	norm = normalize_vect(cross_vect(ab_vec, bc_vec));
	if (dot_vect(norm, normalize_vect(sub_vect(surf_point, pos))) < 0)
		return (norm);
	return (mult_vect(norm, -1));
}
