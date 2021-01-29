/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:35 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:19:00 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_o(va_list argv, t_flags *list)
{
	int num;

	num = va_arg(argv, int);
	list->str = ft_itoa_base(num, 8);
	list->length = ft_strlen(list->str);
}
