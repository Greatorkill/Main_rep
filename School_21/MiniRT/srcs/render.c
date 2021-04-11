/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:37:27 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/28 16:47:57 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_vector	trace(t_scene *scene, int i, int j)
{
	t_vector	res;
	t_vector	wuv[3];
	float		norm_x;
	float		norm_y;
	float		aspect;

	wuv[0] = normalize_vect(mult_vect(((t_camera *)
	(scene->cameras->object))->rotation, -1));
	wuv[1] = normalize_vect(mult_vect(cross_vect(normalize_vect(
	new_vector(0, -1, 0)), wuv[0]), -1));
	wuv[2] = normalize_vect(mult_vect(cross_vect(wuv[0], wuv[1]), -1));
	norm_x = (j / (float)scene->viewport->width) - 0.5;
	norm_y = 0.5 - (i / (float)scene->viewport->height);
	aspect = (float)scene->viewport->width / (float)scene->viewport->height;
	aspect > 1 ? norm_x *= aspect : 0;
	aspect < 1 ? norm_y /= aspect : 0;
	norm_x *= tan((((t_camera *)(scene->cameras->object))->fov / 2) *
	M_PI / 180);
	norm_y *= tan((((t_camera *)(scene->cameras->object))->fov / 2) *
	M_PI / 180);
	res = sum_vect(mult_vect(wuv[1], norm_x), mult_vect(wuv[2], norm_y));
	res = sub_vect(res, wuv[0]);
	res = normalize_vect(res);
	return (res);
}

t_vector	intersect(t_vector ray, t_scene *scene, t_lstobj **curr_obj)
{
	t_vector	res;
	float		hit_dist;
	float		min_dist;
	t_lstobj	*shape;
	float		(*hit_shape[5]) (t_vector ray, t_vector pos, void *object);

	hit_init(hit_shape);
	shape = scene->objects;
	if ((min_dist = hit_shape[shape->type](ray, ((t_camera *)
	(scene->cameras->object))->position, shape->object)) > 0)
		*curr_obj = shape;
	while (shape->next)
	{
		shape = shape->next;
		hit_dist = hit_shape[shape->type](ray, ((t_camera *)
		(scene->cameras->object))->position, shape->object);
		if ((hit_dist < min_dist || min_dist < 0) && hit_dist > 0)
		{
			min_dist = hit_dist;
			*curr_obj = shape;
		}
	}
	res = mult_vect(ray, min_dist);
	return (res);
}

void		render(t_scene *scene)
{
	t_color		color;
	t_vector	ray;
	t_lstobj	*curr_shape;
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++i < scene->viewport->height)
	{
		while (++j < scene->viewport->width)
		{
			curr_shape = NULL;
			color = scene->background_color;
			if (scene->cameras && scene->objects)
			{
				ray = trace(scene, i, j);
				ray = intersect(ray, scene, &curr_shape);
				color = apply_light(sum_vect(ray, ((t_camera *)
				scene->cameras->object)->position), scene, curr_shape);
			}
			pixel_put(&scene->mlx, j, i, color);
		}
		j = -1;
	}
}
