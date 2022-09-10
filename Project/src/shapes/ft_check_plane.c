/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:30:08 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:22:40 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_hit_normal_plane(t_ray *ray, t_vec3 *center)
{
	*ray->hit->v_normal = ft_minus_vec(*ray->hit->v_normal, *center);
	ft_normalize_vector(ray->hit->v_normal);
}

void	ft_plane_check(t_obj *plane, t_ray *ray, t_hit *hit)
{
	t_vec3	aux;
	double	checker;
	double	dist;

	checker = ft_vector_dot(*ray->v_dir, *plane->v_normal);
	if (fabs(checker) < EPSILON)
		return ;
	aux = ft_minus_vec(*plane->p_center, *ray->p_ori);
	dist = ft_vector_dot(aux, *plane->v_normal) / checker;
	if (dist > EPSILON && ft_is_in_front(hit->dist, dist))
	{
		ft_is_set_hit(hit, plane, dist);
		ft_get_hit_point(ray, hit);
		*ray->hit->v_normal = ft_copy_vector(*plane->v_normal);
	}
}
