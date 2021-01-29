/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:14:34 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/17 19:15:31 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus_tr(char *res, int len, t_flags *list, char c)
{
	int i;

	i = 0;
	if (list->type == 'c' && *(list->str) == 0)
	{
		res[i] = 0;
		i++;
	}
	else
		while (list->str[i])
		{
			res[i] = list->str[i];
			i++;
		}
	while (i < len)
	{
		res[i] = c;
		i++;
	}
}

static void	ft_di_type(char *res, int *len, t_flags *list, int *i)
{
	res[0] = '-';
	*i = ft_strlen(list->str) - 1;
	while (*i > 0)
	{
		res[*len - 1] = list->str[*i];
		*i -= 1;
		*len -= 1;
	}
	while (*len > 1)
	{
		res[*len - 1] = '0';
		*len -= 1;
	}
}

static void	ft_else_condition(char *res, int *len, t_flags *list, int *i)
{
	*i = ft_strlen(list->str) - 1;
	while (*i > -1)
	{
		res[*len - 1] = list->str[*i];
		*i -= 1;
		*len -= 1;
	}
}

static void	ft_minus_fl(char *res, int len, t_flags *list, char c)
{
	int i;

	i = 0;
	if (ft_pf_strchr("di", list->type) > -1)
		if (c == '0' && *(list->str) == '-')
		{
			ft_di_type(res, &len, list, &i);
			return ;
		}
	if (list->type == 'c' && *(list->str) == 0)
	{
		i = 0;
		res[len - 1] = 0;
		len--;
	}
	else
		ft_else_condition(res, &len, list, &i);
	while (len)
	{
		res[len - 1] = c;
		len--;
	}
}

int			ft_apply_flags(t_flags *list)
{
	int		len;
	char	*res;
	char	c;

	res = NULL;
	len = 0;
	c = ' ';
	if (list->str != NULL)
	{
		ft_accur_apply(list);
		len = list->length;
		if (list->width > list->length)
			len = list->width;
		if (list->zero && (list->accur == -1) && !list->minus)
			c = '0';
		res = malloc(len + 1);
		res[len] = '\0';
		if (list->minus)
			ft_minus_tr(res, len, list, c);
		else
			ft_minus_fl(res, len, list, c);
	}
	ft_putstr_pf(res, len);
	free(res);
	return (len);
}
