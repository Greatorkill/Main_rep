/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:02:23 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/03/24 18:08:49 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_lstobj	*new_obj(int type, void *object)
{
	t_lstobj *obj;

	if (!(obj = malloc(sizeof(t_lstobj))))
		return (NULL);
	obj->type = type;
	obj->object = object;
	obj->next = NULL;
	return (obj);
}

void		add_back(int type, void *object, t_lstobj **list)
{
	t_lstobj *begin;

	if (!object)
		return ;
	begin = *list;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new_obj(type, object);
	}
	else
		*list = new_obj(type, object);
}

int			free_split(char **str, int err)
{
	int	i;

	i = 0;
	while (NULL != str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	if (err)
		return (0);
	return (1);
}
