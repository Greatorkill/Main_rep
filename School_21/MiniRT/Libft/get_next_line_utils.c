/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:44:06 by kgeorgia          #+#    #+#             */
/*   Updated: 2020/11/26 18:48:38 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	size_t		out;

	out = 0;
	if (s == NULL)
		return (out);
	while (*s)
	{
		out++;
		s++;
	}
	return (out);
}

void			ft_empty_str(char *s, size_t n)
{
	while (n != 0 && *s != 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}

char			*ft_new_str(size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	if (size < 1 || !(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[0] = '\0';
	str[size] = '\0';
	return (str);
}

int				end_line(char *buff)
{
	int			len;

	len = 0;
	while (buff[len] != '\0' && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
	{
		buff[len] = '\0';
		return (len);
	}
	return (-1);
}

char			*ft_strdup(const char *s1)
{
	char		*out;
	size_t		len;
	int			i;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	out = (char *)malloc(len);
	if (out == NULL)
		return (NULL);
	while (len--)
		if (s1[i] != '\0')
		{
			out[i] = s1[i];
			i++;
		}
	out[i] = '\0';
	return (out);
}
