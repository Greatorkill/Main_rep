/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:09 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/30 15:48:52 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int			parse_str(t_scene *scene, char *line)
{
	char **str;

	str = ft_split(line, ' ');
	if (!ft_strncmp(*str, "R") && !scene->viewport)
		scene->viewport = parse_res(str);
	else if (!ft_strncmp(*str, "A") && !scene->ambient)
		scene->ambient = parse_light(str);
	else if (!ft_strncmp(*str, "c"))
		add_back(CAMERA, parse_camera(str), &(scene->cameras));
	else if (!ft_strncmp(*str, "l"))
		add_back(6, parse_light(str), &(scene->lights));
	else if (!ft_strncmp(*str, "sp"))
		add_back(SPHERE, parse_sphere(str), &(scene->objects));
	else if (!ft_strncmp(*str, "pl"))
		add_back(PLANE, parse_plane(str), &(scene->objects));
	else if (!ft_strncmp(*str, "sq"))
		add_back(SQUARE, parse_square(str), &(scene->objects));
	else if (!ft_strncmp(*str, "cy"))
		add_back(CYLINDER, parse_cylinder(str), &(scene->objects));
	else if (!ft_strncmp(*str, "tr"))
		add_back(TRIANGLE, parse_triangle(str), &(scene->objects));
	else if (ft_strncmp(*str, "#"))
		return (free_split(str, 1));
	return (free_split(str, 0));
}

void		set_scene(t_scene *scene)
{
	int			res_x;
	int			res_y;
	t_lstobj	*cam;

	if (!scene->viewport)
		error_file("invalid scene\n");
	mlx_get_screen_size(scene->mlx.mlx_ptr, &res_x, &res_y);
	if (scene->viewport->width > res_x)
		scene->viewport->width = res_x;
	if (scene->viewport->height > res_y)
		scene->viewport->height = res_y;
	cam = scene->cameras;
	if (cam)
	{
		while (cam->next)
			cam = cam->next;
		cam->next = scene->cameras;
	}
}

void		parcing(int fd, t_scene *scene)
{
	char		*line;

	while (get_next_line(fd, &line))
	{
		if (line && ft_strlen(line))
			if (!parse_str(scene, line))
			{
				close(fd);
				error_file("invalid file\n");
			}
		if (!line)
			error_file("invalid file\n");
		free(line);
	}
	parse_str(scene, line);
	free(line);
	set_scene(scene);
	close(fd);
}

void		check_input(int argc, char **argv, int *fd)
{
	int i;

	i = 0;
	if (argc < 2 || argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save")))
		error_file("bad input\n");
	while (argv[1][i])
		i++;
	if (i < 4)
		error_file("bad input\n");
	if (argv[1][i - 1] != 't' || argv[1][i - 2] != 'r' || argv[1][i - 3] != '.')
		error_file("invalid input\n");
	if ((*fd = open(argv[1], O_RDONLY)) < 0)
		error_file("invalid file\n");
}

int			main(int argc, char **argv)
{
	t_scene	scene;
	int		fd;

	check_input(argc, argv, &fd);
	init_scene(&scene);
	parcing(fd, &scene);
	init_mlx(&scene);
	render(&scene);
	if (argc == 2)
	{
		mlx_put_image_to_window(scene.mlx.mlx_ptr, scene.mlx.win_ptr,
		scene.mlx.mlx_img, 0, 0);
		mlx_hook(scene.mlx.win_ptr, 2, 0, key_proc, &scene);
		mlx_hook(scene.mlx.win_ptr, 17, 1L << 17, exit_program, 0);
		mlx_loop(scene.mlx.mlx_ptr);
	}
	else if (argc == 3 && scene.mlx.data)
		save_bmp_file(scene);
	return (0);
}
