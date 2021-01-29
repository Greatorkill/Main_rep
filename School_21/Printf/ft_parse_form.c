/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:46 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/18 13:14:00 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_funs(void (*funs[10]) (va_list argv, t_flags *list))
{
	funs[0] = &ft_c;
	funs[1] = &ft_s;
	funs[2] = &ft_p;
	funs[3] = &ft_d;
	funs[4] = &ft_i;
	funs[5] = &ft_u;
	funs[6] = &ft_x;
	funs[7] = &ft_xx;
	funs[8] = &ft_o;
	funs[9] = &ft_pct;
}

static	void	ft_init_struct(t_flags *list)
{
	list->minus = 0;
	list->zero = 0;
	list->width = -1;
	list->accur = -1;
	list->length = 0;
	list->str = NULL;
	list->type = 0;
}

static void		ft_parse_flag(const char *format, t_flags *list, int *count)
{
	while (format[*count] == '-' || format[*count] == '0')
	{
		while (format[*count] == '-')
		{
			list->minus = 1;
			*count += 1;
		}
		while (format[*count] == '0')
		{
			if (list->minus != 1)
				list->zero = 1;
			*count += 1;
		}
	}
}

int				ft_parse_form(const char *format, va_list argv, int *count)
{
	t_flags	list;
	void	(*funs[10]) (va_list argv, t_flags *list);
	int		length;

	length = 0;
	*count += 1;
	ft_init_funs(funs);
	ft_init_struct(&list);
	ft_parse_flag(format, &list, count);
	if (format[*count] == '*' || ft_isdigit(format[*count]))
		ft_flag_width(format, &list, argv, count);
	if (format[*count] == '.')
		ft_flag_accur(format, &list, argv, count);
	if (ft_pf_strchr("cspdiuxXo%", format[*count]) > -1)
	{
		funs[ft_pf_strchr("cspdiuxXo%", format[*count])](argv, &list);
		(&list)->type = format[*count];
	}
	length += ft_apply_flags(&list);
	if ((&list)->str)
		free((&list)->str);
	return (length);
}
