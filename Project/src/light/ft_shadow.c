/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:48:20 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:44:11 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_shadow(t_mem *mem, t_ray *ray)
{
	int		total;
	t_obj	*obj;

	obj = mem->objs->first;
	total = 0;
	while (total < mem->objs->total)
	{
		if (obj->type == CYLINDER)
			obj->shad = 1;
		ft_pick_intersect_type(obj, ray);
		if (obj->type == CYLINDER)
			obj->shad = 0;
		obj = obj->next;
		total++;
	}
}

double	ft_point_dist(t_vec3 *point_a, t_vec3 *point_b)
{
	double	dist;

	dist = (point_a->x - point_b->x) * (point_a->x - point_b->x);
	dist += (point_a->y - point_b->y) * (point_a->y - point_b->y);
	dist += (point_a->z - point_b->z) * (point_a->z - point_b->z);
	dist = sqrt(dist);
	return (dist);
}

int	ft_in_shadow(t_vec3 *p_light, t_vec3 *p_hit, t_mem *mem)
{
	t_ray	*shadow;
	t_vec3	aux;
	double	len;
	int		ret;

	shadow = ft_create_ray();
	ft_set_ray_ori(shadow, p_hit);
	aux = ft_copy_vector(*mem->ray->hit->v_normal);
	aux = ft_double_multi_vec(EPSILON, aux);
	*shadow->p_ori = ft_add_vec(*shadow->p_ori, aux);
	*shadow->v_dir = ft_copy_vector(*p_light);
	*shadow->v_dir = ft_minus_vec(*shadow->v_dir, *shadow->p_ori);
	ft_normalize_vector(shadow->v_dir);
	ft_check_shadow(mem, shadow);
	len = ft_point_dist(p_light, p_hit);
	ret = 0;
	if (shadow->hit->count > 0)
	{
		if (shadow->hit->dist < len)
			ret = 1;
	}
	ft_free_ray(shadow);
	return (ret);
}
