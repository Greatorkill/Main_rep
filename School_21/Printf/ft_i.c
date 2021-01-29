/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:14 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:18:45 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_i(va_list argv, t_flags *list)
{
	int num;

	num = va_arg(argv, int);
	list->str = ft_itoa(num);
	list->length = ft_strlen(list->str);
}
