/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:16:15 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:23:50 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u(va_list argv, t_flags *list)
{
	unsigned int num;

	num = va_arg(argv, int);
	list->str = ft_itoa_base(num, 10);
	list->length = ft_strlen(list->str);
}
