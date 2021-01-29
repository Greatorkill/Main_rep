/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:53:37 by kgeorgia          #+#    #+#             */
/*   Updated: 2020/11/09 14:30:36 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	len;
	int		i;

	i = 0;
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
