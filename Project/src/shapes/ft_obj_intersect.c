/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:54:36 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/15 18:57:58 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_intersec(t_mem *mem, t_ray *ray, t_color *color)
{
	t_obj	*obj;
	int		total;
	int		hit;

	obj = mem->objs->first;
	total = 0;
	hit = 0;
	while (total < mem->objs->total)
	{
		ft_pick_intersect_type(obj, ray);
		if (ray->hit->count > hit)
		{
			ft_color_ambient_light(mem, obj, color);
			hit++;
		}
		obj = obj->next;
		total++;
	}
}
