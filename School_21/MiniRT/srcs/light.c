/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:26:21 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/30 14:47:37 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_color		set_ambient(t_color color, t_light *light)
{
	t_color	res;
	float	k_r;
	float	k_g;
	float	k_b;

	k_r = 0;
	k_g = 0;
	k_b = 0;
	if (light)
	{
		k_r = ((float)light->color.r * light->intense) / 255;
		k_g = ((float)light->color.g * light->intense) / 255;
		k_b = ((float)light->color.b * light->intense) / 255;
	}
	res = new_color(color.r * k_r, color.g * k_g, color.b * k_b);
	return (res);
}

t_color		set_diffuse(t_color color, t_light *light, float norm)
{
	t_color	res;
	float	k_r;
	float	k_g;
	float	k_b;
	float	tmp_norm;

	tmp_norm = norm < 0 ? 0 : norm;
	k_r = ((float)light->color.r * light->intense) / 255;
	k_g = ((float)light->color.g * light->intense) / 255;
	k_b = ((float)light->color.b * light->intense) / 255;
	res = new_color(color.r * k_r * tmp_norm,
	color.g * k_g * tmp_norm, color.b * k_b * tmp_norm);
	return (res);
}

float		light_intersect(t_vector ray, t_vector point, t_scene *scene)
{
	float		hit_dist;
	float		min_dist;
	t_lstobj	*shape;
	float		(*hit_shape[5]) (t_vector ray, t_vector pos, void *object);

	hit_init(hit_shape);
	shape = scene->objects;
	min_dist = hit_shape[shape->type](ray, sum_vect(point,
	mult_vect(ray, 0.0001)), shape->object);
	while (shape->next)
	{
		shape = shape->next;
		hit_dist = hit_shape[shape->type](ray, sum_vect(point,
		mult_vect(ray, 0.0001)), shape->object);
		if ((hit_dist < min_dist || min_dist < 0) && hit_dist > 0)
			min_dist = hit_dist;
	}
	return (min_dist);
}

void		apply_light_2(t_vector ray, t_scene *scene, t_light_var *vars)
{
	while (vars->list)
	{
		vars->light_ray = normalize_vect(sub_vect(
		((t_light *)vars->list->object)->position, ray));
		vars->dist_light_int = light_intersect(vars->light_ray, ray, scene);
		if (vars->dist_light_int < 0 || (vars->dist_light_int) > length_vect(
		sub_vect(((t_light *)vars->list->object)->position, ray)))
		{
			vars->light_vect = dot_vect(vars->norm_shape, normalize_vect(
			sub_vect(((t_light *)(vars->list->object))->position, ray)));
			vars->tmp_color = sum_colors(vars->tmp_color,
			set_diffuse(vars->color, (t_light *)(vars->list->object),
			vars->light_vect));
		}
		vars->list = vars->list->next;
	}
}

t_color		apply_light(t_vector ray, t_scene *scene, t_lstobj *curr_shape)
{
	t_light_var		vars;
	t_vector		(*get_norm[5]) (t_vector, t_lstobj *, t_color *, t_vector);

	vars.list = scene->lights;
	vars.color = scene->background_color;
	if (curr_shape == NULL)
		return (vars.color);
	norm_init(get_norm);
	vars.norm_shape = get_norm[curr_shape->type](ray, curr_shape,
	&vars.color, ((t_camera *)(scene->cameras->object))->position);
	vars.tmp_color = set_ambient(vars.color, scene->ambient);
	apply_light_2(ray, scene, &vars);
	vars.color = vars.tmp_color;
	return (vars.color);
}
