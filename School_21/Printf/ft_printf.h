/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:15:57 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/01/16 19:37:23 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		accur;
	int		length;
	char	*str;
	char	type;
}				t_flags;

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_pf(char *s, int len);
int				ft_pf_strchr(const char *s, int c);
char			*ft_itoa(int n);
char			*ft_itoa_base(unsigned long num, int base);
char			*ft_strdup(const char *s1);

int				ft_printf(const char *format, ...);
int				ft_parse_form(const char *format, va_list argv, int *count);
int				ft_apply_flags(t_flags *list);
void			ft_accur_apply(t_flags *list);

void			ft_flag_width(const char *format, t_flags *list, va_list argv,
				int *count);
void			ft_flag_accur(const char *format, t_flags *list, va_list argv,
				int *count);

void			ft_c(va_list argv, t_flags *list);
void			ft_s(va_list argv, t_flags *list);
void			ft_p(va_list argv, t_flags *list);
void			ft_d(va_list argv, t_flags *list);
void			ft_i(va_list argv, t_flags *list);
void			ft_u(va_list argv, t_flags *list);
void			ft_x(va_list argv, t_flags *list);
void			ft_xx(va_list argv, t_flags *list);
void			ft_o(va_list argv, t_flags *list);
void			ft_pct(va_list argv, t_flags *list);

#endif
