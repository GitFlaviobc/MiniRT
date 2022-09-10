/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:19:24 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 14:08:34 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_set_low_left(t_camera *cam)
{
	t_vec3	tmp;

	tmp = ft_double_divide_vec(2, *cam->v_hori);
	cam->p_low_left = ft_new_minus_vec(*cam->p_eye, tmp);
	tmp = ft_double_divide_vec(2, *cam->v_vert);
	*cam->p_low_left = ft_minus_vec(*cam->p_low_left, tmp);
	*cam->p_low_left = ft_minus_vec(*cam->p_low_left, *cam->axis_w);
}

void	ft_set_hori_vert_cam(t_camera *cam)
{
	double	view_h;
	double	view_w;

	view_h = 2 * tan(cam->vfov / 2);
	view_w = view_h * cam->aspect_ratio;
	cam->v_vert = ft_new_double_multi_vec(view_w, *cam->axis_v);
	cam->v_hori = ft_new_double_multi_vec(view_h, *cam->axis_u);
}

void	ft_set_ratio(t_camera *cam)
{
	cam->aspect_ratio = (double)HEIGHT / WIDTH;
}

t_camera	*ft_create_camera(void)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->p_eye = NULL;
	cam->p_lookat = NULL;
	cam->p_low_left = NULL;
	cam->axis_u = NULL;
	cam->axis_v = NULL;
	cam->axis_w = NULL;
	cam->v_up = NULL;
	cam->v_hori = NULL;
	cam->v_vert = NULL;
	cam->vfov = 0;
	cam->aspect_ratio = 0;
	return (cam);
}

void	ft_free_camera(t_camera *cam)
{
	if (!cam->p_eye)
		return ;
	free(cam->p_eye);
	if (!cam->p_lookat)
		return ;
	free(cam->p_lookat);
	free(cam->p_low_left);
	free(cam->axis_u);
	free(cam->axis_v);
	free(cam->axis_w);
	free(cam->v_up);
	free(cam->v_hori);
	free(cam->v_vert);
	free(cam);
}
