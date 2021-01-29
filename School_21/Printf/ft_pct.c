/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:50 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:24:09 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pct(va_list argv, t_flags *list)
{
	va_list ght;

	va_copy(ght, argv);
	list->str = malloc(2);
	list->str[0] = '%';
	list->str[1] = '\0';
	list->length = 1;
}
