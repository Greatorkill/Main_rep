/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:34 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:59:06 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	init_mlx(t_scene *scene)
{
	scene->mlx.bpp = 0;
	scene->mlx.size_line = 0;
	scene->mlx.mlx_ptr = mlx_init();
	scene->mlx.win_ptr = mlx_new_window(scene->mlx.mlx_ptr,
	scene->viewport->width, scene->viewport->height, "MiniRT");
	scene->mlx.mlx_img = mlx_new_image(scene->mlx.mlx_ptr,
	scene->viewport->width, scene->viewport->height);
	scene->mlx.data = mlx_get_data_addr(scene->mlx.mlx_img, &(scene->mlx.bpp),
	&(scene->mlx.size_line), &(scene->mlx.endian));
}

void	hit_init(float (*hit_obj[5]) (t_vector ray, t_vector pos, void *object))
{
	hit_obj[SPHERE] = &hit_sphere;
	hit_obj[PLANE] = &hit_plane;
	hit_obj[SQUARE] = &hit_square;
	hit_obj[CYLINDER] = &hit_cylinder;
	hit_obj[TRIANGLE] = &hit_triangle;
}

void	norm_init(t_vector (*get_norm[5]) (t_vector surf_point,
		t_lstobj *shape, t_color *color, t_vector pos))
{
	get_norm[SPHERE] = &get_sphere_norm;
	get_norm[PLANE] = &get_plane_norm;
	get_norm[SQUARE] = &get_square_norm;
	get_norm[CYLINDER] = &get_cylinder_norm;
	get_norm[TRIANGLE] = &get_triangle_norm;
}

void	init_curr_shape(t_lstobj *curr)
{
	curr->type = 20;
	curr->object = NULL;
	curr->next = NULL;
}

void	init_scene(t_scene *scene)
{
	scene->viewport = NULL;
	scene->ambient = NULL;
	scene->cameras = NULL;
	scene->objects = NULL;
	scene->lights = NULL;
	scene->background_color = new_color(0, 0, 0);
}
