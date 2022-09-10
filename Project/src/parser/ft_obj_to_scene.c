/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_to_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:42:16 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/05 13:24:08 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_add_sphere_to_scene(t_mem *mem, char **element)
{
	t_vec3	aux;

	if (ft_check_numb_args(element) != 4)
		ft_error_parse(mem, ESPHERE);
	ft_add_obj_to_list(SPHERE, mem->objs);
	ft_get_xyz_double(mem, element[1], &aux);
	ft_obj_set_center(mem->objs->last, aux.x, aux.y, aux.z);
	ft_get_x_double(mem, element[2], &aux);
	ft_obj_set_radius(mem->objs->last, aux.x / 2);
	ft_get_xyz_double(mem, element[3], &aux);
	ft_check_color_values(mem, aux);
	ft_set_material_color(mem->objs->last->mat,
		aux.x / 255,
		aux.y / 255,
		aux.z / 255);
}

void	ft_add_plane_to_scene(t_mem *mem, char **element)
{
	t_vec3	aux;

	if (ft_check_numb_args(element) != 4)
		ft_error_parse(mem, EPLANE);
	ft_add_obj_to_list(PLANE, mem->objs);
	ft_get_xyz_double(mem, element[1], &aux);
	ft_obj_set_center(mem->objs->last, aux.x, aux.y, aux.z);
	ft_get_xyz_double(mem, element[2], &aux);
	ft_check_normal_values(mem, aux);
	ft_obj_set_normal(mem->objs->last, aux.x, aux.y, aux.z);
	ft_get_xyz_double(mem, element[3], &aux);
	ft_check_color_values(mem, aux);
	ft_set_material_color(mem->objs->last->mat,
		aux.x / 255,
		aux.y / 255,
		aux.z / 255);
}

void	ft_add_cylinder_to_scene(t_mem *mem, char **element)
{
	t_vec3	aux;

	if (ft_check_numb_args(element) != 6)
		ft_error_parse(mem, ECYLINDER);
	ft_add_obj_to_list(CYLINDER, mem->objs);
	ft_get_xyz_double(mem, element[1], &aux);
	ft_obj_set_center(mem->objs->last, aux.x, aux.y, aux.z);
	ft_get_xyz_double(mem, element[2], &aux);
	ft_check_normal_values(mem, aux);
	ft_obj_set_normal(mem->objs->last, aux.x, aux.y, aux.z);
	ft_get_x_double(mem, element[3], &aux);
	ft_obj_set_radius(mem->objs->last, aux.x / 2);
	ft_get_x_double(mem, element[4], &aux);
	ft_obj_set_height(mem->objs->last, aux.x);
	ft_get_xyz_double(mem, element[5], &aux);
	ft_check_color_values(mem, aux);
	ft_set_material_color(mem->objs->last->mat,
		aux.x / 255,
		aux.y / 255,
		aux.z / 255);
}
