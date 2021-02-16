#ifndef MINIRT_H
# define MINIRT_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}			t_vector;

typedef struct s_color
{
	int		R;
	int		G;
	int		B;
}				t_color;

typedef struct s_canvas
{
	int			width;
	int			height;
	int			dist;
}				t_canvas;

typedef struct	s_camera
{
	t_vector	*position;
	t_vector	*rotation;
	char			fov;
}				t_camera;

typedef struct	s_light
{
	t_vector	*position;
	t_color		*color;
	float		intense;
	char		amb_bool;
}				t_light;

typedef struct	s_sphere
{
	t_vector	*position;
	float		diameter;
	t_color		*color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	*position;
	t_vector	*rotation;
	t_color		*color;
}				t_plane;

typedef struct	s_square
{
	t_vector	*position;
	t_vector	*rotation;
	float		size;
	t_color		*color;
}				t_square;

typedef struct	s_cylinder
{
	t_vector	*position;
	t_vector	*rotation;
	float		diameter;
	float		height;
	t_color		*color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_vector	*pos_a;
	t_vector	*pos_b;
	t_vector	*pos_c;
	t_color		*color;
}				t_triangle;

typedef struct		s_lstobj
{
	int				type;
	void			*object;
	void			*prev;
	void			*next;
}					t_lstobj;

typedef struct		s_scene
{
	t_canvas		*viewport;
	t_camera		*camera;
	t_lstobj		*objects;
	t_lstobj		*lights;
	t_color			*background_color;
}					t_scene;

t_vector	*new_vector(float x, float y, float z);
t_color		*new_color(int R, int G, int B);
t_canvas	*new_canvas(int width, int height, int dist);
t_camera	*new_camera(t_vector *pos, t_vector *rot, char fov);
t_light		*new_light(t_vector *pos, t_color *color, float intense, char amb_bool);
t_sphere	*new_sphere(t_vector *pos, float diameter, t_color *color);
t_plane		*new_plane(t_vector *pos, t_vector *rot, t_color *color);
t_square	*new_square(t_vector *pos, t_vector *rot, float size, t_color *color);
t_cylinder	*new_cylinder(t_vector *pos, t_vector *rot, float diameter, float height, t_color *color);
t_triangle	*new_triangle(t_vector *pos_a, t_vector *pos_b, t_vector *pos_c, t_color *color);
void		new_obj(int type, void *object, t_lstobj **list);
void		init_scene(t_scene *scene);

t_vector	*sum_vect(t_vector *a, t_vector *b);
t_vector	*sub_vect(t_vector *a, t_vector *b);
t_vector	*mult_vect(t_vector *a, float b);
float		dot_vect(t_vector *a, t_vector *b);
float		length_vect(t_vector *a);
t_vector	*normalize_vect(t_vector *vect);

#endif
