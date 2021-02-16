#include "../includes/MiniRT.h"

t_vector *new_vector(float x, float y, float z)
{
	t_vector *out;

	out = malloc(sizeof(t_vector));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_color *new_color(int R, int G, int B)
{
	t_color *out;

	out = malloc(sizeof(t_color));
	out->R = R;
	out->G = G;
	out->B = B;
	return (out);
}

t_canvas *new_canvas(int width, int height, int dist)
{
	t_canvas *out;

	out = malloc(sizeof(t_canvas));
	out->width = width;
	out->height = height;
	out->dist = dist;
	return (out);
}

t_camera *new_camera(t_vector *pos, t_vector *rot, char fov)
{
	t_camera *out;

	out = malloc(sizeof(t_camera));
	out->position = pos;
	out->rotation = rot;
	out->fov = fov;
	return (out);
}

t_light *new_light(t_vector *pos, t_color *color, float intense, char amb_bool)
{
	t_light *out;

	out = malloc(sizeof(t_light));
	out->position = pos;
	out->color = color;
	out->intense = intense;
	out->amb_bool = amb_bool;
	return (out);
}

t_sphere *new_sphere(t_vector *pos, float diameter, t_color *color)
{
	t_sphere *out;

	out = malloc(sizeof(t_sphere));
	out->position = pos;
	out->diameter = diameter;
	out->color = color;
	return (out);
}

t_plane *new_plane(t_vector *pos, t_vector *rot, t_color *color)
{
	t_plane *out;

	out = malloc(sizeof(t_plane));
	out->position = pos;
	out->rotation = rot;
	out->color = color;
	return (out);
}

t_square *new_square(t_vector *pos, t_vector *rot, float size, t_color *color)
{
	t_square *out;

	out = malloc(sizeof(t_square));
	out->position = pos;
	out->rotation = rot;
	out->size = size;
	out->color = color;
	return (out);
}

t_cylinder *new_cylinder(t_vector *pos, t_vector *rot, float diameter, float height, t_color *color)
{
	t_cylinder *out;

	out = malloc(sizeof(t_cylinder));
	out->position = pos;
	out->rotation = rot;
	out->diameter = diameter;
	out->height = height;
	out->color = color;
	return (out);
}

t_triangle *new_triangle(t_vector *pos_a, t_vector *pos_b, t_vector *pos_c, t_color *color)
{
	t_triangle *out;

	out = malloc(sizeof(t_triangle));
	out->pos_a = pos_a;
	out->pos_b = pos_b;
	out->pos_c = pos_c;
	out->color = color;
	return (out);
}

void new_obj(int type, void *object, t_lstobj **list)
{
	t_lstobj *new;
	t_lstobj *begin;

	begin = *list;
	while (begin)
		begin = begin->next;
	new = malloc(sizeof(t_lstobj));
	new->type = type;
	new->object = object;
	new->next = NULL;
	begin = new;
}

void init_scene(t_scene *scene)
{
	scene->viewport = NULL;
	scene->camera = NULL;
	scene->objects = NULL;
	scene->lights = NULL;
	scene->background_color = NULL;
}
