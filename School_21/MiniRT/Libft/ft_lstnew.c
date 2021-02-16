/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:47:45 by kgeorgia          #+#    #+#             */
/*   Updated: 2020/11/09 14:38:03 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_ls;

	if (!(new_ls = malloc(sizeof(t_list))))
		return (NULL);
	new_ls->content = content;
	new_ls->next = NULL;
	return (new_ls);
}
