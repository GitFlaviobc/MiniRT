/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:05:05 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/22 19:40:58 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_obj_set_center(t_obj *obj, double x, double y, double z)
{
	obj->p_center->x = x;
	obj->p_center->y = y;
	obj->p_center->z = z;
}

void	ft_obj_set_radius(t_obj *obj, double radius)
{
	obj->radius = radius;
}

void	ft_obj_set_normal(t_obj *obj, double x, double y, double z)
{
	obj->v_normal->x = x;
	obj->v_normal->y = y;
	obj->v_normal->z = z;
	ft_normalize_vector(obj->v_normal);
}

void	ft_obj_set_height(t_obj *obj, double height)
{
	obj->height = height;
}
