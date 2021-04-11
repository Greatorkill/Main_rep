/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:59:29 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/30 14:49:48 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

float	hit_sphere(t_vector ray, t_vector pos, void *sphere)
{
	t_vector	sub;
	t_solver	vars;
	t_sphere	*sp;

	sp = (t_sphere *)sphere;
	sub = sub_vect(pos, sp->position);
	vars.a = dot_vect(ray, ray);
	vars.b = 2 * dot_vect(ray, sub);
	vars.c = dot_vect(sub, sub) - pow(sp->diameter / 2, 2);
	vars.disc = pow(vars.b, 2) - (4 * vars.a * vars.c);
	if (vars.disc < 0)
		return (-1);
	vars.disc = sqrt(vars.disc);
	vars.a = 2 * vars.a;
	vars.x1 = (-vars.b - vars.disc) / vars.a;
	vars.x2 = (-vars.b + vars.disc) / vars.a;
	if (vars.x1 >= 0 && vars.x1 < vars.x2)
		return (vars.x1);
	if (vars.x2 >= 0 && vars.x2 < vars.x1)
		return (vars.x2);
	return (-1);
}

float	hit_plane(t_vector ray, t_vector pos, void *plane)
{
	float	a;
	float	b;
	float	t1;
	t_plane	*pl;

	pl = (t_plane *)plane;
	a = dot_vect(sub_vect(pos, pl->position), normalize_vect(pl->rotation));
	b = dot_vect(ray, normalize_vect(pl->rotation));
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t1 = -a / b;
	if (t1 < 0)
		return (-1);
	return (t1);
}

float	hit_square(t_vector ray, t_vector pos, void *square)
{
	t_vector	d;
	float		solve[4];
	t_square	*sq;

	sq = (t_square *)square;
	solve[0] = dot_vect(sub_vect(pos, sq->position),
	normalize_vect(sq->rotation));
	solve[1] = dot_vect(ray, normalize_vect(sq->rotation));
	if (solve[1] == 0 || (solve[0] < 0 && solve[1] < 0) || (solve[0] > 0
	&& solve[1] > 0))
		return (-1);
	solve[2] = -solve[0] / solve[1];
	d = sub_vect(sum_vect(mult_vect(ray, solve[2]), pos), sq->position);
	solve[3] = sq->size / 2;
	if (fabs(d.x) > solve[3] || fabs(d.y) > solve[3] || fabs(d.z) > solve[3])
		return (-1);
	if (solve[2] > 0)
		return (solve[2]);
	return (-1);
}

float	hit_triangle(t_vector ray, t_vector pos, void *triangle)
{
	t_vector	vecs[4];
	t_solver	vars;
	t_triangle	*tr;

	tr = (t_triangle *)triangle;
	vecs[0] = sub_vect(tr->pos_b, tr->pos_a);
	vecs[1] = sub_vect(tr->pos_c, tr->pos_a);
	vecs[3] = cross_vect(ray, vecs[1]);
	vars.disc = dot_vect(vecs[0], vecs[3]);
	if (fabs(vars.disc) < 0.00001)
		return (-1);
	vars.c = 1 / vars.disc;
	vecs[2] = sub_vect(pos, tr->pos_a);
	vars.a = dot_vect(vecs[2], vecs[3]) * vars.c;
	if (vars.a < 0 || vars.a > 1)
		return (-1);
	vecs[2] = cross_vect(vecs[2], vecs[0]);
	vars.b = dot_vect(ray, vecs[2]) * vars.c;
	if (vars.b < 0 || vars.a + vars.b > 1)
		return (-1);
	if ((vars.x1 = dot_vect(vecs[1], vecs[2]) * vars.c) > 0)
		return (vars.x1);
	return (-1);
}
