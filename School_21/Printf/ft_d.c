/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:14:47 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:17:47 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d(va_list argv, t_flags *list)
{
	int num;

	num = va_arg(argv, int);
	list->str = ft_itoa(num);
	list->length = ft_strlen(list->str);
}
