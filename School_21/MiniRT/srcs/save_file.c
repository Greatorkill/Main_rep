/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:37:20 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/28 16:58:18 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static char	*header_bmp(t_scene scene, unsigned int *size)
{
	char	*data;
	int		i;

	*size = scene.viewport->height * scene.viewport->width * 3;
	if (!(data = malloc(*size + HEADER)))
		return (NULL);
	i = 0;
	while (i < (int)*size + HEADER)
		data[i++] = 0;
	*(unsigned short *)data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(data + 2) = (*size + HEADER);
	*(unsigned int *)(data + 6) = 0u;
	*(unsigned char *)(data + 10) = HEADER;
	*(unsigned int *)(data + 14) = 40;
	*(unsigned int *)(data + 18) = scene.viewport->width;
	*(unsigned int *)(data + 22) = scene.viewport->height;
	*(unsigned short *)(data + 26) = 1;
	*(unsigned short *)(data + 28) = 24;
	*(unsigned int *)(data + 30) = 0;
	*(unsigned int *)(data + 34) = (unsigned int)*size;
	*(unsigned int *)(data + 38) = 3780;
	*(unsigned int *)(data + 42) = 3780;
	*(int *)(data + 46) = 0;
	*(int *)(data + 50) = 0;
	return (data);
}

void		save_bmp_file(t_scene scene)
{
	int				fd;
	unsigned int	size;
	char			*data;
	int				vars[4];

	scene.viewport->width -= scene.viewport->width % 16;
	data = header_bmp(scene, &size);
	vars[0] = HEADER;
	vars[3] = scene.viewport->height;
	while (vars[3]--)
	{
		vars[2] = -1;
		while (++vars[2] < scene.viewport->width)
		{
			vars[1] = (vars[2] * (scene.mlx.bpp / 8)) + (vars[3] *
			scene.mlx.size_line);
			*(data + vars[0]++) = *(scene.mlx.data + vars[1]++);
			*(data + vars[0]++) = *(scene.mlx.data + vars[1]++);
			*(data + vars[0]++) = *(scene.mlx.data + vars[1]);
		}
	}
	if ((fd = open("image.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
		return ;
	write(fd, data, size + HEADER);
	close(fd);
}
