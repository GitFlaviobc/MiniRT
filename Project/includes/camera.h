/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:19 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/22 19:42:06 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vec3	*p_eye;
	t_vec3	*p_lookat;
	t_vec3	*p_low_left;
	t_vec3	*axis_u;
	t_vec3	*axis_v;
	t_vec3	*axis_w;
	t_vec3	*v_up;
	t_vec3	*v_hori;
	t_vec3	*v_vert;
	double	vfov;
	double	aspect_ratio;
}	t_camera;

t_camera	*ft_create_camera(void);	
void		ft_free_camera(t_camera *cam);
void		ft_set_ratio(t_camera *cam);
void		ft_set_hori_vert_cam(t_camera *cam);
void		ft_set_low_left(t_camera *cam);

#endif