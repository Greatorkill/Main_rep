/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:53 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:22:29 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		length;
	int		count;

	count = 0;
	length = 0;
	va_start(argv, format);
	while (format[count])
	{
		if (format[count] != '%')
		{
			ft_putchar_fd(format[count], 1);
			length++;
		}
		else
			length += ft_parse_form(format, argv, &count);
		count++;
	}
	va_end(argv);
	return (length);
}
