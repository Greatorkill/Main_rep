/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:23 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:50 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_vector	sum_vect(t_vector a, t_vector b)
{
	return (new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector	sub_vect(t_vector a, t_vector b)
{
	return (new_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector	mult_vect(t_vector a, float b)
{
	return (new_vector(a.x * b, a.y * b, a.z * b));
}

float		dot_vect(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
