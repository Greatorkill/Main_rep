/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:16:22 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 19:04:01 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xx(va_list argv, t_flags *list)
{
	unsigned int num;

	num = va_arg(argv, int);
	list->str = ft_itoa_base(num, 16);
	list->length = ft_strlen(list->str);
}
