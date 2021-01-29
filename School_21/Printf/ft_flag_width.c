/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:09 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 19:03:36 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_width(const char *format, t_flags *list, va_list argv,
		int *count)
{
	if (format[*count] == '*')
	{
		list->width = va_arg(argv, int);
		if (list->width < 0)
		{
			list->width *= -1;
			list->minus = 1;
		}
		*count += 1;
		return ;
	}
	list->width = 0;
	while (ft_isdigit(format[*count]))
	{
		list->width *= 10;
		list->width += format[*count] - '0';
		*count += 1;
	}
	if (list->width < 0)
	{
		list->width *= -1;
		list->minus = 1;
	}
}
