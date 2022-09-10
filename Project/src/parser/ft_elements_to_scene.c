/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements_to_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:02:18 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/08 19:04:14 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*ft_get_v_up(t_vec3 look)
{
	t_vec3	*up;

	up = NULL;
	if (look.y == 0)
		up = ft_new_create_vector(0, 1, 0);
	else if (look.y > 0 && look.z == 0)
		up = ft_new_create_vector(0, 0, 1);
	else if (look.y < 0 && look.z == 0)
		up = ft_new_create_vector(0, 0, -1);
	else if (look.y > 0)
		up = ft_new_create_vector(-look.x, look.y, -look.z);
	else if (look.y < 0)
		up = ft_new_create_vector(look.x, -look.y, look.z);
	return (up);
}

void	ft_add_ambient_to_scene(t_mem *mem, char **element)
{
	t_vec3	aux;

	if (mem->max[0] != 0)
		ft_error_parse(mem, ENAMBIENT);
	if (ft_check_numb_args(element) != 3)
		ft_error_parse(mem, EAMBIENT);
	mem->ambient = ft_create_light();
	ft_get_x_double(mem, element[1], &aux);
	ft_set_light_brightness(mem->ambient, aux.x);
	ft_check_intensity_value(mem, aux.x);
	ft_get_xyz_double(mem, element[2], &aux);
	ft_check_color_values(mem, aux);
	ft_set_light_color(mem->ambient, aux.x / 255, aux.y / 255, aux.z / 255);
	mem->max[0] = 1;
}

void	ft_add_camera_to_scene(t_mem *mem, char **element)
{
	t_vec3	aux;

	if (mem->max[1] != 0)
		ft_error_parse(mem, ENCAMERA);
	if (ft_check_numb_args(element) != 4)
		ft_error_parse(mem, ECAMERA);
	mem->cam = ft_create_camera();
	ft_get_xyz_double(mem, element[1], &aux);
	mem->cam->p_eye = ft_new_create_vector(aux.x, aux.y, aux.z);
	ft_get_xyz_double(mem, element[2], &aux);
	ft_check_normal_values(mem, aux);
	mem->cam->p_lookat = ft_new_create_vector(aux.x, aux.y, aux.z);
	mem->cam->v_up = ft_get_v_up(*mem->cam->p_lookat);
	ft_get_x_double(mem, element[3], &aux);
	ft_check_fov_value(mem, aux.x);
	mem->cam->vfov = (M_PI / 180) * aux.x;
	ft_set_ratio(mem->cam);
	mem->cam->axis_w = ft_new_minus_vec(*mem->cam->p_eye, *mem->cam->p_lookat);
	ft_normalize_vector(mem->cam->axis_w);
	mem->cam->axis_u = ft_vector_cross(mem->cam->v_up, mem->cam->axis_w);
	mem->cam->axis_v = ft_vector_cross(mem->cam->axis_w, mem->cam->axis_u);
	ft_set_hori_vert_cam(mem->cam);
	ft_set_low_left(mem->cam);
	mem->max[1] = 1;
}

void	ft_add_light_to_scene(t_mem *mem, char **element)
{
	t_vec3	aux;

	if (mem->max[2] != 0)
		ft_error_parse(mem, ENLIGHT);
	if (ft_check_numb_args(element) != 4)
		ft_error_parse(mem, ELIGHT);
	ft_add_light_to_list(mem->lights);
	ft_get_xyz_double(mem, element[1], &aux);
	ft_set_light_position(mem->lights->last, aux.x, aux.y, aux.z);
	ft_get_x_double(mem, element[2], &aux);
	ft_check_intensity_value(mem, aux.x);
	ft_set_light_brightness(mem->lights->last, aux.x);
	ft_get_xyz_double(mem, element[3], &aux);
	ft_check_color_values(mem, aux);
	ft_set_light_color(mem->lights->last,
		aux.x / 255,
		aux.y / 255,
		aux.z / 255);
	mem->max[2] = 1;
}
