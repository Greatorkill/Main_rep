/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:16:19 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:28:44 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x(va_list argv, t_flags *list)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = va_arg(argv, int);
	list->str = ft_itoa_base(num, 16);
	while (list->str[i])
	{
		if (list->str[i] > 64)
			list->str[i] += 32;
		i++;
	}
	list->length = ft_strlen(list->str);
}
