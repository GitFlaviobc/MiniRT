/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:34:56 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 14:00:54 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_create_sphere(t_obj *sphere)
{
	sphere->p_center = ft_new_create_vector(0, 0, 0);
	sphere->radius = 0;
	sphere->mat = ft_make_material();
}

void	ft_create_plane(t_obj *plane)
{
	plane->p_center = ft_new_create_vector(0, 0, 0);
	plane->v_normal = ft_normal_vector(0, 1, 0);
	plane->mat = ft_make_material();
	plane->shad = 0;
}

void	ft_create_cylinder(t_obj *cylinder)
{
	cylinder->p_center = ft_new_create_vector(0, 0, 0);
	cylinder->radius = 0;
	cylinder->v_normal = ft_new_create_vector(0, 0, 0);
	cylinder->mat = ft_make_material();
	cylinder->height = 0;
	cylinder->shad = 0;
}

void	ft_pick_obj(t_obj *obj, int type)
{
	t_funct	function[MAX_OBJ];

	function[SPHERE] = ft_create_sphere;
	function[PLANE] = ft_create_plane;
	function[CYLINDER] = ft_create_cylinder;
	function[type](obj);
}

t_obj	*ft_create_obj(int type)
{
	t_obj	*obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	obj->next = obj;
	obj->prev = obj;
	obj->type = type;
	ft_pick_obj(obj, type);
	return (obj);
}
