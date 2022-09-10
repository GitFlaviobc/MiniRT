/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:12:53 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/16 15:15:51 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light_list	*ft_create_light_list(void)
{
	t_light_list	*list;

	list = (t_light_list *)malloc(sizeof(t_light_list));
	list->total = 0;
	list->first = NULL;
	list->last = NULL;
	return (list);
}

void	ft_add_light_to_list(t_light_list *list)
{
	t_light	*light;

	light = ft_create_light();
	if (list->total == 0)
		list->first = light;
	else
	{
		light->next = list->first;
		list->first->prev = light;
		light->prev = list->last;
		list->last->next = light;
	}
	list->last = light;
	list->total++;
}

void	ft_free_light_from_list(t_light_list *list, t_light *light)
{
	if (list->first == light)
	{
		if (list->last == light)
		{
			list->first = NULL;
			list->last = NULL;
		}
		else
		{
			list->first = light->next;
			list->last->next = light->next;
			light->next->prev = list->last;
		}
	}
	else
	{
		if (list->last == light)
			list->last = light->prev;
		light->prev->next = light->next;
		light->next->prev = light->prev;
	}
	list->total--;
	ft_free_light(light);
}

void	ft_free_light_list(t_light_list *list)
{
	while (list->total != 0)
	{
		ft_free_light_from_list(list, list->first);
	}
	free(list);
}
