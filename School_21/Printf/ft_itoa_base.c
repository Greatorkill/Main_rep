/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:28 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 19:08:59 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_null_str(void)
{
	char *res;

	if (!(res = malloc(2)))
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static int	ft_lennum(unsigned long num, int base)
{
	int len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned long num, int base)
{
	char	*res;
	int		len;

	len = 0;
	if (num == 0)
		return (res = ft_null_str());
	len += ft_lennum(num, base);
	if ((res = malloc(len + 1)) == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	while (num)
	{
		if ((num % base) > 9)
			res[len] = (num % base) + 55;
		else
			res[len] = (num % base) + '0';
		num /= base;
		len--;
	}
	return (res);
}
