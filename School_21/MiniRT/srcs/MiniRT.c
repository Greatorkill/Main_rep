#include "../includes/MiniRT.h"

int		create_trgb(t_color *color)
{
	return(color->R << 16 | color->G << 8 | color->B);
}

void            pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

t_vector *ray_calc(int x, int y, int res_x, int res_y)
{
	float  norm_x;
	float  norm_y;
	float norm_z;
	t_vector *out;

	norm_x = (x / (float)res_x) - 0.5;
	norm_y = (y / (float)res_y) - 0.5;
	norm_z = 10;
	out = new_vector(norm_x, norm_y, norm_z);
	out = normalize_vect(out);
	return (out);
}

t_color *pixel_color(t_vector *ray, t_sphere *object)
{
	float		a;
	float		b;
	float		c;
	float		det;
	t_vector    *oc;
	oc = new_vector(0 - object->position->x, 0 - object->position->y, 0 - object->position->z);
	a = dot_vect(ray, ray);
	b = 2.0 * dot_vect(ray, oc);
	c = dot_vect(oc, oc) - pow(object->diameter / 2, 2);
	det = pow(b, 2) - (4 * a * c);
	if (det < 0)
	{
		return (new_color(0, 0, 0));
	}
	return (object->color);
}

int             main(int argc, char **argv)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
	int res_x;
	int res_y;
	t_camera *camera;
	t_canvas *canvas;
	t_sphere *sphere;
	t_color *pixel;
	int i;
	int j;

	i = argc;
	(void)argv;
	i = 0;
	j = 0;
	res_x = 720;
	res_y = 720;
	camera = new_camera(new_vector(0,0,0), new_vector(0,0,0), 70);
	canvas = new_canvas(res_x, res_y, 10);
	sphere = new_sphere(new_vector(0, 0, 100), 5, new_color(0, 100, 100));
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, res_x, res_y, "MiniRT");
    img.img = mlx_new_image(mlx, res_x, res_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	while (i < res_y)
	{
		while (j < res_x)
		{
			pixel = pixel_color(ray_calc(i, j, res_x, res_y), sphere);
			pixel_put(&img, i, j, create_trgb(pixel));
			j++;
		}
		j = 0;
		i++;
	}
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
