/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:50:53 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 17:58:49 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/mini_rt.h>

int		create_rgb(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

t_color	create_color(int color)
{
	t_color res;

	res.r = color & (0xFF << 16);
	res.g = color & (0xFF << 8);
	res.b = color & 0xFF;
	return (res);
}

t_color	sum_colors(t_color x, t_color y)
{
	int r;
	int g;
	int b;

	r = (x.r + y.r) > 255 ? 255 : (x.r + y.r);
	g = (x.g + y.g) > 255 ? 255 : (x.g + y.g);
	b = (x.b + y.b) > 255 ? 255 : (x.b + y.b);
	r = r < 0 ? 0 : r;
	g = g < 0 ? 0 : g;
	b = b < 0 ? 0 : b;
	return (new_color(r, g, b));
}
