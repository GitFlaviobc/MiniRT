/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:30:19 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 13:44:20 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_hit_normal_cy(t_ray *ray, t_obj *cylinder, double dist)
{
	t_vec3	aux;

	aux = ft_double_multi_vec(dist, *cylinder->v_normal);
	aux = ft_add_vec(aux, *cylinder->p_center);
	*ray->hit->v_normal = ft_copy_vector(*ray->hit->p_hit);
	*ray->hit->v_normal = ft_minus_vec(*ray->hit->v_normal, aux);
	ft_normalize_vector(ray->hit->v_normal);
}

void	ft_get_distances(t_obj *cy, t_ray *ray, double roots[2], double dist[2])
{
	t_vec3	aux;
	t_vec3	v_root_0;
	t_vec3	v_root_1;

	aux = ft_minus_vec(*cy->p_center, *ray->p_ori);
	v_root_0 = ft_double_multi_vec(roots[0], *ray->v_dir);
	v_root_0 = ft_minus_vec(v_root_0, aux);
	v_root_1 = ft_double_multi_vec(roots[1], *ray->v_dir);
	v_root_1 = ft_minus_vec(v_root_1, aux);
	dist[0] = ft_vector_dot(*cy->v_normal, v_root_0);
	dist[1] = ft_vector_dot(*cy->v_normal, v_root_1);
}

int	ft_get_roots_cy(t_obj *cy, t_ray *ray, double root[2], double dist[2])
{
	double	a;
	double	b;
	double	c;
	t_vec3	v;
	t_vec3	u;

	v = ft_double_multi_vec(ft_vector_dot(*ray->v_dir, *cy->v_normal),
			*cy->v_normal);
	v = ft_minus_vec(*ray->v_dir, v);
	u = ft_minus_vec(*ray->p_ori, *cy->p_center);
	u = ft_double_multi_vec(ft_vector_dot(u, *cy->v_normal), *cy->v_normal);
	u = ft_minus_vec(ft_minus_vec(*ray->p_ori, *cy->p_center), u);
	a = ft_vector_dot(v, v);
	b = ft_vector_dot(v, u);
	c = ft_vector_dot(u, u) - (cy->radius * cy->radius);
	root[0] = (b * b) - (a * c);
	if (root[0] < 0)
		return (0);
	root[1] = (-b + (sqrt(root[0]))) / a;
	root[0] = (-b - (sqrt(root[0]))) / a;
	ft_get_distances(cy, ray, root, dist);
	return (1);
}

void	ft_set_cy_hit_normal(t_ray *ray, t_obj *cy, double root, double dist)
{
	ft_is_set_hit(ray->hit, cy, root);
	ft_get_hit_point(ray, ray->hit);
	ft_get_hit_normal_cy(ray, cy, dist);
}

void	ft_cylinder_check(t_obj *cylinder, t_ray *ray, t_hit *hit)
{
	double	roots[2];
	double	dist[2];
	int		height[2];

	if (!ft_get_roots_cy(cylinder, ray, roots, dist))
		return ;
	height[0] = ft_check_height_hit(dist[0], cylinder->height / 2, roots[0]);
	height[1] = ft_check_height_hit(dist[1], cylinder->height / 2, roots[1]);
	if (height[0] && height[1])
	{
		if (roots[0] < roots[1] && ft_is_in_front(hit->dist, roots[0]))
			ft_set_cy_hit_normal(ray, cylinder, roots[0], dist[0]);
		else if (ft_is_in_front(hit->dist, roots[1]))
		{
			ft_set_cy_hit_normal(ray, cylinder, roots[1], dist[1]);
			*ray->hit->v_normal = ft_double_multi_vec(-1, *ray->hit->v_normal);
		}
	}
	else if (height[0] && ft_is_in_front(hit->dist, roots[0]))
		ft_set_cy_hit_normal(ray, cylinder, roots[0], dist[0]);
	else if (height[1] && ft_is_in_front(hit->dist, roots[1]))
	{
		ft_set_cy_hit_normal(ray, cylinder, roots[1], dist[1]);
		*ray->hit->v_normal = ft_double_multi_vec(-1, *ray->hit->v_normal);
	}
}
