/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accur_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:37:46 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/17 19:17:50 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_accur_neg_digit(t_flags *list, char *res)
{
	int i;
	int j;

	i = 0;
	j = 0;
	res = malloc(list->accur + 2);
	res[list->accur + 1] = '\0';
	res[0] = '-';
	i++;
	j++;
	while (i < (list->accur - (list->length - 2)))
	{
		res[i] = '0';
		i++;
	}
	while (list->str[j])
	{
		res[i] = list->str[j];
		i++;
		j++;
	}
	list->str = res;
}

static void	ft_accur_pos_digit(t_flags *list, char *res)
{
	int i;
	int j;

	i = 0;
	j = 0;
	res = malloc(list->accur + 1);
	res[list->accur] = '\0';
	while (i < (list->accur - list->length))
	{
		res[i] = '0';
		i++;
	}
	while (list->str[j])
	{
		res[i] = list->str[j];
		i++;
		j++;
	}
	list->str = res;
}

static void	ft_accur_str(t_flags *list, char *res)
{
	int i;
	int j;

	i = 0;
	j = 0;
	res = malloc(list->accur + 1);
	res[list->accur] = '\0';
	while (i < list->accur)
	{
		res[i] = list->str[i];
		i++;
	}
	list->str = res;
	list->length = ft_strlen(list->str);
}

void		ft_accur_apply(t_flags *list)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = NULL;
	if (ft_pf_strchr("diuxX", list->type) > -1)
	{
		if (list->accur == 0 && *(list->str) == '0')
			list->str = ft_strdup("");
		if (*(list->str) == '-' && (list->length - 1) < list->accur)
			ft_accur_neg_digit(list, res);
		else if (list->length < list->accur)
			ft_accur_pos_digit(list, res);
		list->length = ft_strlen(list->str);
	}
	if (list->type == 's' && list->length > list->accur && list->accur != -1)
	{
		ft_accur_str(list, res);
	}
	free(res);
}
