/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_shooter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:44:00 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 20:32:17 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_new_direction(t_camera *cam, t_ray *ray, int i, int j)
{
	t_vec3	tmp;
	t_vec3	tmp_2;
	float	x;
	float	y;

	x = (float)j / WIDTH;
	y = (float)i / HEIGHT;
	*ray->p_ori = ft_copy_vector(*cam->p_eye);
	tmp = ft_double_multi_vec(x, *cam->v_hori);
	tmp_2 = ft_double_multi_vec(y, *cam->v_vert);
	tmp = ft_add_vec(tmp, tmp_2);
	tmp = ft_add_vec(tmp, *cam->p_low_left);
	*ray->v_dir = ft_copy_vector(tmp);
	*ray->v_dir = ft_minus_vec(*ray->v_dir, *cam->p_eye);
	ft_normalize_vector(ray->v_dir);
}
