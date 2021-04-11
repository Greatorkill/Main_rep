/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:09:27 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:03 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

float	cut_cylinder(float solve[6], float m1, float m2, t_cylinder *cy)
{
	if (solve[4] < solve[5])
	{
		if (m1 >= 0 && m1 <= cy->height && solve[4] >= 0)
			return (solve[4]);
		else if (m2 >= 0 && m2 <= cy->height && solve[5] >= 0)
			return (solve[5]);
	}
	else if (solve[4] > solve[5])
	{
		if (m2 >= 0 && m2 <= cy->height && solve[5] >= 0)
			return (solve[5]);
		else if (m1 >= 0 && m1 <= cy->height && solve[4] >= 0)
			return (solve[4]);
	}
	return (-1);
}

float	hit_cylinder(t_vector ray, t_vector pos, void *cylinder)
{
	float		m1;
	float		m2;
	float		solve[6];
	t_cylinder	*cy;
	t_vector	sub;

	cy = (t_cylinder *)cylinder;
	solve[0] = dot_vect(ray, ray) -
	pow(dot_vect(ray, normalize_vect(cy->rotation)), 2);
	sub = sub_vect(pos, cy->position);
	solve[1] = 2 * (dot_vect(ray, sub) -
	(dot_vect(ray, normalize_vect(cy->rotation)) *
	dot_vect(sub, normalize_vect(cy->rotation))));
	solve[2] = dot_vect(sub, sub) - pow(dot_vect(sub,
	normalize_vect(cy->rotation)), 2) - pow(cy->diameter / 2, 2);
	solve[3] = pow(solve[1], 2) - (4 * solve[0] * solve[2]);
	if (solve[3] < 0)
		return (-1);
	solve[4] = (-solve[1] - sqrt(solve[3])) / (2 * solve[0]);
	solve[5] = (-solve[1] + sqrt(solve[3])) / (2 * solve[0]);
	m1 = (dot_vect(ray, normalize_vect(cy->rotation)) * solve[4]) +
	dot_vect(sub, normalize_vect(cy->rotation));
	m2 = (dot_vect(ray, normalize_vect(cy->rotation)) * solve[5]) +
	dot_vect(sub, normalize_vect(cy->rotation));
	return (cut_cylinder(solve, m1, m2, cy));
}
