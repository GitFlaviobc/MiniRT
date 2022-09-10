/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:29:55 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 22:35:39 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_hit_normal_sph(t_ray *ray, t_vec3 *center)
{
	*ray->hit->v_normal = ft_minus_vec(*ray->hit->p_hit, *center);
	ft_normalize_vector(ray->hit->v_normal);
}

int	ft_get_roots_sph(t_obj *obj, t_ray *ray, double root[2])
{
	t_vec3	aux;
	double	a;
	double	b;
	double	c;

	aux = ft_minus_vec(*ray->p_ori, *obj->p_center);
	a = ft_vector_dot(*ray->v_dir, *ray->v_dir);
	b = ft_vector_dot(aux, *ray->v_dir);
	c = ft_vector_dot(aux, aux) - (obj->radius * obj->radius);
	root[0] = (b * b) - (a * c);
	if (root[0] < 0)
		return (0);
	root[1] = (-b + (sqrt(root[0]))) / a;
	root[0] = (-b - (sqrt(root[0]))) / a;
	return (1);
}

void	ft_sphere_check(t_obj *sphere, t_ray *ray, t_hit *hit)
{
	double	dist[2];

	if (!ft_get_roots_sph(sphere, ray, dist))
		return ;
	if (dist[0] >= 0 && ft_is_in_front(hit->dist, dist[0]))
	{
		ft_is_set_hit(hit, sphere, dist[0]);
		ft_get_hit_point(ray, hit);
		ft_get_hit_normal_sph(ray, sphere->p_center);
		return ;
	}
	if (dist[1] >= 0 && ft_is_in_front(hit->dist, dist[1]))
	{
		ft_is_set_hit(hit, sphere, dist[1]);
		ft_get_hit_point(ray, hit);
		ft_get_hit_normal_sph(ray, sphere->p_center);
	}
}
