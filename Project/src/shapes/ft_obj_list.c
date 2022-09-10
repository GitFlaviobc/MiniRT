/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:57:15 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/21 20:27:23 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj_list	*ft_create_obj_list(void)
{
	t_obj_list	*list;

	list = (t_obj_list *)malloc(sizeof(t_obj_list));
	list->total = 0;
	list->first = NULL;
	list->last = NULL;
	return (list);
}

void	ft_add_obj_to_list(int type, t_obj_list *list)
{
	t_obj	*obj;

	obj = ft_create_obj(type);
	if (list->total == 0)
		list->first = obj;
	else
	{
		obj->next = list->first;
		list->first->prev = obj;
		obj->prev = list->last;
		list->last->next = obj;
	}
	list->last = obj;
	list->total++;
	obj->id = list->total;
}

void	ft_free_obj_list(t_obj_list *list)
{
	while (list->total != 0)
	{
		ft_free_obj(list, list->first);
	}
	free(list);
}

void	ft_free_obj(t_obj_list *list, t_obj *obj)
{
	if (list->first == obj)
	{
		if (list->last == obj)
		{
			list->first = NULL;
			list->last = NULL;
		}
		else
		{
			list->first = obj->next;
			list->last->next = obj->next;
			obj->next->prev = list->last;
		}
	}
	else
	{
		if (list->last == obj)
			list->last = obj->prev;
		obj->prev->next = obj->next;
		obj->next->prev = obj->prev;
	}
	list->total--;
	ft_free_obj_by_type(obj);
}
