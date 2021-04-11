/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:42:56 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/30 15:49:30 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdio.h>

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../minilibx_mms/mlx.h"

# define SPHERE 0
# define PLANE 1
# define SQUARE 2
# define CYLINDER 3
# define TRIANGLE 4
# define CAMERA 5

# define HEADER 54

typedef struct	s_solver
{
	float		a;
	float		b;
	float		c;
	float		disc;
	float		x1;
	float		x2;
}				t_solver;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_data;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_canvas
{
	int			width;
	int			height;
	int			dist;
}				t_canvas;

typedef struct	s_camera
{
	t_vector	position;
	t_vector	rotation;
	int			fov;
}				t_camera;

typedef struct	s_light
{
	t_vector	position;
	t_color		color;
	float		intense;
}				t_light;

typedef struct	s_sphere
{
	t_vector	position;
	float		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	position;
	t_vector	rotation;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	t_vector	position;
	t_vector	rotation;
	float		size;
	t_color		color;
}				t_square;

typedef struct	s_cylinder
{
	t_vector	position;
	t_vector	rotation;
	float		diameter;
	float		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_vector	pos_a;
	t_vector	pos_b;
	t_vector	pos_c;
	t_color		color;
}				t_triangle;

typedef struct	s_lstobj
{
	int			type;
	void		*object;
	void		*next;
}				t_lstobj;

typedef struct	s_light_var
{
	t_vector	norm_shape;
	t_color		color;
	t_color		tmp_color;
	t_lstobj	*list;
	float		light_vect;
	float		dist_light_int;
	t_vector	light_ray;
}				t_light_var;

typedef struct	s_scene
{
	t_data		mlx;
	t_canvas	*viewport;
	t_light		*ambient;
	t_lstobj	*cameras;
	t_lstobj	*objects;
	t_lstobj	*lights;
	t_color		background_color;
}				t_scene;

/*
** Color math
*/

int				create_rgb(t_color color);
t_color			create_color(int color);
t_color			sum_colors(t_color x, t_color y);

/*
** Constructors
*/

t_sphere		*new_sphere(t_vector pos, float diameter, t_color color);
t_plane			*new_plane(t_vector pos, t_vector rot, t_color color);
t_square		*new_square(t_vector pos, t_vector rot, float size,
				t_color color);
t_cylinder		*new_cylinder(t_vector pos, t_vector rot, float size[2],
				t_color color);
t_triangle		*new_triangle(t_vector pos_a, t_vector pos_b, t_vector pos_c,
				t_color color);
t_vector		new_vector(float x, float y, float z);
t_color			new_color(int r, int g, int b);
t_canvas		*new_canvas(int width, int height, int dist);
t_camera		*new_camera(t_vector pos, t_vector rot, int fov);
t_light			*new_light(t_vector pos, t_color color, float intense);

/*
** Ft_atoi
*/

int				ft_is_digit(char c);
int				ft_atoi(char *line);

/*
** Ft_split
*/

char			**ft_split(char const *s, char c);

/*
** Hit objects
*/

float			cut_cylinder(float solve[6], float m1, float m2,
				t_cylinder *cy);
float			hit_cylinder(t_vector ray, t_vector pos, void *cylinder);
float			hit_sphere(t_vector ray, t_vector pos, void *sphere);
float			hit_plane(t_vector ray, t_vector pos, void *plane);
float			hit_square(t_vector ray, t_vector pos, void *square);
float			hit_triangle(t_vector ray, t_vector pos, void *triangle);

/*
** Init functions
*/

void			init_mlx(t_scene *scene);
void			hit_init(float (*hit_obj[5]) (t_vector ray, t_vector pos,
				void *object));
void			norm_init(t_vector (*get_norm[5]) (t_vector surf_point,
				t_lstobj *shape, t_color *color, t_vector pos));
void			init_curr_shape(t_lstobj *curr);
void			init_scene(t_scene *scene);

/*
** Key processing
*/

int				exit_program(void);
int				key_proc(int key, t_scene *scene);
void			ft_putstr_fd(char *s, int fd);
int				error_file(char *str);

/*
** Light functions
*/

t_color			set_ambient(t_color color, t_light *light);
t_color			set_diffuse(t_color color, t_light *light, float norm);
float			light_intersect(t_vector ray, t_vector point, t_scene *scene);
void			apply_light_2(t_vector ray, t_scene *scene, t_light_var *vars);
t_color			apply_light(t_vector ray, t_scene *scene, t_lstobj *curr_shape);

/*
** List functions
*/

t_lstobj		*new_obj(int type, void *object);
void			add_back(int type, void *object, t_lstobj **list);
int				free_split(char **str, int err);

/*
** mini_RT functions
*/

int				parse_str(t_scene *scene, char *line);
void			set_scene(t_scene *scene);
void			parcing(int fd, t_scene *scene);
void			check_input(int argc, char **argv, int *fd);

/*
** Parsing objects
*/

t_canvas		*parse_res(char **str);
t_light			*parse_light(char **str);
t_camera		*parse_camera(char **str);
t_color			parse_color(char *line);
t_vector		parse_vector(char *line);

/*
** Parsing shapes
*/

t_sphere		*parse_sphere(char **str);
t_plane			*parse_plane(char **str);
t_square		*parse_square(char **str);
t_cylinder		*parse_cylinder(char **str);
t_triangle		*parse_triangle(char **str);

/*
** Render functions
*/

t_vector		trace(t_scene *scene, int i, int j);
t_vector		intersect(t_vector ray, t_scene *scene, t_lstobj **curr_obj);
void			render(t_scene *scene);

/*
** Save bmp format
*/

void			save_bmp_file(t_scene scene);

/*
** Shape normal
*/

t_vector		get_sphere_norm(t_vector surf_point, t_lstobj *shape,
				t_color *color, t_vector pos);
t_vector		get_plane_norm(t_vector surf_point, t_lstobj *shape,
				t_color *color, t_vector pos);
t_vector		get_square_norm(t_vector surf_point, t_lstobj *shape,
				t_color *color, t_vector pos);
t_vector		get_cylinder_norm(t_vector surf_point, t_lstobj *shape,
				t_color *color, t_vector pos);
t_vector		get_triangle_norm(t_vector surf_point, t_lstobj *shape,
				t_color *color, t_vector pos);

/*
** Utils
*/

float			ft_atof(char *line);
int				ft_strncmp(const char *s1, const char *s2);
void			pixel_put(t_data *mlx, int x, int y, t_color color);
int				ft_lensplit(char **str);

/*
** Vector math
*/

float			length_vect(t_vector a);
t_vector		normalize_vect(t_vector vect);
t_vector		cross_vect(t_vector a, t_vector b);
t_vector		sum_vect(t_vector a, t_vector b);
t_vector		sub_vect(t_vector a, t_vector b);
t_vector		mult_vect(t_vector a, float b);
float			dot_vect(t_vector a, t_vector b);

#endif
