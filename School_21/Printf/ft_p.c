/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:42 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 18:21:12 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p(va_list argv, t_flags *list)
{
	char			*nbr;
	unsigned long	num;
	int				i;

	i = 0;
	num = va_arg(argv, unsigned long);
	nbr = ft_itoa_base(num, 16);
	list->str = malloc(ft_strlen(nbr) + 3);
	list->str[0] = '0';
	list->str[1] = 'x';
	while (nbr[i])
	{
		if (nbr[i] > 64)
			list->str[i + 2] = nbr[i] + 32;
		else
			list->str[i + 2] = nbr[i];
		i++;
	}
	list->str[i + 2] = '\0';
	list->length = ft_strlen(list->str);
}
