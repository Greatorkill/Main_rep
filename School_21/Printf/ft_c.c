/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:14:43 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:18:26 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(va_list argv, t_flags *list)
{
	list->str = malloc(2);
	list->str[0] = va_arg(argv, int);
	list->str[1] = '\0';
	list->length = 1;
}
