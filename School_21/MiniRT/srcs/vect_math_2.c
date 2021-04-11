/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_math_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:04:41 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:48 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

float		length_vect(t_vector a)
{
	return (sqrt(dot_vect(a, a)));
}

t_vector	normalize_vect(t_vector vect)
{
	float len;

	len = length_vect(vect);
	return (new_vector(vect.x / len, vect.y / len, vect.z / len));
}

t_vector	cross_vect(t_vector a, t_vector b)
{
	float x;
	float y;
	float z;

	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;
	return (new_vector(x, y, z));
}
