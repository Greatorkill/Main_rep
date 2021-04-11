/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:59 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/04/01 13:08:20 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int		exit_program(void)
{
	exit(0);
	return (0);
}

int		key_proc(int key, t_scene *scene)
{
	if (key == 53)
		exit_program();
	if (key == 49 && scene->cameras && scene->cameras->next)
		scene->cameras = scene->cameras->next;
	render(scene);
	mlx_clear_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr);
	mlx_put_image_to_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
scene->mlx.mlx_img, 0, 0);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

int		error_file(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(-1);
	return (0);
}
