/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:16:07 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/18 13:37:10 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s(va_list argv, t_flags *list)
{
	char *res;

	res = va_arg(argv, char*);
	if (res != NULL)
	{
		list->str = ft_strdup(res);
	}
	else
		list->str = ft_strdup("(null)");
	list->length = ft_strlen(list->str);
}
