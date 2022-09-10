/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:37:31 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/27 13:34:58 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_pick_intersect_type(t_obj *obj, t_ray *ray)
{
	t_funct	function[MAX_OBJ];

	function[SPHERE] = ft_sphere_check;
	function[PLANE] = ft_plane_check;
	function[CYLINDER] = ft_cylinder_check;
	function[obj->type](obj, ray, ray->hit);
}
