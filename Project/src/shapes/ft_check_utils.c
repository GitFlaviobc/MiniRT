/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:34:45 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 13:44:23 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_hit_point(t_ray *ray, t_hit *hit)
{
	*hit->p_hit = ft_double_multi_vec(hit->dist, *ray->v_dir);
	*hit->p_hit = ft_add_vec(*hit->p_hit, *ray->p_ori);
}

int	ft_is_in_front(double last_hit, double root)
{
	if (last_hit == 0)
		return (1);
	if (last_hit > root - EPSILON)
		return (1);
	return (0);
}

void	ft_is_set_hit(t_hit *hit, t_obj *obj, double dist)
{
	hit->mat = obj->mat;
	hit->dist = dist - EPSILON;
	hit->count++;
}

int	ft_check_height_hit(double dist, double height, double root)
{
	if (dist >= 0 && dist <= height && root > EPSILON)
		return (1);
	return (0);
}
