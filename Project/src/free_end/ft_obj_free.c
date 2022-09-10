/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:11:00 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/21 20:24:15 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_sphere(t_obj *sphere)
{
	free(sphere->p_center);
	ft_free_material(sphere->mat);
	free(sphere);
}

void	ft_free_plane(t_obj *plane)
{
	free(plane->p_center);
	free(plane->v_normal);
	ft_free_material(plane->mat);
	free(plane);
}

void	ft_free_cylinder(t_obj *cylinder)
{
	free(cylinder->p_center);
	free(cylinder->v_normal);
	ft_free_material(cylinder->mat);
	free(cylinder);
}

void	ft_free_obj_by_type(t_obj *obj)
{
	t_funct	function[MAX_OBJ];

	function[SPHERE] = ft_free_sphere;
	function[PLANE] = ft_free_plane;
	function[CYLINDER] = ft_free_cylinder;
	function[obj->type](obj);
}
