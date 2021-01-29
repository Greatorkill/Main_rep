/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_accur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:14:50 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 19:03:25 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_accur(const char *format, t_flags *list, va_list argv,
		int *count)
{
	*count += 1;
	if (format[*count] == '*')
	{
		list->accur = va_arg(argv, int);
		if (list->accur < 0)
			list->accur = -1;
		*count += 1;
		return ;
	}
	list->accur = 0;
	while (ft_isdigit(format[*count]))
	{
		list->accur *= 10;
		list->accur += format[*count] - '0';
		*count += 1;
	}
	if (list->accur < 0)
		list->accur = -1;
}
